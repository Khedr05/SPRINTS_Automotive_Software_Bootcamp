/*
 * app.h
 *
 * Created: 27/05/2023 04:04:11
 *  Author: 20101
 */ 


#ifndef APP_H_
#define APP_H_


#include "../COMMON/std_types.h"
#include "../SERVICES/bcm/bcm_interface.h"
#include "../ECUAL/led/LED_interface.h"

#define F_CPU 8000000UL


extern const str_bcm_instance_t medium_cfg[1];
extern Uchar8_t str_send_buffer[SEND_BUFFER_MAX_SIZE];


ST_led_t led0 =
{
	.led_status = LED_STATUS_OFF,
	.pin = GPIO_PIN5,
	.port_name = GPIO_PORTA_INDEX
};
ST_led_t led1 =
{
	.led_status = LED_STATUS_OFF,
	.pin = GPIO_PIN6,
	.port_name = GPIO_PORTA_INDEX
};


typedef enum 
{
	IDLE,
	INIT,
	SENDING,
	RCIVEING
}enu_state_machine_flow;


#endif /* APP_H_ */