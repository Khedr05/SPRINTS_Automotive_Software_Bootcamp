/*
 * led_config.c
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */


#include "led_interface.h"

ST_led_pinCfg_t a_ledCfgPins[LED_PIN_CFG_ARRAY_SIZE] =
{
	{GPIO_PORTF , GPIO_PIN1 , GPIO_LOGIC_LOW},
	{GPIO_PORTF , GPIO_PIN2 , GPIO_LOGIC_LOW},
  {GPIO_PORTF , GPIO_PIN3 , GPIO_LOGIC_LOW}
};



