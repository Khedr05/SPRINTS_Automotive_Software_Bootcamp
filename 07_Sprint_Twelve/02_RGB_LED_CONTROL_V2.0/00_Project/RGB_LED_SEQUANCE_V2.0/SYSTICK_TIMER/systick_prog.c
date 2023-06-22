
#include "systick_interface.h"

static void(*ptrFucnSystickTrigger)(void) = PTR_NULL;

ENU_SYSTICK_systemState_t SYSTICK_init(STR_SYSTICK_cfg_t *systickCfg)
{
	 ENU_SYSTICK_systemState_t ret;
	 
	if(PTR_NULL == systickCfg)
	{
		 ret = SYSTICK_PTR_NULL;
	}
	else
	{
		 if(SYSTICK_SYSTEM_CLOCK == systickCfg->systickClock)
		 {
			  SET_BIT(STCTRL_REG , 2);
			 ret = SYSTICK_CLOCK_OK;
		 }
		 else if(SYSTICK_PIOSC_CLOCK == systickCfg->systickClock)
		 {
			  CLEAR_BIT(STCTRL_REG , 2);
			 ret = SYSTICK_CLOCK_OK;
		 }
		 else
		 {
			  ret = SYSTICK_CLOCK_NOK;
		 }
		 
		 if(SYSTICK_CLOCK_OK == ret)
		 {
			 if(SYSTICK_INTERRUPT_ENABLED == systickCfg->interruptStatus)
			 {
				 	 SET_BIT(STCTRL_REG , 1);
				   ptrFucnSystickTrigger = systickCfg->ptrFucnSystickcallback;
				   ret = SYSTICK_INTERRUPT_OK;
			 }
			 else if(SYSTICK_INTERRUPT_DISABLED == systickCfg->interruptStatus)
			 {
				   CLEAR_BIT(STCTRL_REG , 1);
				   ret = SYSTICK_INTERRUPT_OK;
			 }
			 else
			 {
				 ret = SYSTICK_INIT_NOK;
			 }
		 }
		 else
			 {
				  /* Do Nothing*/
			 }
			
				if(SYSTICK_INTERRUPT_OK == ret)
				{
					 if(SYSTICK_ENABLED == systickCfg->status)
					 {
						  SET_BIT(STCTRL_REG , 0);
						  ret = SYSTICK_ENABLE_OK;
					 }
					 else if(SYSTICK_DISABLED == systickCfg->status)
					 {
						 	CLEAR_BIT(STCTRL_REG , 0);
						  ret = SYSTICK_DISABLE_OK;
					 }
					 else
					 {
						  ret = SYSTICK_ENABLE_NOK;
					 }
				}
				else
				{
					 /* Do Nothing */
				}
				
				if(SYSTICK_ENABLE_OK  == ret || SYSTICK_DISABLE_OK == ret )
				{
					 ret = SYSTICK_INIT_OK;
				}
				else
				{
					ret = SYSTICK_INIT_NOK;
				}
	}
	return ret;
}


ENU_SYSTICK_systemState_t SYSTICK_deinit(void)
{
	ENU_SYSTICK_systemState_t ret;
	CLEAR_BIT(STCTRL_REG , 0);
	ret = SYSTICK_DISABLE_OK;
	return ret;
}





ENU_SYSTICK_systemState_t SYSTICK_enableInterrupt(void)
{
	 ENU_SYSTICK_systemState_t ret;

	 SET_BIT(STCTRL_REG , 1);
	 ret = SYSTICK_INTERRUPT_OK;

	return ret;
}

ENU_SYSTICK_systemState_t SYSTICK_disableInterrupt(void)
{
	 ENU_SYSTICK_systemState_t ret;

	CLEAR_BIT(STCTRL_REG , 1);
	ret = SYSTICK_INTERRUPT_OK;
	
	return ret;	
}

ENU_SYSTICK_systemState_t SYSTICK_setDelayMs(Uint32_t arg_delayInMs)
{
	  ENU_SYSTICK_systemState_t ret;
		STRCURRENT_REG = 0;
	  STRELOAD_REG = ((arg_delayInMs)*(SystemCoreClock/1000)) - 1 ;
		
		
    ret = SYSTICK_DELAY_START_OK;
	
	return ret;
}


void SysTick_Handler(void);
void SysTick_Handler(void)
{
	 if(PTR_NULL != ptrFucnSystickTrigger)
	 {
		 ptrFucnSystickTrigger();
	 }
	 else
	 {
		 /* Do Nothing */
	 }
}
