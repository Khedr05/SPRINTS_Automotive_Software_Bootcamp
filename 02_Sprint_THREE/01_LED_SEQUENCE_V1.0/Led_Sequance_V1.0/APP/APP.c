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
				.port = GPIO_PORTA_INDEX,
				.pin = GPIO_PIN0,
				.direction = GPIO_DIRECTION_INPUT,
				.logic = GPIO_LOGIC_HIGH
		},
		.PUSH_BTN_connection = PUSH_BTN_PULL_UP,
		.PUSH_BTN_state = PUSH_BTN_STATE_RELEASED
};





void appmain(void)
{
	Uchar8_t pressCounterFlag = ZERO_PRESS;
	EN_PUSH_BTN_state_t btnState = PUSH_BTN_STATE_RELEASED;

	LED_initialize(&led0);
	LED_initialize(&led1);
	LED_initialize(&led2);
	LED_initialize(&led3);

	PUSH_BTN_intialize(&btn0);

	while(1)
	{
		PUSH_BTN_read_state(&btn0,&btnState);

		if(btnState == PUSH_BTN_STATE_PRESSED)
		{
			_delay_ms(50);
			pressCounterFlag++;
		}

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
			pressCounterFlag = 0;
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


