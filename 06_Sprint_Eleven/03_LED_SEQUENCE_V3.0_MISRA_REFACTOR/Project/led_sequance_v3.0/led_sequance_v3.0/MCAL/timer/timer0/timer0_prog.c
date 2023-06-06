/*
 * timers_prog.c
 *
 * Created: 05/06/2023 18:32:05
 *  Author: 20101
 */ 

#include "timer0_interface.h"


static void(*ptr_func_overflow_isr)(void) = PTR_NULL;
static void(*ptr_func_ctc_isr)(void) = PTR_NULL;

Uint32_t g_u32_number_of_ovf;

Uint32_t g_u64_polling_counter = 0;
Uint32_t g_u32_isr_ovf_counter = 0;

static enu_timer0_system_state timer0_set_ovf_isr(void(*ptr_func_isr_callback)(void))
{
	  enu_timer0_system_state ret;
	  
	  if( PTR_NULL == ptr_func_isr_callback)
	  {
		  ret = TIMER0_SYSTEM_STATE_SET_OVERFLOW_ISR_NOK;
	  }
	  else
	  {
		  ptr_func_overflow_isr = ptr_func_isr_callback;
		  ret  = TIMER0_SYSTEM_STATE_SET_OVERFLOW_ISR_OK;
	  }
	  return ret;
}

static enu_timer0_system_state timer0_set_ctc_isr(void(*ptr_func_isr_callback)(void))
{
		  enu_timer0_system_state ret;
		  
		  if( PTR_NULL == ptr_func_isr_callback)
		  {
			  ret = TIMER0_SYSTEM_STATE_SET_CTC_ISR_NOK;
		  }
		  else
		  {
			  ptr_func_ctc_isr = ptr_func_isr_callback;
			  ret  = TIMER0_SYSTEM_STATE_SET_CTC_ISR_OK;
		  }
		  return ret;
}



enu_timer0_system_state TIMER0_init(const str_timer0_init_config_t *str_timer0_cfg)
{	
	enu_timer0_system_state ret;
	
	if(PTR_NULL == str_timer0_cfg)
	{
		ret = TIMER0_SYSTEM_STATE_NULL_POINTER;
	}
	else
	{
		switch(str_timer0_cfg->enu_timer0_mode)
		{
			case TIMER0_NORMAL_MODE:
			{
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_WGM01_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_WGM00_BIT);
				ret = TIMER0_SYSTEM_STATE_MODE_OK;
				break;
			}
			case TIMER0_PWM_PHASE_CORRECT_MODE :
			{
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_WGM01_BIT);
				SET_BIT(TCCR0_REG   , TCCR0_REG_WGM00_BIT);
				ret = TIMER0_SYSTEM_STATE_MODE_OK;
				break;
			}			
			case TIMER0_CTC_MODE :
			{
				SET_BIT(TCCR0_REG   , TCCR0_REG_WGM01_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_WGM00_BIT);
				ret = TIMER0_SYSTEM_STATE_MODE_OK;
				break;				
			}
			case TIMER0_PWM_FAST_MODE :
			{
				SET_BIT(TCCR0_REG , TCCR0_REG_WGM01_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_WGM00_BIT);
				ret = TIMER0_SYSTEM_STATE_MODE_OK;
				break;
			}
			default :
			{
				ret = TIMER0_SYSTEM_STATE_MODE_NOK;
			}
		}
		if(TIMER0_SYSTEM_STATE_MODE_OK == ret)
		{
			switch(str_timer0_cfg->enu_timer0_oc0_output_mode)
			{
				case TIMER0_OC0_DISCONNECTED :
				{
					CLEAR_BIT(TCCR0_REG , TCCR0_REG_COM01_BIT);
					CLEAR_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}
				case TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH :
				{
					CLEAR_BIT(TCCR0_REG , TCCR0_REG_COM01_BIT);
					SET_BIT(TCCR0_REG   , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}
				case TIMER0_OC0_CLEAR_ON_COMPARE_MATCH :
				{
					SET_BIT(TCCR0_REG   , TCCR0_REG_COM01_BIT);
					CLEAR_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}
				case TIMER0_OC0_SET_ON_COMPARE_MATCH :
				{
					SET_BIT(TCCR0_REG , TCCR0_REG_COM01_BIT);
					SET_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}
				case TIMER0_OC0_CLEAR_ON_COMPARE_MATCH_SET_OC0_AT_TOP :
				{
					SET_BIT(TCCR0_REG   , TCCR0_REG_COM01_BIT);
					CLEAR_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}
				case TIMER0_OC0_SET_ON_COMPARE_MATCH_CLEAR_OC0_AT_TOP :
				{
					SET_BIT(TCCR0_REG , TCCR0_REG_COM01_BIT);
					SET_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}	
				case TIMER0_CLEAR_OC0_UP_COUNTING_SET_OC0_DOWNCOUNTING :
				{
					SET_BIT(TCCR0_REG   , TCCR0_REG_COM01_BIT);
					CLEAR_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}
				case TIMER0_SET_OC0_UP_COUNTING_CLEAR_OC0_DOWNCOUNTING :
				{
					SET_BIT(TCCR0_REG   , TCCR0_REG_COM01_BIT);
					SET_BIT(TCCR0_REG , TCCR0_REG_COM00_BIT);
					ret = TIMER0_SYSTEM_STATE_OC0_OK;
					break;
				}	
				default :
				{
					ret = TIMER0_SYSTEM_STATE_OC0_NOK;
				}		
			}
		}
		else
		{
			/* Do Nothing */
		}
		if(TIMER0_SYSTEM_STATE_OC0_OK == ret )
		{
			switch(str_timer0_cfg->enu_timer0_trigger_mode)
			{
				case TIMER0_INTERRUPT_ENABLE :
				{
					switch(str_timer0_cfg->enu_timer0_mode)
					{
						case TIMER0_NORMAL_MODE :
						{
							MCU_vEnableInterrupt();
							SET_BIT(TIMSK_REG , TIMSK_REG_TOIE0_BIT);
							ret = TIMER0_SYSTEM_STATE_INTERRUPT_OK;
							break;
						}
						case TIMER0_CTC_MODE :
						{
							MCU_vEnableInterrupt();
							SET_BIT(TIMSK_REG , TIMSK_REG_OCIE0_BIT);
							ret = TIMER0_SYSTEM_STATE_INTERRUPT_OK;
							break;	
						}
						default :
						{
							ret = TIMER0_SYSTEM_STATE_INTERRUPT_NOK;
						}
					}
					break;
				}
				case TIMER0_INTERRUPT_DISABLE :
				{
					switch(str_timer0_cfg->enu_timer0_mode)
					{
						case TIMER0_NORMAL_MODE :
						{
							CLEAR_BIT(TIMSK_REG , TIMSK_REG_TOIE0_BIT);
							ret = TIMER0_SYSTEM_STATE_INTERRUPT_OK;
							break;
						}
						case TIMER0_CTC_MODE :
						{
							CLEAR_BIT(TIMSK_REG , TIMSK_REG_OCIE0_BIT);
							ret = TIMER0_SYSTEM_STATE_INTERRUPT_OK;
							break;
						}
						default :
						{
							ret = TIMER0_SYSTEM_STATE_INTERRUPT_NOK;
						}
					}
					break;					
				}
				default :
				{
					ret = TIMER0_SYSTEM_STATE_INTERRUPT_NOK;
				}
			}
		}
		else
		{
			/* DO Nothing*/
		}
		
		if(TIMER0_SYSTEM_STATE_INTERRUPT_OK == ret)
		{
			switch(str_timer0_cfg->enu_timer0_mode)
			{
				case TIMER0_NORMAL_MODE :
				{
					ret = timer0_set_ovf_isr(str_timer0_cfg->ptr_func_overflow_callback);
					break;
				}
				case TIMER0_CTC_MODE :
				{
					ret = timer0_set_ctc_isr(str_timer0_cfg->ptr_func_ctc_callback);
					break;
				}
				default :
				{
					ret = TIMER0_SYSTEM_STATE_SET_ISR_NOK;
				}
			}
		}
		if(TIMER0_SYSTEM_STATE_SET_OVERFLOW_ISR_OK == ret || TIMER0_SYSTEM_STATE_SET_CTC_ISR_OK == ret)
		{
			/* To Make Sure That The Timer Is Stopped Until We Want To Start IT*/
			CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
			CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
			CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
			/* Return that the timer is initialize successfully  */
			ret = TIMER0_SYSTEM_STATE_OK;
		}
	}
	
	return ret;
}
enu_timer0_system_state TIMER0_start(const str_timer0_init_config_t *str_timer0_cfg)
{
	enu_timer0_system_state ret;
	
	if(PTR_NULL == str_timer0_cfg)
	{
		ret = TIMER0_SYSTEM_STATE_NULL_POINTER;
	}
	else
	{
		switch(str_timer0_cfg->enu_timer0_prescaler)
		{
			case TIMER0_NO_SOURCE_CLOCK :
			{
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			case TIMER0_NO_PRESCALER :
			{
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;				
			}
			case TIMER0_8_PRESCALER :
			{
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			case TIMER0_64_PRESCALER :
			{
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			case TIMER0_256_PRESCALER :
			{
				SET_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			case TIMER0_1024_PRESCALER :
			{
				SET_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			case TIMER0_EXTERNAL_CLOCK_FALLING_EDGE_PRESCALER :
			{
				SET_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			case TIMER0_EXTERNAL_CLOCK_RISING_EDGE_PRESCALER :
			{
				SET_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
				SET_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
				ret = TIMER0_SYSTEM_STATE_PRESCALER_OK;
				break;
			}
			default : 
			{
				ret = TIMER0_SYSTEM_STATE_PRESCALER_NOK;
			}
		}
		if(TIMER0_SYSTEM_STATE_PRESCALER_OK == ret)
		{
			ret = TIMER0_SYSTEM_STATE_OK;
		}
	}
	return ret;
}
enu_timer0_system_state TIMER0_stop()
{
	 CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
	 CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
	 CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
	 
	 return TIMER0_SYSTEM_STATE_OK;
}
enu_timer0_system_state TIMER0_set_tcnt(Uint8_t arg_tcnt_value)
{
	TCNT0_REG = arg_tcnt_value;
	return TIMER0_SYSTEM_STATE_OK;
}
enu_timer0_system_state TIMER0_set_ocr(Uint8_t arg_ocr_value)
{
	OCR0_REG = arg_ocr_value;
	return TIMER0_SYSTEM_STATE_OK;
}

void TIMER0_delay_ms(Uint32_t arg_delay_in_ms)
{

	Uint32_t l_u32_timer_tick = 0;
	Uint32_t l_u32_max_delay = 0;
	Uint32_t l_u32_preload_time = 0;
	Uint32_t l_u64_required_time_in_micro_sec = (arg_delay_in_ms * 1000);

	l_u32_timer_tick = DELAY_IN_MS_RESCALER / MCU_FREQ;
	l_u32_max_delay = l_u32_timer_tick * TIMER_RESOLUTION;
	
	g_u32_number_of_ovf = l_u64_required_time_in_micro_sec / l_u32_max_delay;
	
	l_u32_preload_time = TIMER_RESOLUTION - (l_u64_required_time_in_micro_sec % TIMER_RESOLUTION);
	
	TCNT0_REG = l_u32_preload_time;
	g_u32_number_of_ovf++;
	
	/* start timer */
	CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS02_BIT);
	SET_BIT(TCCR0_REG , TCCR0_REG_CS01_BIT);
	CLEAR_BIT(TCCR0_REG , TCCR0_REG_CS00_BIT);
}


void TIMER0_sync_delay_ms(Uint32_t arg_delay_in_ms)
{
	Uint32_t l_u32_timer_tick = 0;
	Uint32_t l_u32_max_delay = 0;
	Uint32_t l_u32_preload_time = 0;
	Uint32_t l_u64_required_time_in_micro_sec = (arg_delay_in_ms * 1000);
	
		g_u64_polling_counter = 0;
	l_u32_timer_tick = DELAY_IN_MS_RESCALER / MCU_FREQ;
	l_u32_max_delay = l_u32_timer_tick * TIMER_RESOLUTION;
	
	g_u32_number_of_ovf = l_u64_required_time_in_micro_sec / l_u32_max_delay;
	
	l_u32_preload_time = TIMER_RESOLUTION - (l_u64_required_time_in_micro_sec % TIMER_RESOLUTION);
	
	TCNT0_REG = l_u32_preload_time;
	g_u32_number_of_ovf++;
	

	while(g_u64_polling_counter != 1);
	g_u64_polling_counter = 0;
	
}


ISR(TIM0_OVF_INT)
{
	if (enable_delay_ms == TIMER0_DELAY_ENABLE)
	{
			if(g_u32_isr_ovf_counter == g_u32_number_of_ovf)
			{
				ptr_func_overflow_isr();
				g_u32_isr_ovf_counter = 0;
				g_u64_polling_counter = 1;
				TIMER0_stop();
			}
			else
			{
				g_u32_isr_ovf_counter++;
			}
	}

	else if (enable_delay_ms == TIMER0_DELAY_DISABLE)
	{
		ptr_func_overflow_isr();	
	}
}

ISR(TIM0_COMP_INT)
{
	ptr_func_ctc_isr();
}

