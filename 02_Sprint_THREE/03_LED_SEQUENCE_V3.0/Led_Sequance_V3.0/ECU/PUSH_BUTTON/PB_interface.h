/*
 * PB_interface.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_PUSH_BUTTON_PB_INTERFACE_H_
#define ECU_PUSH_BUTTON_PB_INTERFACE_H_

#include"PB_config.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"../../SERVICES/BIT_Math.h"


Std_ReturnType PUSH_BTN_intialize(const ST_PUSH_BTN_t *btn);

Std_ReturnType PUSH_BTN_read_state(const ST_PUSH_BTN_t *btn , EN_PUSH_BTN_state_t *btn_state);

#endif /* ECU_PUSH_BUTTON_PB_INTERFACE_H_ */
