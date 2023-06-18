#include "port.h"

 InterruptHandler interruptHandlers[6][8] = {
    /* PORTA */
    {
        NULL,  // PIN_0
        NULL,  // PIN_1
        NULL,  // PIN_2
        NULL,  // PIN_3
        NULL,  // PIN_4
        NULL,  // PIN_5
        NULL,  // PIN_6
        NULL   // PIN_7
    },
    /* PORTB */
    {
        NULL,  // PIN_0
        NULL,  // PIN_1
        NULL,  // PIN_2
        NULL,  // PIN_3
        NULL,  // PIN_4
        NULL,  // PIN_5
        NULL,  // PIN_6
        NULL   // PIN_7
    },
    /* PORTC */
    {
        NULL,  // PIN_0
        NULL,  // PIN_1
        NULL,  // PIN_2
        NULL,  // PIN_3
        NULL,  // PIN_4
        NULL,  // PIN_5
        NULL,  // PIN_6
        NULL   // PIN_7
    },
    /* PORTD */
    {
        NULL,  // PIN_0
        NULL,  // PIN_1
        NULL,  // PIN_2
        NULL,  // PIN_3
        NULL,  // PIN_4
        NULL,  // PIN_5
        NULL,  // PIN_6
        NULL   // PIN_7
    },
    /* PORTE */
    {
        NULL,  // PIN_0
        NULL,  // PIN_1
        NULL,  // PIN_2
        NULL,  // PIN_3
        NULL,  // PIN_4
        NULL,  // PIN_5
        NULL,  // PIN_6
        NULL   // PIN_7
    },
    /* PORTF */
    {
        NULL,  // PIN_0
        NULL,  // PIN_1
        NULL,  // PIN_2
        NULL,  // PIN_3
        NULL,  // PIN_4
    }
};





void Port_Init( Port_ConfigType* ConfigPtr)
{
	uint8_t u8_Pin_Counter=0;
	for(u8_Pin_Counter=0;u8_Pin_Counter < PORT_PINS_NUMS;u8_Pin_Counter++)
	{
	Port_Num port_num =ConfigPtr[u8_Pin_Counter].PortNum;
	Port_PinNum pin_num =ConfigPtr[u8_Pin_Counter].PortPinNum;
		/* TODO:initiate the clock mention in DataSheet, p340 */
SET_BIT(RCGCGPIO,port_num);		
		if(PORT_PIN_DIRECTION_OUT==ConfigPtr[u8_Pin_Counter].PortPinDirection)
		{
		  SET_BIT(GPIO_DIR_REG(port_num),pin_num);
		
	  	if(PORT_PIN_LEVEL_HIGH==ConfigPtr[u8_Pin_Counter].PortPinLevelValue)
		     {
		     SET_BIT(GPIO_DATA_REG(port_num),pin_num);		    
				 }
			else if(PORT_PIN_LEVEL_LOW==ConfigPtr[u8_Pin_Counter].PortPinLevelValue)
	       {
         CLR_BIT(GPIO_DATA_REG(port_num),pin_num);
		     }
				 else
				 {
					 /*invalid*/
				 }
		switch(ConfigPtr[u8_Pin_Counter].PortPinOutputCurrent)
		{
			case PORT_PIN_OUTPUT_CURRENT_2MA:
				SET_BIT(GPIO_DR2R_REG(port_num),pin_num);
			break;
		
			case PORT_PIN_OUTPUT_CURRENT_4MA:
				SET_BIT(GPIO_DR4R_REG(port_num),pin_num);
			break;
		
			case PORT_PIN_OUTPUT_CURRENT_8MA:
				SET_BIT(GPIO_DR8R_REG(port_num),pin_num);
			break;
			default :
				break;
			
		}
				 
		}
			switch(ConfigPtr[u8_Pin_Counter].PortPinMode)
		{
			case PORT_MODE_DIGITAL:
				SET_BIT(GPIO_DEN_REG(port_num),pin_num);
			  CLR_BIT(GPIO_AFSEL_REG(port_num),pin_num);
			  CLR_BIT(GPIO_AMSEL_REG(port_num),pin_num);
			break;
		
			case PORT_MODE_ANALOG:
				CLR_BIT(GPIO_DEN_REG(port_num),pin_num);
			  CLR_BIT(GPIO_AFSEL_REG(port_num),pin_num);
			  SET_BIT(GPIO_AMSEL_REG(port_num),pin_num);
			break;
		
			case PORT_MODE_ALTERNATE:
				CLR_BIT(GPIO_DEN_REG(port_num),pin_num);
			  SET_BIT(GPIO_AFSEL_REG(port_num),pin_num);
			  CLR_BIT(GPIO_AMSEL_REG(port_num),pin_num);
			break;
			default :
				break;
			
		}
					switch(ConfigPtr[u8_Pin_Counter].PortPinInternalAttach)
		{
			case PORT_PIN_PUR:
				SET_BIT(GPIO_PUR_REG(port_num),pin_num);
		
			break;
		
			case PORT_PIN_PDR:
			
			  SET_BIT(GPIO_PDR_REG(port_num),pin_num);
			break;
		
			case PORT_PIN_ODR:
		
			  SET_BIT(GPIO_ODR_REG(port_num),pin_num);
			
			break;
			default :
				break;
			
		}
		if(Port_Int==ConfigPtr[u8_Pin_Counter].PortIntPin)
		{
			switch(ConfigPtr[u8_Pin_Counter].PortIntSense)
				{
				case IntSense_Edges:
			  CLR_BIT(GPIO_IS_REG(port_num),pin_num);
			break;
		
			case IntSense_Levels:
			
			  SET_BIT(GPIO_IS_REG(port_num),pin_num);
			break;
	     default :
				break;
		    }
				switch(ConfigPtr[u8_Pin_Counter].PortIntEvent)
		
				{
				case IntEvent_Falling:
			  CLR_BIT(GPIO_IEV_REG(port_num),pin_num);
			break;
				case IntEvent_Rising:
			  SET_BIT(GPIO_IEV_REG(port_num),pin_num);
			break;
		   	case IntEvent_Both:
			  SET_BIT(GPIO_IBE_REG(port_num),pin_num);
			break;
			
	     default :
				break;
		}
				switch(ConfigPtr[u8_Pin_Counter].PortIntMask)
				{
				case IntEvent_Masked:
			  CLR_BIT(GPIO_IM_REG(port_num),pin_num);
			break;
		
			case IntEvent_UnMaske:
			
			  SET_BIT(GPIO_IM_REG(port_num),pin_num);
			break;
	     default :
				break;
		    }
				
		
		}
		
		
	}

}

void GPIO_Write(Port_Num port_num, Port_PinNum pin_num, uint8_t value)
{
    if (value == PORT_PIN_LEVEL_HIGH)
    {
        SET_BIT(GPIO_DATA_REG(port_num), pin_num);
    }
    else if(value == PORT_PIN_LEVEL_LOW)
	       {
         CLR_BIT(GPIO_DATA_REG(port_num),pin_num);
		     }
				 else
				 {
					 /*invalid*/
				 }

}
void GPIO_Read(Port_Num port_num, Port_PinNum pin_num,Port_PinLevel *value)
{
    *value= (GET_BIT(GPIO_DATA_REG(port_num), pin_num) != 0) ? 1 : 0;
}

void GPIO_Toggle(Port_Num port_num, Port_PinNum pin_num)
{
    TGL_BIT(GPIO_DATA_REG(port_num), pin_num);
}
void GPIO_Enable_Interrupt(Port_Num port_num,Port_PinNum port_pinnum)
{
	SET_BIT(GPIO_IM_REG(port_num),port_pinnum);
	  NVIC_EnableIRQ(GPIOF_IRQn);
				__enable_irq();
	

	}


void GPIOA_Handler(void)
{
	 uint8_t x;
	for(x=0;x<5;x++)
	{

	if(GET_BIT(GPIO_RIS_REG(PORTA),x))
	{
 if(interruptHandlers[0][x]!=NULL)
    {
    				SET_BIT(GPIO_ICR_REG(5),x);
         interruptHandlers[0][x]();

		
      }

	}
}}

void GPIOB_Handler(void)
{
	 uint8_t x;
	for(x=0;x<5;x++)
	{

	if(GET_BIT(GPIO_RIS_REG(PORTF),x))
	{
 if(interruptHandlers[1][x]!=NULL)
    {
    				SET_BIT(GPIO_ICR_REG(1),x);
         interruptHandlers[1][x]();

		
      }

	}
}}

void GPIOC_Handler(void)
{
	 uint8_t x;
	for(x=0;x<5;x++)
	{

	if(GET_BIT(GPIO_RIS_REG(PORTF),x))
	{
 if(interruptHandlers[2][x]!=NULL)
    {
    				SET_BIT(GPIO_ICR_REG(2),x);
         interruptHandlers[2][x]();

		
      }

	}
}}

void GPIOD_Handler(void)
{
	 uint8_t x;
	for(x=0;x<5;x++)
	{

	if(GET_BIT(GPIO_RIS_REG(PORTF),x))
	{
 if(interruptHandlers[3][x]!=NULL)
    {
    				SET_BIT(GPIO_ICR_REG(3),x);
         interruptHandlers[3][x]();

		
      }

	}
}}

void GPIOE_Handler(void)
{
	 uint8_t x;
	for(x=0;x<5;x++)
	{

	if(GET_BIT(GPIO_RIS_REG(PORTF),x))
	{
 if(interruptHandlers[4][x]!=NULL)
    {
    				SET_BIT(GPIO_ICR_REG(4),x);
         interruptHandlers[4][x]();

		
      }

	}
}}