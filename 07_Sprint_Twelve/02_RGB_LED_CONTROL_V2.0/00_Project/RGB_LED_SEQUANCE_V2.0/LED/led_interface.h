/*
 * led_interface.h
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */

#ifndef ECUAL_LED_LED_INTERFACE_H_
#define ECUAL_LED_LED_INTERFACE_H_

#include "bit_math.h"
#include "std_types.h"
#include "dio_interface.h"
#include "led_config.h"


 ENU_LED_systemState_t LED_initialize(const ST_led_pinCfg_t *led);
 ENU_LED_systemState_t LED_turnOn(const ST_led_pinCfg_t *led);
 ENU_LED_systemState_t LED_turnOff(const ST_led_pinCfg_t *led);
 ENU_LED_systemState_t LED_toggle(const ST_led_pinCfg_t *led);


#endif /* ECUAL_LED_LED_INTERFACE_H_ */
