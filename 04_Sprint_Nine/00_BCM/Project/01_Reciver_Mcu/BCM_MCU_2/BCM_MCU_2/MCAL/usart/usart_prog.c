/*
 * usart_prog.c
 *
 * Created: 23/05/2023 21:22:46
 *  Author: 20101
 */ 

#include "usart_interface.h"

static enu_uart_error_status_t (*ptr_func_rx_callback)(Uchar8_t *data_to_send , Uint16_t data_length) = PTR_NULL;
static enu_uart_error_status_t(*set_tx_callback_handllar)(Uchar8_t *data_to_send , Uint16_t data_length) = PTR_NULL;

Uint16_t vu16_g_recive_counter = 0;
Uint16_t vu16_g_send_counter = 1;
extern Uchar8_t str_send_buffer[SEND_BUFFER_MAX_SIZE];
extern Uchar8_t str_recive_buffer[RECIVE_BUFFER_MAX_SIZE];
Uchar8_t str_len = 0;
Uchar8_t gl_u8_send_end_flag = 0;
Uchar8_t gl_u8_recive_end_flag = 0;
static void uart_rx_set_callback_handler(enu_uart_error_status_t(*rxhandler)(Uchar8_t *data_to_send , Uint16_t data_length))
{
	if( PTR_NULL == rxhandler)
	{
		
	}
	else
	{
		ptr_func_rx_callback = rxhandler;
	}
}

static void uart_tx_set_callback_handler(enu_uart_error_status_t(*txhandler)(Uchar8_t *data_to_send , Uint16_t data_length))
{
	if( PTR_NULL == txhandler)
	{
	}
	else
	{
		set_tx_callback_handllar = txhandler;
	}
}

static void uart_enable(void)
{
	SET_BIT(UCSRB_REG,UCSRB_REG_RXEN_BIT);
	SET_BIT(UCSRB_REG,UCSRB_REG_TXEN_BIT);
}

enu_uart_error_status_t uart_init(const str_uart_instance_cfg_t *ptr_str_instance)
{
	enu_uart_error_status_t ret = UART_INIT_NOK;
	uart_enable();
  if(PTR_NULL != ptr_str_instance)
  {
	  switch(ptr_str_instance->enu_operation_mode)
	  {
		  case ASYNCHRONOUS_OPERATION :
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			  CLEAR_BIT(UCSRC_REG,UCSRC_REG_UMSEL_BIT);
			  break;
		  }
		  case SYNCHRONOUS_OPERATION :
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			  SET_BIT(UCSRC_REG,UCSRC_REG_UMSEL_BIT);
			  break;
		  }
	  }
	  
	  switch(ptr_str_instance->enu_parity_bit)
	  {
		  case PARITY_DISABLED:
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			  CLEAR_BIT(UCSRC_REG,UCSRC_REG_UPM0_BIT);
			  CLEAR_BIT(UCSRC_REG,UCSRC_REG_UPM1_BIT);
			  break;
		  }
		  case PARITY_ENABLED_EVEN :
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_UPM1_BIT);
			  CLEAR_BIT(UCSRC_REG,UCSRC_REG_UPM0_BIT);			  
			  break;
		  }
		  case PARITY_ENABLED_ODD :
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			  SET_BIT(UCSRC_REG,UCSRC_REG_UPM0_BIT);
			  SET_BIT(UCSRC_REG,UCSRC_REG_UPM1_BIT);			
			break;  
		  }
	  }
	  
	  switch(ptr_str_instance->enu_stop_bit)
	  {
		  case ONE_STOP_BIT:
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			  CLEAR_BIT(UCSRC_REG,UCSRC_REG_USBS_BIT);
			  break;
		  }
		  case TWO_STOP_BIT:
		  {
			  SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			  SET_BIT(UCSRC_REG,UCSRC_REG_USBS_BIT);			  
			  break;
		  }
	  }
	  
	  switch(ptr_str_instance->enu_char_size)
	  {
		  case CHARACTER_SIZE_5_BIT :
		  {
			 CLEAR_BIT(UCSRB_REG,UCSRB_REG_UCSZ2_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			 CLEAR_BIT(UCSRC_REG,UCSRC_REG_UCSZ0_BIT);
			 CLEAR_BIT(UCSRC_REG,UCSRC_REG_UCSZ1_BIT);
			 break;
		  }
		  case CHARACTER_SIZE_6_BIT :
		  {
			 CLEAR_BIT(UCSRB_REG,UCSRB_REG_UCSZ2_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			 CLEAR_BIT(UCSRC_REG,UCSRC_REG_UCSZ0_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_UCSZ1_BIT);  
			  break;
		  }
		  case CHARACTER_SIZE_7_BIT :
		  {
			 CLEAR_BIT(UCSRB_REG,UCSRB_REG_UCSZ2_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_UCSZ0_BIT);
			 CLEAR_BIT(UCSRC_REG,UCSRC_REG_UCSZ1_BIT);
			  break;
		  }
		  case CHARACTER_SIZE_8_BIT :
		  {
			 CLEAR_BIT(UCSRB_REG,UCSRB_REG_UCSZ2_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_UCSZ0_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_UCSZ1_BIT); 
			  break;
		  }
		  case CHARACTER_SIZE_9_BIT :
		  {
			 SET_BIT(UCSRB_REG,UCSRB_REG_UCSZ2_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_UCSZ0_BIT);
			 SET_BIT(UCSRC_REG,UCSRC_REG_UCSZ1_BIT); 
			  break;
		  }		  		  		  		  
	  }
	  switch(ptr_str_instance->enu_interrupt_status)
	  {
		  case ENABLE_INTERRUPT:
		  {
			SET_BIT(UCSRB_REG , UCSRB_REG_RXCIE_BIT);
			SET_BIT(UCSRB_REG , UCSRB_REG_TXCIE_BIT);
			//SET_BIT(UCSRB_REG , UCSRB_REG_UDRIE_BIT);
			break;  
		  }
		  case DISABLE_INTERRUPT :
		  {
			CLEAR_BIT(UCSRB_REG , UCSRB_REG_RXCIE_BIT);
			CLEAR_BIT(UCSRB_REG , UCSRB_REG_TXCIE_BIT); 
			//CLEAR_BIT(UCSRB_REG , UCSRB_REG_UDRIE_BIT);
			break;
		  }
	  }
	  switch(ptr_str_instance->enu_transmission_speed)
	  {
		  case  SPEED_U1X:
		  {
			  CLEAR_BIT(UCSRA_REG,UCSRA_REG_U2X_BIT);
			  //CLEAR_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
 			  UBRRL_REG = ptr_str_instance->enu_baud_rate_1x;
 			  UBRRH_REG = ((ptr_str_instance->enu_baud_rate_1x)>>8);
			  break;
		  }
		  case  SPEED_U2X:
		  {
			  SET_BIT(UCSRA_REG,UCSRA_REG_U2X_BIT);
			  //CLEAR_BIT(UCSRC_REG,UCSRC_REG_URSEL_BIT);
 			  UBRRL_REG = ptr_str_instance->enu_baud_rate_2x;
 			  UBRRH_REG = ((ptr_str_instance->enu_baud_rate_2x)>>8);
			  break;
		  }
	  }
	    uart_rx_set_callback_handler(ptr_str_instance->ptr_func_rx_callback);
	    uart_tx_set_callback_handler(ptr_str_instance->ptr_func_tx_callback);
	    MCU_vEnableInterrupt();
	  ret = UART_INIT_OK;
  }
  else
  {
	  ret  = UART_NULL_PTR;
  }
  return ret;
}

void uart_deinit(void)
{
	CLEAR_BIT(UCSRB_REG,UCSRB_REG_RXEN_BIT);
	CLEAR_BIT(UCSRB_REG,UCSRB_REG_TXEN_BIT);
}



Uchar8_t u8_g_isr_flag = 0;
void uart_send(Uchar8_t *data_to_send)
{
	u8_g_isr_flag = 0;
	UDR_REG = data_to_send[0];
}

enu_uart_error_status_t uart_recive(Uchar8_t *data_to_send , Uint16_t data_length)
{
		enu_uart_error_status_t ret = UART_RECIVE_NOK;
		if(vu16_g_recive_counter < data_length )
		{
			data_to_send[vu16_g_recive_counter] = UDR_REG;
			vu16_g_recive_counter++;
		}
		else
		{
			gl_u8_recive_end_flag = 1;
			vu16_g_recive_counter = 0;
			ret = UART_RECIVE_OK;
		}
		return ret;
}

enu_uart_error_status_t uart_send_n(Uchar8_t *data_to_send , Uint16_t data_length)
{		enu_uart_error_status_t ret = UART_SEND_NOK;	
		if(vu16_g_send_counter < data_length )
		{
			UDR_REG = data_to_send[vu16_g_send_counter];
			vu16_g_send_counter++;
		}
		else
		{
			vu16_g_send_counter = 0;
			gl_u8_send_end_flag = 1;
			ret = UART_SEND_OK;
		}
		return ret;
}

ISR (USART_RXC_INT)
{
	ptr_func_rx_callback(str_recive_buffer,RECIVE_BUFFER_MAX_SIZE);	
}

ISR(USART_TXC_INT)
{
	set_tx_callback_handllar(str_send_buffer,SEND_BUFFER_MAX_SIZE);
}
 