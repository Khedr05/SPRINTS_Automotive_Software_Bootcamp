/*
 * usart_interface.h
 *
 * Created: 23/05/2023 21:23:20
 *  Author: 20101
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "../../COMMON/vect_table.h"
#include "usart_private.h"
#include "usart_cfg.h"
#include "../MCU_CFG/MCU_Interface.h"


enu_uart_error_status_t uart_init(const str_uart_instance_cfg_t *ptr_str_instance);
enu_uart_error_status_t uart_send_n(Uchar8_t *data_to_send , Uint16_t data_length);
enu_uart_error_status_t uart_recive(Uchar8_t *data_to_send , Uint16_t data_length);
void uart_send(Uchar8_t *data_to_send);
void uart_deinit(void);






#endif /* USART_INTERFACE_H_ */