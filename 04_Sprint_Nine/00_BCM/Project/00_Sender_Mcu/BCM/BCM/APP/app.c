

#include "app.h"




int main(void)
{
	enu_state_machine_flow lo_u8_main_state = INIT;
	enu_bcm_states_code_t ret = BCM_NOK;
	while(1)
	{
		switch(lo_u8_main_state)
		{
			
			case INIT:
			{
				bcm_init(&medium_cfg[0]);
				LED_initialize(&led0);
				LED_initialize(&led1);
				bcm_send(&medium_cfg[0],str_send_buffer);
				lo_u8_main_state = IDLE;
				break;
			}
			case IDLE :
			{
				ret = bcm_dispatcher();
				if(ret == ALL_BYTES_SENDED)
				{
					lo_u8_main_state = SENDING;
				}
				else if(ret == ALL_BYTES_RECVIED)
				{
					lo_u8_main_state = RCIVEING;
				}
				break;
			}
			case SENDING:
			{
				LED_toggle(&led0);
				lo_u8_main_state = IDLE;
				break;
			}
			case RCIVEING:
			{
				LED_toggle(&led1);
				lo_u8_main_state = IDLE;
				break;
			}
		}
	}
}





















