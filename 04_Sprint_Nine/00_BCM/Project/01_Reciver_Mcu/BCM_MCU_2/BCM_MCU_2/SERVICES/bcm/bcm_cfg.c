/*
 * bcm_cfg.c
 *
 * Created: 25/05/2023 17:04:21
 *  Author: 20101
 */ 

#include "bcm_cfg.h"


str_bcm_instance_t medium_cfg[1] = 
{
	{
		.uart_device_index = 0,
		.ptr_func_initMedium = uart_init,
		.ptr_func_send_byte = uart_send,
		.ptr_func_deinitMdeium = uart_deinit
	}
};