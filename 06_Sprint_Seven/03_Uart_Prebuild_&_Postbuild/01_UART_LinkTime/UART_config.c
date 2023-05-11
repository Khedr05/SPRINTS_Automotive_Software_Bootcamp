
#include "UART_config.h"


typedef struct{
	EN_CharSize_tcfg		
	EN_ParityState_tcfg		
	EN_StopBitsNum_tcfg		
	EN_UARTInterrupt_tcfg	
	EN_UARTBaudRate2X_tcfg	
	EN_UARTBaudRate1X_tcfg	
	EN_UART_ClkMode_tcfg	
	EN_UARTCommMode_tcfg	
}ST_UART_tcfgInitialize;

const ST_UART_tcfgInitialize UART_arr[MAX_UART_SIZE];


UART_arr[0]
{
	.GLOBAL_tcfgCharSize  = CHAR_8_BITS,
	.GLOBAL_tcfgParityState = PARITY_DISABLED,
	.GLOBAL_tcfgStopBits = STOP_BITS_1,
	.GLOBAL_tcfgUartInterrupt = UART_INTERRUPT_DISABLED,
	.GLOBAL_tcfgUartBaudRate2X =UART_BR2X_9600,
	.GLOBAL_tcfgUartBaudRate1X =UART_BR1X_9600,
	.GLOBAL_tcfgUartClkMode =UART_1X_SPEED,
	.GLOBAL_tcfgUartCommMode =UART_ASYNCHRONOUS
};

