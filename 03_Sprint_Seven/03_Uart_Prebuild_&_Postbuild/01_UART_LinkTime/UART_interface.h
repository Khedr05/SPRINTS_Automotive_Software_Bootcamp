

#ifndef MCAL_ATMEGA32_UART_UART_INTERFACE_H_
#define MCAL_ATMEGA32_UART_UART_INTERFACE_H_

/* Section : Includes */
#include "UART_config.h"
#include "UART_private.h"
#include "../Services/BIT_MATH/BIT_MATH.h"
#include "../Services/STD_TYPES/STD_TYPES.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */


/* Section : Function Declarations */
void UART_vInit(u8 deviceNumber);

void UART_vEnable(void);

void UART_vDisable(void);

void UART_vSendData(u8 LOCAL_u8Data);

u8 UART_u8ReceiveData(void);

void UART_vSendString(u8 *Copy_u8Str);

void UART_vClearBuffer(void);

#endif /* MCAL_ATMEGA32_UART_UART_INTERFACE_H_ */
