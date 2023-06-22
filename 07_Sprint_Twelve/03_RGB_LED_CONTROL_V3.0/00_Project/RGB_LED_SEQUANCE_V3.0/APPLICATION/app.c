#include "app.h"
extern ST_PUSH_BTN_pinCfg_t a_pushBtnCfgPins[PUSH_BTN_PIN_CFG_ARRAY_SIZE];
extern ST_led_pinCfg_t a_ledCfgPins[LED_PIN_CFG_ARRAY_SIZE];
extern Gpt_ConfigType STR_GPTConfig[MAX_CHANNELS];
extern 	uint32_t On_time;
extern uint32_t OFF_time;
ENU_PUSH_BTN_state_t pushed_button =0;
uint8_t flag=0;
uint8_t flag2=0;
uint8_t is_on=0;
void timercallback(void)
{
if(is_on==1)
{
					LED_turnOff(&a_ledCfgPins[LED_PIN]);
GPT_Start_Timer(0,OFF_time);
is_on = 0 ;
}else
{
				LED_turnOn(&a_ledCfgPins[LED_PIN]);

GPT_Start_Timer(0,On_time  );
is_on = 1 ;

}

}
void app_init(void)
{
	LED_initialize(&a_ledCfgPins[LED_PIN]);

	PUSH_BTN_intialize(a_pushBtnCfgPins);
	TIMER0A_Callback=timercallback;

	Gpt_init(&STR_GPTConfig);

	GPT_enable_intturpt(GPT_CHANNEL_0);



    // Enable global interrupts
    __enable_irq();
}
void app_superloop(void)
{

	PUSH_BTN_read_state(a_pushBtnCfgPins,&pushed_button);

	 if(pushed_button==PUSH_BTN_STATE_RELEASED)
	{
		flag2=0;
	}
	else if(pushed_button==PUSH_BTN_STATE_PRESSED)
	{
	

		if(flag2==0)
		{
			flag2=1;
			if(flag==0)
		{
				LED_turnOff(&a_ledCfgPins[LED_PIN]);
						is_on=0;

			PWM_Init(PERIOD,FIRST_DUTY);



			flag++;
		}else if (flag==1)
		{
			LED_turnOff(&a_ledCfgPins[LED_PIN]);
						is_on=0;

			PWM_Init(PERIOD,SECOUND_DUTY);


			flag++;

		}else if (flag==2)
		{
			LED_turnOff(&a_ledCfgPins[LED_PIN]);
			is_on=0;
			
	PWM_Init(PERIOD,THIRD_DUTY);

			flag++;

		}else if (flag==3)
		{
						LED_turnOff(&a_ledCfgPins[LED_PIN]);

			GPT_STOP_Timer(0);


			flag=0;
		}
	}
		
		
	}
	/*this loop to detection the debouncing*/

	for(volatile uint16_t i=0;i<1000;i++)
		{
		for(volatile uint16_t j=0;j<100;j++)
{
}
		}

}

