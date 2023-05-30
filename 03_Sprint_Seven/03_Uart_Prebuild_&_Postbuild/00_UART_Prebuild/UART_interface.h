


#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
void UART_IMTvInit();
/*************** FILE INCLUDES ***************/
#include "UART_config.h"
#include "UART_private.h"
#include "Services/BIT_MATH/BIT_MATH.h"
#include "Services/STD_TYPES/STD_TYPES.h"

/*************** OPERATION MODES ***************/
#define UART_Baud_Rate			0x0033 // 51 decimal // F = 8GHZ, NORMAL MODE (U2X=0), 9600 Baud Rate
#define UART_SPEED				NORMAL_SPEED // Use normal if synchronous
#define UART_OPERATION_MODE		UART_ASYNCHRONOUS
#define UART_PARITY_MODE		PARITY_DISABLE
#define UART_STOP_BITS			STOP_BITS_1
#define UART_CHARACTER_SIZE		CHARACTER_SIZE_8
#define USART_CLOCK_EDGE		UART_ASYNCHRONOUS // Synchronous mode only
#define UART_INTERRUPT			UART_IE_DISABLE

/*************** FUNCTION DECLARATION ***************/

// This function is responsible for enabling and initializing UART protocol
void UART_vInit(void);

// This function is responsible for transmitting data
void UART_vTransmitData(u8 Copy_u8Data);

// This function is responsible for receiving data
u8 UART_u8ReceiveData();

// This function is responsible for transmitting a string
void UART_vTransmitString(u8 *Copy_u8String);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
