/*
 * APP.c
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */


#include"APP.h"


void INT0_ISR_HANDELER(void);
void INT1_ISR_HANDELER(void);

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

ST_PUSH_BTN_t btn1 =
{
		.PUSH_BTN_pin =
		{
				.port = GPIO_PORTD_INDEX,
				.pin = GPIO_PIN3,
				.direction = GPIO_DIRECTION_INPUT,
				.logic = GPIO_LOGIC_HIGH
		},
		.PUSH_BTN_connection = PUSH_BTN_PULL_UP,
		.PUSH_BTN_state = PUSH_BTN_STATE_RELEASED
};

ST_EXT_INTERRUPTS_CFG int0 =
{
		.EXTERNAL_INTERRUPRT_Number = EXT0_INTERRUPTS,
		.EXTERNAL_INTERRUPRT_Sense_Control = LOW_LEVEL_SENSE_CONTROL,
		.INTERRUPT_EXTERNAL_HANDLER = INT0_ISR_HANDELER
};

ST_EXT_INTERRUPTS_CFG int1 =
{
		.EXTERNAL_INTERRUPRT_Number = EXT1_INTERRUPTS,
		.EXTERNAL_INTERRUPRT_Sense_Control = LOW_LEVEL_SENSE_CONTROL,
		.INTERRUPT_EXTERNAL_HANDLER = INT1_ISR_HANDELER
};




Uchar8_t blankCounter = ONE_PRESS;
Uchar8_t seqCounter = ZERO_PRESS;
void appmain(void)
{


	LED_initialize(&led0);
	LED_initialize(&led1);
	LED_initialize(&led2);
	LED_initialize(&led3);
	EXT_vINTERRUPT_Init(&int0);
	EXT_INTERRUPT_SetInterruptHandler(&int0);
	EXT_vINTERRUPT_Init(&int1);
	EXT_INTERRUPT_SetInterruptHandler(&int1);
	PUSH_BTN_intialize(&btn0);
	PUSH_BTN_intialize(&btn1);
	MCU_vEnableInterrupt();
	while(1)
	{

		switch(blankCounter)
		{
		case ONE_PRESS :
		{
			BlinkModes(100,900);
			break;
		}
		case TWO_PRESS :
		{
			BlinkModes(200,800);
			break;
		}
		case THREE_PRESS :
		{
			BlinkModes(300,700);
			break;
		}
		case FOUR_PRESS :
		{
			BlinkModes(500,500);
			break;
		}
		case FIVE_PRESS :
		{
			BlinkModes(800,200);
			break;
		}
		}
	}
}


void BlinkModes(Uint32_t from,Uint32_t to)
{
	switch(seqCounter)
	{
	case ONE_PRESS:
	{
		LED_turn_on(&led0);
		delay_ms(from);
		LED_turn_off(&led0);
		delay_ms(to);
		break;
	}
	case TWO_PRESS:
	{
		LED_turn_on(&led0);
		LED_turn_on(&led1);
		delay_ms(from);
		LED_turn_off(&led0);
		LED_turn_off(&led1);
		delay_ms(to);
		break;
	}
	case THREE_PRESS:
	{
		LED_turn_on(&led0);
		LED_turn_on(&led1);
		LED_turn_on(&led2);
		delay_ms(from);
		LED_turn_off(&led0);
		LED_turn_off(&led1);
		LED_turn_off(&led2);
		delay_ms(to);
		break;
	}
	case FOUR_PRESS:
	{
		LED_turn_on(&led0);
		LED_turn_on(&led1);
		LED_turn_on(&led2);
		LED_turn_on(&led3);
		delay_ms(from);
		LED_turn_off(&led0);
		LED_turn_off(&led1);
		LED_turn_off(&led2);
		LED_turn_off(&led3);
		delay_ms(to);
		break;
	}
	case FIVE_PRESS:
	{
		LED_turn_off(&led0);
		LED_turn_on(&led1);
		LED_turn_on(&led2);
		LED_turn_on(&led3);
		delay_ms(from);
		LED_turn_off(&led1);
		LED_turn_off(&led2);
		LED_turn_off(&led3);
		delay_ms(to);
		break;
	}
	case SIX_PRESS:
	{
		LED_turn_on(&led2);
		LED_turn_on(&led3);
		delay_ms(from);
		LED_turn_off(&led2);
		LED_turn_off(&led3);
		delay_ms(to);
		break;
	}
	case SEVEN_PRESS:
	{
		LED_turn_on(&led3);
		delay_ms(from);
		LED_turn_off(&led3);
		delay_ms(to);
		break;
	}
	case EIGHT_PRESS:
	{
		LED_turn_off(&led0);
		LED_turn_off(&led1);
		LED_turn_off(&led2);
		LED_turn_off(&led3);
	}


	}
}


void INT0_ISR_HANDELER(void)
{
	seqCounter++;
	if(seqCounter == 9)
	seqCounter = 0;

}

void INT1_ISR_HANDELER(void)
{
	blankCounter++;
	if(blankCounter == 6)
	blankCounter = 1;

}




