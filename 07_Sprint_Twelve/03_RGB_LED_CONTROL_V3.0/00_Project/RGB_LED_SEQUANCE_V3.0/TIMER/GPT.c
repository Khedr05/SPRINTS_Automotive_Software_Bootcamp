#include "GPT.h"
  void (*TIMER0A_Callback)(void) = NULL;
	uint32_t On_time=0;
	uint32_t OFF_time=0;
Gpt_State Gpt_init(Gpt_ConfigType *Config)
{
		Gpt_State error =GPT_OK;

	uint8_t init_counter=0;
for(init_counter=0;	init_counter<MAX_CHANNELS;init_counter++)	
	{
		
		Gpt_ChannelType channelid = Config[init_counter].GptChannelId;
SET_BIT(RCGCTIMER,channelid);

		CLR_BIT(GPT_channel_CFG(channelid),TIMER_CONFIGRATION_32);

		if(timerA==Config[init_counter].timeruse)
{
	CLR_BIT(GPT_channel_CTL(channelid),GPT_TIMER_A_ENABLE);
		if(GPT_MODE_ONE_SHOT==Config[init_counter].ChannelMode)
		{
			 SET_BIT(GPT_channel_TAMR(channelid),GPT_TAMR_ONR_SHOT_MODE_A);	
		}else if (GPT_MODE_CONTINUOUS==Config[init_counter].ChannelMode)
		{
					 SET_BIT(GPT_channel_TAMR(channelid),GPT_TAMR_CONTINUOUS_MODE_A);
		}
		else {
		error=GPT_ERROR_INVALID_MODE;
		}
		
		
		
		if(up==Config[init_counter].countdirection)
		{
		SET_BIT(GPT_channel_TAMR(channelid),GPT_TAMR_DIRECTION_A);

		}else if (down==Config[init_counter].countdirection)
		{
		CLR_BIT(GPT_channel_TAMR(channelid),GPT_TAMR_DIRECTION_A);
		}else 
		{
					error=GPT_ERROR_INVALID_MODE;
		}
			
	}else if(timerB==Config[init_counter].timeruse)
{
		CLR_BIT(GPT_channel_CTL(channelid),GPT_TIMER_B_ENABLE);

if(GPT_MODE_ONE_SHOT==Config[init_counter].ChannelMode)
		{
			 SET_BIT(GPT_channel_TBMR(channelid),GPT_TAMR_ONR_SHOT_MODE_B);	
		}else if (GPT_MODE_CONTINUOUS==Config[init_counter].ChannelMode)
		{
					 SET_BIT(GPT_channel_TBMR(channelid),GPT_TAMR_CONTINUOUS_MODE_B);
		}
		else {
		error=GPT_ERROR_INVALID_MODE;
		}
		
		
		
		if(up==Config[init_counter].countdirection)
		{
		SET_BIT(GPT_channel_TBMR(channelid),GPT_TAMR_DIRECTION_B);

		}else if (down==Config[init_counter].countdirection)
		{
		CLR_BIT(GPT_channel_TBMR(channelid),GPT_TAMR_DIRECTION_B);
		}else 
		{
					error=GPT_ERROR_INVALID_MODE;
		}

	}
else
	{	error=GPT_ERROR_INVALID_MODE;
}

SET_BIT(GPT_channel_CTL(channelid),GPT_CTL_STAL_BIT);

 
}
	
	return error;
}


 Gpt_State GPT_Start_Timer(Gpt_ChannelType channel_id,uint32_t u32_time)
{ uint32_t	total_ticks =0;
	flaot64_t tick_time = 1.0/F_CPU;
	Gpt_State error =GPT_OK;
		if(channel_id>GPT_MAX_CHANNELS)
	{
	error =GPT_ERROR_INVALID_CHANNEL;
	}
	else{
			total_ticks = ((u32_time/ MILISCOUND_CONVERT)/(tick_time));
						GPT_channel_MTAILR(channel_id)= total_ticks;
	SET_BIT(GPT_channel_CTL(channel_id),GPT_TIMER_A_ENABLE);
	}
	return error ;
	
}
Gpt_State GPT_STOP_Timer(Gpt_ChannelType channel_id)
{
	Gpt_State error =GPT_OK;
		if(channel_id>GPT_MAX_CHANNELS)
	{
	error =GPT_ERROR_INVALID_CHANNEL;
	}
	else{
	CLR_BIT(GPT_channel_CTL(channel_id),GPT_TIMER_A_ENABLE);
	}
	return error ;
	
}




 Gpt_State GPT_enable_intturpt(Gpt_ChannelType channel_id)
{
Gpt_State error = GPT_OK;
		if(channel_id>GPT_MAX_CHANNELS)
	{
	error =GPT_ERROR_INVALID_CHANNEL;
	}
	else{
	SET_BIT(GPT_channel_IMR(channel_id),GPT_TIMER_A_ENABLE_INTURRPT); 
NVIC_EnableIRQ(TIMER0A_IRQn);
	__enable_irq();
	}
	return error;
}
 Gpt_State GPT_disable_intturpt(Gpt_ChannelType channel_id)
{
Gpt_State error = GPT_OK;
	if(channel_id>GPT_MAX_CHANNELS)
	{
	error =GPT_ERROR_INVALID_CHANNEL;
	}
	else{
	CLR_BIT(GPT_channel_IMR(channel_id),GPT_TIMER_A_ENABLE_INTURRPT); 
	}
	return error;
}

Gpt_State PWM_Init(uint32_t ui32Period, uint8_t ui8DutyCycle)
{
	Gpt_State error = GPT_OK;

On_time = (((ui32Period )*ui8DutyCycle)/100);
	OFF_time= ui32Period-On_time;

 
  	GPT_Start_Timer(GPT_CHANNEL_0,OFF_time);
	return error;
}

 Gpt_State GPT_GetElapsedTime(Gpt_ChannelType channel_id,Timer_Use timer_use, uint32_t *time)
{
	Gpt_State error = GPT_OK;
	if(channel_id>GPT_MAX_CHANNELS)
	{
	error =GPT_ERROR_INVALID_CHANNEL;
	}
	else{
if(timerA==timer_use)
{
		*time=GPT_channel_MTAV(channel_id);
}
else if (timerB==timer_use)
{
	*time=GPT_channel_MTBV(channel_id);
}
else
{

					error=GPT_ERROR_INVALID_MODE;


}
	
	}
		return error;

}
 Gpt_State GPT_GetRemainingTime(Gpt_ChannelType channel_id,Timer_Use timer_use,uint32_t time)
{
	
	Gpt_State error = GPT_OK;
	if(channel_id>GPT_MAX_CHANNELS)
	{
	error =GPT_ERROR_INVALID_CHANNEL;
	}
	else{
if(timerA==timer_use)
{
	uint32_t elapsedTime = GPT_channel_MTAV(channel_id);

		uint32_t targetingTime =GPT_channel_MTAILR(channel_id);

		time = targetingTime - elapsedTime;
}else if (timerB==timer_use)
{
	uint32_t elapsedTime = GPT_channel_MTBV(channel_id);

		uint32_t targetingTime =GPT_channel_MTAILR(channel_id);

		time = targetingTime - elapsedTime;
}else
{

					error=GPT_ERROR_INVALID_MODE;


}
}
return error ;

   } 




void TIMER0A_Handler(void)
{
	      if (TIMER0A_Callback != NULL)
    {		
			GPT_STOP_Timer(GPT_CHANNEL_0);
			SET_BIT(GPT_channel_ICR(GPT_CHANNEL_0),0);

			        TIMER0A_Callback();
			
	

			// Call the registered callback function
    }
}