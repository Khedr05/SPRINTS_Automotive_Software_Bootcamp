/*
 * bcm_cfg.h
 *
 * Created: 25/05/2023 17:07:29
 *  Author: 20101
 */ 


#ifndef BCM_CFG_H_
#define BCM_CFG_H_

#include "../../MCAL/usart/usart_interface.h"

extern const str_uart_instance_cfg_t uart_devices[1];
extern enu_uart_error_status_t uart_init(const str_uart_instance_cfg_t *ptr_str_instance);
extern void uart_send(Uchar8_t *data_to_send);
void uart_deinit(void);


typedef enum
{
	
	BCM_NOK = 0,
	BCM_OK,
	BCM_NULL_POINTER,
	INVALID_SEND_DATA,
	INVALID_NUMBER_OF_BYTES,
	ALL_BYTES_SENDED,
	ALL_BYTES_RECVIED
		
}enu_bcm_states_code_t;

typedef enum
{
	UART_COMMUNCATION_PROTOCOL = 0
}enu_communcation_protocol_type_t;

typedef enum
{
	BCM_STATE_INTILIAZE = 0,
	BCM_STATE_DEINITIALZE,
	BCM_STATE_SENDING
}str_bcm_instance_state_t;

typedef struct  
{
	Uchar8_t uart_device_index;
	enu_uart_error_status_t(*ptr_func_initMedium)(const str_uart_instance_cfg_t *ptr_str_instance);
	void (*ptr_func_send_byte)(Uchar8_t *data_to_send);
	void(*ptr_func_deinitMdeium)(void);
	 	
}str_bcm_instance_t;



#endif /* BCM_CFG_H_ */