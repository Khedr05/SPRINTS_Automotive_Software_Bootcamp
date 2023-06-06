/*
 * EXT_INTERRUPT_Interface.h
 *
 *  Created on: 9 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_

#include "exti_config.h"
#include "exti_private.h"
#include "../../MCAL/mcu_cfg/mcu_interface.h"
#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "../../COMMON/vect_table.h"



Std_ReturnType EXT_vINTERRUPT_Init(const  ST_EXT_INTERRUPTS_CFG *EXT_INTx);
Std_ReturnType EXT_vINTERRUPT_Denit(const ST_EXT_INTERRUPTS_CFG *EXT_INTx);




#endif /* MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_ */
