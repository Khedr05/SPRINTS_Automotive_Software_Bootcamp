/*
* usart_cfg.h
*
* Created: 23/05/2023 21:23:36
*  Author: 20101
*/


#ifndef USART_CFG_H_
#define USART_CFG_H_

#include "../../COMMON/std_types.h"

#define SEND_BUFFER_MAX_SIZE		23
#define RECIVE_BUFFER_MAX_SIZE		14

extern	void txc(void);
typedef enum
{
	ONE_STOP_BIT = 0,
	TWO_STOP_BIT
}enu_stop_bit_cfg_t;


typedef enum
{
	PARITY_DISABLED = 0,
	PARITY_ENABLED_EVEN,
	PARITY_ENABLED_ODD
}enu_parity_bit_cfg_t;

typedef enum
{
	ASYNCHRONOUS_OPERATION = 0,
	SYNCHRONOUS_OPERATION
}enu_operation_mode_cfg_t;

typedef enum
{
	CHARACTER_SIZE_5_BIT = 0,
	CHARACTER_SIZE_6_BIT,
	CHARACTER_SIZE_7_BIT,
	CHARACTER_SIZE_8_BIT,
	CHARACTER_SIZE_9_BIT
}enu_character_size_cfg_t;

typedef enum
{
	ENABLE_INTERRUPT = 0,
	DISABLE_INTERRUPT
}enu_interrupt_cfg_t;

typedef enum
{
	SPEED_U1X = 0,
	SPEED_U2X
}enu_transmission_speed_cfg_t;


typedef enum
{
	UART_BR1X_2400 = 207,
	UART_BR1X_4800 = 103,
	UART_BR1X_9600 = 51,
	UART_BR1X_38400 = 12
}enu_baud_rate_speed_u1x_cfg_t;

typedef enum{
	UART_BR2X_2400 = 416,
	UART_BR2X_4800 = 207,
	UART_BR2X_9600 = 103,
	UART_BR2X_38400 = 25
}enu_baud_rate_speed_u2x_cfg_t;


typedef enum
{
	UART_INIT_OK = 0,
	UART_INIT_NOK,
	UART_SEND_OK,
	UART_SEND_NOK,
	UART_RECIVE_OK,
	UART_RECIVE_NOK,
	UART_NULL_PTR,
	UART_HANDLLER_SET_OK
}enu_uart_error_status_t;

extern enu_uart_error_status_t uart_recive(Uchar8_t *data_to_send , Uint16_t data_length);
extern enu_uart_error_status_t uart_send_n(Uchar8_t *data_to_send , Uint16_t data_length);


typedef struct  
{
	enu_operation_mode_cfg_t			enu_operation_mode;
	enu_parity_bit_cfg_t				enu_parity_bit;
	enu_stop_bit_cfg_t					enu_stop_bit;
	enu_character_size_cfg_t			enu_char_size;
	enu_interrupt_cfg_t					enu_interrupt_status;
	enu_transmission_speed_cfg_t		enu_transmission_speed;
	enu_baud_rate_speed_u1x_cfg_t		enu_baud_rate_1x;
	enu_baud_rate_speed_u2x_cfg_t		enu_baud_rate_2x;
	enu_uart_error_status_t(*ptr_func_tx_callback)(Uchar8_t *data_to_send , Uint16_t data_length);
	enu_uart_error_status_t (*ptr_func_rx_callback)(Uchar8_t *data_to_send , Uint16_t data_length);

	
}str_uart_instance_cfg_t;

#endif /* USART_CFG_H_ */