
/*
 * led_config.h
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */

#ifndef ECUAL_LED_LED_CONFIG_H_
#define ECUAL_LED_LED_CONFIG_H_

#include "port.h"
#define  LED_PIN_CFG_ARRAY_SIZE    3


typedef enum
{
  LED_INIT_OK = 0,
  LED_INIT_NOK,
  LED_NULL_PTR

}ENU_LED_systemState_t;


typedef struct
{
    Port_Num    portNumber;
    Port_PinNum     pinNumber;
    Port_PinLevel   led_status;
}ST_led_pinCfg_t;


#endif /* ECUAL_LED_LED_CONFIG_H_ */
