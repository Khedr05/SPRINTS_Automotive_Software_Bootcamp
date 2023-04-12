/*
 * LED_prog.c
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#include"LED_interface.h"

Std_ReturnType LED_initialize(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
			.port = led->port_name,
			.pin = led->pin,
			.direction = GPIO_DIRECTION_OUTPUT,
			.logic = led->led_status
		};
		ret = GPIO_pin_intialize(&LED_pin_obj);
	}
	return ret;
}
Std_ReturnType LED_turn_on(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
				.port = led->port_name,
				.pin = led->pin,
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = led->led_status
		};
		ret = GPIO_pin_write_logic(&LED_pin_obj , GPIO_LOGIC_HIGH);
	}
	return ret;
}
Std_ReturnType LED_turn_off(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
				.port = led->port_name,
				.pin = led->pin,
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = led->led_status
		};
		ret = GPIO_pin_write_logic(&LED_pin_obj , GPIO_LOGIC_LOW);
	}
	return ret;
}
Std_ReturnType LED_toggle(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
				.port = led->port_name,
				.pin = led->pin,
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = led->led_status
		};
		ret = GPIO_pin_toggle_logic(&LED_pin_obj);
	}
	return ret;
}
