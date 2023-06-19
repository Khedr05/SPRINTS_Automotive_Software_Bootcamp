/*
 * led_config.h
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */

#ifndef ECUAL_LED_LED_CONFIG_H_
#define ECUAL_LED_LED_CONFIG_H_

#include "dio_interface.h"


#define  LED_PIN_CFG_ARRAY_SIZE    3


typedef enum
{
  LED_INIT_OK = 0,
  LED_INIT_NOK,
  LED_NULL_PTR

}ENU_LED_systemState_t;


typedef struct
{
    ENU_GPIO_port_t    portNumber;
    ENU_GPIO_pin_t     pinNumber;
    ENU_GPIO_logic_t   led_status;
}ST_led_pinCfg_t;


#endif /* ECUAL_LED_LED_CONFIG_H_ */
