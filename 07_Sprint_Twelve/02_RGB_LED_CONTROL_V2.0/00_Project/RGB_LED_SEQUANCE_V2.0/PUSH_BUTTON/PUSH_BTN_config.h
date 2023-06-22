/*
 * push_btn_config.h
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */

#ifndef ECUAL_PUSH_BTN_PUSH_BTN_CONFIG_H_
#define ECUAL_PUSH_BTN_PUSH_BTN_CONFIG_H_

#include "dio_interface.h"
#define  PUSH_BTN_PIN_CFG_ARRAY_SIZE    1


typedef enum
{
  PUSH_BTN_INIT_OK = 0,
  PUSH_BTN_INIT_NOK,
  PUSH_BTN_NULL_PTR,
  PUSH_BTN_INVALD_CONNECTION,
  PUSH_BTN_READ_OK,
  PUSH_BTN_READ_NOK

}ENU_PUSH_BTN_systemState_t;

typedef enum
{
    PUSH_BTN_STATE_PRESSED = 0,
    PUSH_BTN_STATE_RELEASED
}ENU_PUSH_BTN_state_t;

typedef struct
{
    ENU_GPIO_port_t                 portNumber;
    ENU_GPIO_pin_t                  pinNumber;
    ENU_GPIO_pinInternalAttach_t    pushBtnConnection;
}ST_PUSH_BTN_pinCfg_t;



#endif /* ECUAL_PUSH_BTN_PUSH_BTN_CONFIG_H_ */
