/*
 * push_btn_config.c
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */



#include "PUSH_BTN_interface.h"

ST_PUSH_BTN_pinCfg_t a_pushBtnCfgPins[PUSH_BTN_PIN_CFG_ARRAY_SIZE] =
{
   {GPIO_PORTF , GPIO_PIN4 , GPIO_PULL_UP}
};
