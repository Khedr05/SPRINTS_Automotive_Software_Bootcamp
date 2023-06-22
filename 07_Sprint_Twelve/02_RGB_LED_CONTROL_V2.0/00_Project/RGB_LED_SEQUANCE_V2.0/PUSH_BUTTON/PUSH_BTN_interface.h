/*
 * push_btn_interface.h
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */

#ifndef ECUAL_PUSH_BTN_PUSH_BTN_INTERFACE_H_
#define ECUAL_PUSH_BTN_PUSH_BTN_INTERFACE_H_


#include "std_types.h"
#include "bit_math.h"
#include "dio_interface.h"
#include "push_btn_config.h"

ENU_PUSH_BTN_systemState_t PUSH_BTN_intialize(const ST_PUSH_BTN_pinCfg_t *btn);
ENU_PUSH_BTN_systemState_t PUSH_BTN_read_state(const ST_PUSH_BTN_pinCfg_t *btn , ENU_PUSH_BTN_state_t *btn_state);



#endif /* ECUAL_PUSH_BTN_PUSH_BTN_INTERFACE_H_ */
