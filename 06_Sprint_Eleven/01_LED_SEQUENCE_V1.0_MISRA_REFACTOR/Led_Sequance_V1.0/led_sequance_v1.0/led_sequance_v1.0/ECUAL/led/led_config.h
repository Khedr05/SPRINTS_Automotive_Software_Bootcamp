/*
 * LED_config.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_LED_LED_CONFIG_H_
#define ECU_LED_LED_CONFIG_H_

#include"../../COMMON/std_types.h"

typedef enum
{
    LED_STATUS_OFF = 0,
    LED_STATUS_ON,
}EN_led_status_t;

typedef struct
{
    Uint8_t port_name : 3;
    Uint8_t pin : 3;
    Uint8_t led_status : 1;
    Uint8_t reserved : 1;
}ST_led_t;



#endif /* ECU_LED_LED_CONFIG_H_ */
