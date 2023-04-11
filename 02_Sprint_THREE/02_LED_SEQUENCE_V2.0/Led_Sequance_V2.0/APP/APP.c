/*
 * APP.c
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */


#include"APP.h"



ST_led_t led0 =
{
		.port_name = GPIO_PORTC_INDEX,
		.pin = GPIO_PIN0,
		.led_status = LED_STATUS_OFF
};

ST_led_t led1 =
{
		.port_name = GPIO_PORTC_INDEX,
		.pin = GPIO_PIN1,
		.led_status = LED_STATUS_OFF
};

ST_led_t led2 =
{
		.port_name = GPIO_PORTC_INDEX,
		.pin = GPIO_PIN2,
		.led_status = LED_STATUS_OFF
};

ST_led_t led3 =
{
		.port_name = GPIO_PORTC_INDEX,
		.pin = GPIO_PIN3,
		.led_status = LED_STATUS_OFF
};


ST_PUSH_BTN_t btn0 =
{
		.PUSH_BTN_pin =
		{
				.port = GPIO_PORTD_INDEX,
				.pin = GPIO_PIN2,
				.direction = GPIO_DIRECTION_INPUT,
				.logic = GPIO_LOGIC_HIGH
		},
		.PUSH_BTN_connection = PUSH_BTN_PULL_UP,
		.PUSH_BTN_state = PUSH_BTN_STATE_RELEASED
};

void con(void);
ST_EXT_INTERRUPTS_CFG int0 =
{
	.EXTERNAL_INTERRUPRT_Number = EXT0_INTERRUPTS,
	.EXTERNAL_INTERRUPRT_Sense_Control = LOW_LEVEL_SENSE_CONTROL,
	.INTERRUPT_EXTERNAL_HANDLER = con
};


Uchar8_t pressCounterFlag = ZERO_PRESS;



void appmain(void)
{


	LED_initialize(&led0);
	LED_initialize(&led1);
	LED_initialize(&led2);
	LED_initialize(&led3);
	EXT_vINTERRUPT_Init(&int0);
	EXT_INTERRUPT_SetInterruptHandler(&int0);
	PUSH_BTN_intialize(&btn0);

	while(1)
	{

		if(pressCounterFlag == ONE_PRESS)
		{
			LED_turn_on(&led0);
			LED_turn_off(&led1);
			LED_turn_off(&led2);
			LED_turn_off(&led3);
		}
		else if(pressCounterFlag == TWO_PRESS)
		{
			LED_turn_on(&led0);
			LED_turn_on(&led1);
			LED_turn_off(&led2);
			LED_turn_off(&led3);
		}
		else if(pressCounterFlag == THREE_PRESS)
		{
			LED_turn_on(&led0);
			LED_turn_on(&led1);
			LED_turn_on(&led2);
			LED_turn_off(&led3);
		}
		else if(pressCounterFlag == FOUR_PRESS)
		{

			LED_turn_on(&led0);
			LED_turn_on(&led1);
			LED_turn_on(&led2);
			LED_turn_on(&led3);
		}
		else if(pressCounterFlag == FIVE_PRESS)
		{

			LED_turn_off(&led0);
			LED_turn_on(&led1);
			LED_turn_on(&led2);
			LED_turn_on(&led3);
		}
		else if(pressCounterFlag == SIX_PRESS)
		{
			LED_turn_off(&led0);
			LED_turn_off(&led1);
			LED_turn_on(&led2);
			LED_turn_on(&led3);
		}
		else if(pressCounterFlag == SEVEN_PRESS)
		{
			LED_turn_off(&led0);
			LED_turn_off(&led1);
			LED_turn_off(&led2);
			LED_turn_on(&led3);
		}
		else if(pressCounterFlag == EIGHT_PRESS)
		{
			LED_turn_off(&led0);
			LED_turn_off(&led1);
			LED_turn_off(&led2);
			LED_turn_off(&led3);
			pressCounterFlag = ZERO_PRESS;
		}
		else
		{
			LED_turn_off(&led0);
			LED_turn_off(&led1);
			LED_turn_off(&led2);
			LED_turn_off(&led3);

		}
	}
}

void con(void)
{
	pressCounterFlag++;
}

