/*
 * EXT_INTERRUPT_Interface.h
 *
 *  Created on: 9 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_

#include"EXT_INTERRUPT_Config.h"
#include"EXT_INTERRUPT_Private.h"
#include"../../../MCAL/MCU_CFG/MCU_Interface.h"
#include"../../../SERVICES/BIT_Math.h"
#include"../../../SERVICES/STD_Types.h"



Std_ReturnType EXT_vINTERRUPT_Init(const  ST_EXT_INTERRUPTS_CFG *EXT_INTx);
Std_ReturnType EXT_vINTERRUPT_Denit(const ST_EXT_INTERRUPTS_CFG *EXT_INTx);




#endif /* MCAL_INTERRUPT_EXTERNAL_INTERRUPT_EXT_INTERRUPT_INTERFACE_H_ */
