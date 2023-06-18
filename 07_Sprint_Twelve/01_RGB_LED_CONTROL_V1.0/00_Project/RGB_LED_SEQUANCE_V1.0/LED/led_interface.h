/*
 * led_interface.h
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */

#ifndef ECUAL_LED_LED_INTERFACE_H_
#define ECUAL_LED_LED_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "port.h"
#include "led_config.h"

void LED_initialize(const ST_led_pinCfg_t *led);
void LED_turnOn(const ST_led_pinCfg_t *led);
void LED_turnOff(const ST_led_pinCfg_t *led);
void LED_toggle(const ST_led_pinCfg_t *led);


#endif /* ECUAL_LED_LED_INTERFACE_H_ */
