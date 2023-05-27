/*
 * uart_config.c
 *
 * Created: 24/05/2023 00:12:56
 *  Author: 20101
 */ 

#include "usart_cfg.h"
#include "../../COMMON/std_types.h"


const str_uart_instance_cfg_t uart_devices[1] = 
{
	{
		.enu_baud_rate_2x = UART_BR2X_9600,
		.enu_baud_rate_1x = UART_BR1X_9600,
		.enu_char_size = CHARACTER_SIZE_8_BIT,
		.enu_interrupt_status = ENABLE_INTERRUPT,
		.enu_operation_mode = ASYNCHRONOUS_OPERATION,
		.enu_parity_bit = PARITY_DISABLED,
		.enu_stop_bit = ONE_STOP_BIT,
		.enu_transmission_speed = SPEED_U1X,
 		.ptr_func_tx_callback = uart_send_n,
		.ptr_func_rx_callback = uart_recive
	}
};