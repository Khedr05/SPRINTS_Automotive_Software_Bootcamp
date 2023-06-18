#include "app.h"
extern ST_PUSH_BTN_pinCfg_t a_pushBtnCfgPins[PUSH_BTN_PIN_CFG_ARRAY_SIZE];
extern ST_led_pinCfg_t a_ledCfgPins[LED_PIN_CFG_ARRAY_SIZE];

ENU_PUSH_BTN_state_t pushed_button =0;
uint8_t flag=0;
uint8_t flag2=0;

void app_init(void)
{
	LED_initialize(&a_ledCfgPins[0]);
	LED_initialize(&a_ledCfgPins[1]);
	LED_initialize(&a_ledCfgPins[2]);

	PUSH_BTN_intialize(a_pushBtnCfgPins);
	
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
				LED_turnOn(&a_ledCfgPins[0]);
			flag++;
		}else if (flag==1)
		{
			LED_turnOff(&a_ledCfgPins[0]);
				LED_turnOn(&a_ledCfgPins[2]);
						flag++;

		}else if (flag==2)
		{
			LED_turnOff(&a_ledCfgPins[2]);
				LED_turnOn(&a_ledCfgPins[1]);
						flag++;

		}else if (flag==3)
		{
						LED_turnOn(&a_ledCfgPins[0]);
				LED_turnOn(&a_ledCfgPins[1]);
				LED_turnOn(&a_ledCfgPins[2]);
flag++;
		}else if (flag==4)
		{
		LED_turnOff(&a_ledCfgPins[0]);
				LED_turnOff(&a_ledCfgPins[1]);
				LED_turnOff(&a_ledCfgPins[2]);
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



