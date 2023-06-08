/*
 * PB_config.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_PUSH_BUTTON_PB_CONFIG_H_
#define ECU_PUSH_BUTTON_PB_CONFIG_H_

#include"../../MCAL/DIO/DIO_interface.h"

typedef enum
{
    PUSH_BTN_STATE_PRESSED = 0,
    PUSH_BTN_STATE_RELEASED
}EN_PUSH_BTN_state_t;

typedef enum
{
    PUSH_BTN_PULL_UP = 0,
    PUSH_BTN_PULL_DOWN
}EN_PUSH_BTN_active_t;

typedef struct
{
    ST_pin_config_t PUSH_BTN_pin;
    EN_PUSH_BTN_state_t PUSH_BTN_state;
    EN_PUSH_BTN_active_t PUSH_BTN_connection;
}ST_PUSH_BTN_t;

#endif /* ECU_PUSH_BUTTON_PB_CONFIG_H_ */
