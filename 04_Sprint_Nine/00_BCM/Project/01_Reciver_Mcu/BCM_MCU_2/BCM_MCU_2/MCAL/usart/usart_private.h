/*
 * usart_private.h
 *
 * Created: 23/05/2023 21:23:51
 *  Author: 20101
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define UDR_REG			*((VUchar8_t *)0x2C)
#define UCSRA_REG		*((VUchar8_t *)0x2B)
#define UCSRB_REG		*((VUchar8_t *)0x2A)
#define UCSRC_REG		*((VUchar8_t *)0x40)
#define UBRRL_REG		*((VUchar8_t *)0x29)
#define UBRRH_REG		*((VUchar8_t *)0x40)



typedef enum
{
	UCSRA_REG_MPCM_BIT = 0,
	UCSRA_REG_U2X_BIT,
	UCSRA_REG_PE_BIT,
	UCSRA_REG_DOR_BIT,
	UCSRA_REG_FE_BIT,
	UCSRA_REG_UDRE_BIT,
	UCSRA_REG_TXC_BIT,
	UCSRA_REG_RXC_BIT
}enu_ucsra_reg_bits;


typedef enum
{

	UCSRB_REG_TXB8_BIT = 0,
	UCSRB_REG_RXB8_BIT,
	UCSRB_REG_UCSZ2_BIT,
	UCSRB_REG_TXEN_BIT,
	UCSRB_REG_RXEN_BIT,
	UCSRB_REG_UDRIE_BIT,
	UCSRB_REG_TXCIE_BIT,
	UCSRB_REG_RXCIE_BIT,	
	
}enu_ucsrb_reg_bits;


typedef enum
{
	UCSRC_REG_UCPOL_BIT = 0,
	UCSRC_REG_UCSZ0_BIT,
	UCSRC_REG_UCSZ1_BIT,
	UCSRC_REG_USBS_BIT,
	UCSRC_REG_UPM0_BIT,
	UCSRC_REG_UPM1_BIT,
	UCSRC_REG_UMSEL_BIT,
	UCSRC_REG_URSEL_BIT,
		
}enu_ucsrc_reg_bits;



#endif /* USART_PRIVATE_H_ */