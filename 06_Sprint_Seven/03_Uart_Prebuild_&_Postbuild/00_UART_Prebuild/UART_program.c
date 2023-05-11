
#include "UART_interface.h"

// This function is responsible for enabling and initializing UART protocol
void UART_vInit(void){

	// Set normal or double speed
#if UART_SPEED == NORMAL_SPEED
	CLR_BIT(UCSRA_REG, U2X_BIT);
#elif UART_SPEED == DOUBLE_SPEED
	SET_BIT(UCSRA_REG, U2X_BIT);
#endif

	// Enable TX and RX
	SET_BIT(UCSRB_REG, RXEN_BIT);
	SET_BIT(UCSRB_REG, TXEN_BIT);

	 // Choose Synchronous or Asynchronous
#if UART_OPERATION_MODE == UART_ASYNCHRONOUS
	CLR_BIT(UCSRC_REG, UMSEL_BIT);
#elif UART_OPERATION_MODE == UART_SYNCHRONOUS
	SET_BIT(UCSRC_REG, UMSEL_BIT);
#endif

	// Choose Parity Mode
#if UART_PARITY_MODE == PARITY_DISABLE
	CLR_BIT(UCSRC_REG, UPM0_BIT);
	CLR_BIT(UCSRC_REG, UPM1_BIT);
#elif UART_PARITY_MODE == PARITY_ENABLE_EVEN
	CLR_BIT(UCSRC_REG, UPM0_BIT);
	SET_BIT(UCSRC_REG, UPM1_BIT);
#elif UART_PARITY_MODE == PARITY_ENABLE_ODD
	SET_BIT(UCSRC_REG, UPM0_BIT);
	SET_BIT(UCSRC_REG, UPM1_BIT);
#endif

	// Choose Stop Bits
#if UART_STOP_BITS == STOP_BITS_1
	CLR_BIT(UCSRC_REG, USBS_BIT);
#elif UART_STOP_BITS == STOP_BITS_2
	SET_BIT(UCSRC_REG, USBS_BIT);
#endif

	// Choose Character Size
#if UART_CHARACTER_SIZE == CHARACTER_SIZE_5
	CLR_BIT(UCSRC_REG, UCSZ0_BIT);
	CLR_BIT(UCSRC_REG, UCSZ1_BIT);
	CLR_BIT(UCSRB_REG, UCSZ2_BIT);
#elif UART_CHARACTER_SIZE == CHARACTER_SIZE_6
	SET_BIT(UCSRC_REG, UCSZ0_BIT);
	CLR_BIT(UCSRC_REG, UCSZ1_BIT);
	CLR_BIT(UCSRB_REG, UCSZ2_BIT);
#elif UART_CHARACTER_SIZE == CHARACTER_SIZE_7
	CLR_BIT(UCSRC_REG, UCSZ0_BIT);
	SET_BIT(UCSRC_REG, UCSZ1_BIT);
	CLR_BIT(UCSRB_REG, UCSZ2_BIT);
#elif UART_CHARACTER_SIZE == CHARACTER_SIZE_8
	SET_BIT(UCSRC_REG, UCSZ0_BIT);
	SET_BIT(UCSRC_REG, UCSZ1_BIT);
	CLR_BIT(UCSRB_REG, UCSZ2_BIT);
#elif UART_CHARACTER_SIZE == CHARACTER_SIZE_9
	SET_BIT(UCSRC_REG, UCSZ0_BIT);
	SET_BIT(UCSRC_REG, UCSZ1_BIT);
	SET_BIT(UCSRB_REG, UCSZ2_BIT);
#endif

	// Choose Clock Polarity
#if USART_CLOCK_EDGE == UART_ASYNCHRONOUS
	CLR_BIT(UCSRC_REG, UCPOL_BIT);
#elif USART_CLOCK_EDGE == CLOCK_RISING_EDGE
	CLR_BIT(UCSRC_REG, UCPOL_BIT);
#elif USART_CLOCK_EDGE == CLOCK_FALLING_EDGE
	SET_BIT(UCSRC_REG, UCPOL_BIT);
#endif

	// Select the baud rate
	UBRRL_REG = (UART_Baud_Rate);
	UBRRH_REG = (UART_Baud_Rate>>8);

}

// This function is responsible for transmitting data
void UART_vTransmitData(u8 Copy_u8Data){

	// Wait until transmission register is empty // 0b 0010 0000
	while( !( UCSRA_REG & (1<<UDRE_BIT) ) );

	// Send data to UDR
	UDR_REG = Copy_u8Data;
}

// This function is responsible for receiving data
u8 UART_u8ReceiveData(){

	u8 LOCAL_u8Data;
	// Wait until data is received 0b 1000 0000
	while( !( UCSRA_REG & (1<<RXC_BIT) ) );

	// Receive data from UDR
	LOCAL_u8Data = UDR_REG;

	// Clear Flag
	CLR_BIT(UCSRA_REG, RXC_BIT);

	// Return data
	return LOCAL_u8Data;
}

void UART_vTransmitString(u8 *Copy_u8String)
{
	for(int i=0;Copy_u8String[i]!='\0';i++)
	{
		UART_vTransmitData(Copy_u8String[i]);
	}
}
