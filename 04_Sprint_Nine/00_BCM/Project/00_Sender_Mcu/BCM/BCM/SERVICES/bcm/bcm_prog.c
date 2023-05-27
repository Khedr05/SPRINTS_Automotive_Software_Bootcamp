/*
 * bcm_prog.c
 *
 * Created: 25/05/2023 16:59:06
 *  Author: 20101
 */ 

#include "bcm_interface.h"

extern Uchar8_t gl_u8_send_end_flag;
extern Uchar8_t gl_u8_recive_end_flag;

extern const str_bcm_instance_t medium_cfg[1];
extern VUint16_t vu16_g_recive_counter;
Uchar8_t str_send_buffer[SEND_BUFFER_MAX_SIZE] = "[BCM Operating]";
Uchar8_t str_recive_buffer[RECIVE_BUFFER_MAX_SIZE];


Uchar8_t gl_u8_first_dispatcher_time = 0;

static enu_uart_error_status_t(*ptr_func_init)(const str_uart_instance_cfg_t *ptr_str_instance);



static enu_uart_error_status_t set_init_callback(enu_uart_error_status_t(*ptr_func_handelr)(const str_uart_instance_cfg_t *ptr_str_instance))
{
	ptr_func_init = ptr_func_handelr;
	return UART_HANDLLER_SET_OK;
}




enu_bcm_states_code_t bcm_init(const str_bcm_instance_t * ptr_str_bcm_instance)
{
	enu_bcm_states_code_t ret = BCM_NOK; 
	if(PTR_NULL != ptr_str_bcm_instance)
	{
		set_init_callback(ptr_str_bcm_instance->ptr_func_initMedium);
		ptr_func_init(&uart_devices[ptr_str_bcm_instance->uart_device_index]);
		ret = BCM_OK;
	}
	else
	{
		ret = BCM_NULL_POINTER;
	}
	return ret;
}

enu_bcm_states_code_t bcm_send(const str_bcm_instance_t * ptr_str_bcm_instance , Uchar8_t *copy_ptr_u8_data_to_send)
{
	ptr_str_bcm_instance->ptr_func_send_byte(copy_ptr_u8_data_to_send);
	return BCM_OK;
}

enu_bcm_states_code_t bcm_deinit(const str_bcm_instance_t * ptr_str_bcm_instance)
{
	ptr_str_bcm_instance->ptr_func_deinitMdeium();
	return BCM_OK;
}

enu_bcm_states_code_t bcm_dispatcher()
{
	enu_bcm_states_code_t ret = BCM_NOK;
	if(gl_u8_send_end_flag == 1)
	{
		ret = ALL_BYTES_SENDED;
		gl_u8_send_end_flag = 0;
	}
	if(gl_u8_recive_end_flag == 1)
	{
		ret = ALL_BYTES_RECVIED;
		gl_u8_recive_end_flag = 0;
	}
	return ret;
}


