/*************************************************************************//*
 Author        				: Sherif Ashraf Ali                      
 Date         				: 20 Feb 2023                               
 Project Name | File Name   : AVR_DRIVER | MCU_Interface.h         
 Version       				: V-01                                   
 GitHub       				: https://github.com/sherifkhadr         
*//*************************************************************************/

#ifndef MCAL_MCU_INTERRUPT_MCU_INTERFACE_H_
#define MCAL_MCU_INTERRUPT_MCU_INTERFACE_H_


#include"MCU_Private.h"
#include"../../COMMON/bit_math.h"
#include"../../COMMON/std_types.h"

/*
Function: MCU_vEnableInterrupt

Description: Enables Global interrupts on a micro-controller.

Return Type: void. This function does not return a value.

Overall, the MCU_vEnableInterrupt function provides a way to enable interrupts globally on a 
micro-controller. By using this function, the software can ensure that interrupts are enabled 
and can be triggered as needed.
*/
void MCU_vEnableInterrupt(void);

void MCU_vDisableInterrupt(void);


#endif /* MCAL_MCU_INTERRUPT_MCU_INTERFACE_H_ */
