

#include "../MCAL/usart/usart_interface.h"
#include "../MCAL/mcu_cfg/MCU_Interface.h"
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


int main(void)
{
		bcm_init(&medium_cfg[0]);
		LED_initialize(&led0);
		LED_initialize(&led1);
		enu_bcm_states_code_t ret = BCM_NOK;
		bcm_send(&medium_cfg[0],str_send_buffer);
	while(1)
	{
			ret = bcm_dispatcher();
			if(ret == ALL_BYTES_SENDED)
			{
				LED_toggle(&led0);
			}
			else if(ret == ALL_BYTES_RECVIED)
			{
				LED_toggle(&led1);
			}
	}
	return 0;
}





















