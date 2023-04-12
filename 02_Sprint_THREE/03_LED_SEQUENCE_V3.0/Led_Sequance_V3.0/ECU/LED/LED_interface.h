/*
 * LED_interface.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_LED_LED_INTERFACE_H_
#define ECU_LED_LED_INTERFACE_H_

#include"LED_config.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"../../SERVICES/BIT_Math.h"
#include"../../SERVICES/STD_Types.h"


 Std_ReturnType LED_initialize(const ST_led_t *led);
 Std_ReturnType LED_turn_on(const ST_led_t *led);
 Std_ReturnType LED_turn_off(const ST_led_t *led);
 Std_ReturnType LED_toggle(const ST_led_t *led);

#endif /* ECU_LED_LED_INTERFACE_H_ */
