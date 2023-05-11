

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
typedef struct{
	EN_CharSize_tcfg		GLOBAL_tcfgCharSize;
	EN_ParityState_tcfg		GLOBAL_tcfgParityState;
	EN_StopBitsNum_tcfg		GLOBAL_tcfgStopBits;
	EN_UARTInterrupt_tcfg	GLOBAL_tcfgUartInterrupt;
	EN_UARTBaudRate2X_tcfg	GLOBAL_tcfgUartBaudRate2X;
	EN_UARTBaudRate1X_tcfg	GLOBAL_tcfgUartBaudRate1X;
	EN_UART_ClkMode_tcfg	GLOBAL_tcfgUartClkMode;
	EN_UARTCommMode_tcfg	GLOBAL_tcfgUartCommMode;
}ST_UART_tcfgInitialize;

/* Section : Function Declarations */
void UART_vInit(const ST_UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vEnable(const ST_UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vDisable(const ST_UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vSendData(u8 LOCAL_u8Data);

u8 UART_u8ReceiveData(void);

void UART_vSendString(u8 *Copy_u8Str);

void UART_vClearBuffer();

#endif /* MCAL_ATMEGA32_UART_UART_INTERFACE_H_ */
