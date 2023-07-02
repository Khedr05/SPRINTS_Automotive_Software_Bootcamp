
#ifndef ECUAL_PUSH_BTN_PUSH_BTN_INTERFACE_H_
#define ECUAL_PUSH_BTN_PUSH_BTN_INTERFACE_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "port.h"
#include "BUTTON_config.h"

ENU_PUSH_BTN_systemState_t PUSH_BTN_intialize(const ST_PUSH_BTN_pinCfg_t *btn);
ENU_PUSH_BTN_systemState_t PUSH_BTN_read_state(const ST_PUSH_BTN_pinCfg_t *btn , ENU_PUSH_BTN_state_t *btn_state);



#endif /* ECUAL_PUSH_BTN_PUSH_BTN_INTERFACE_H_ */
