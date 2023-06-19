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





Port_ErrorCode Port_Init( Port_ConfigType* ConfigPtr)
{
		Port_ErrorCode error=PORT_OK;
	   if (ConfigPtr == NULL) {
        error= PORT_ERROR; // Return the error code for invalid parameters
    }
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
					 error= PORT_INVALID_PARAM;
				 }
	if (PORT_PIN_OUTPUT_CURRENT_2MA == ConfigPtr[u8_Pin_Counter].PortPinOutputCurrent)
{
    SET_BIT(GPIO_DR2R_REG(port_num), pin_num);
}
else if (PORT_PIN_OUTPUT_CURRENT_4MA == ConfigPtr[u8_Pin_Counter].PortPinOutputCurrent)
{
    SET_BIT(GPIO_DR4R_REG(port_num), pin_num);
}
else if (PORT_PIN_OUTPUT_CURRENT_8MA == ConfigPtr[u8_Pin_Counter].PortPinOutputCurrent)
{
    SET_BIT(GPIO_DR8R_REG(port_num), pin_num);
}
else
{
    // Invalid output current
   error= PORT_INVALID_PARAM;
}
				 
		}
		if (PORT_MODE_DIGITAL == ConfigPtr[u8_Pin_Counter].PortPinMode)
{
    SET_BIT(GPIO_DEN_REG(port_num), pin_num);
    CLR_BIT(GPIO_AFSEL_REG(port_num), pin_num);
    CLR_BIT(GPIO_AMSEL_REG(port_num), pin_num);
}
else if (PORT_MODE_ANALOG == ConfigPtr[u8_Pin_Counter].PortPinMode)
{
    CLR_BIT(GPIO_DEN_REG(port_num), pin_num);
    CLR_BIT(GPIO_AFSEL_REG(port_num), pin_num);
    SET_BIT(GPIO_AMSEL_REG(port_num), pin_num);
}
else if (PORT_MODE_ALTERNATE == ConfigPtr[u8_Pin_Counter].PortPinMode)
{
    CLR_BIT(GPIO_DEN_REG(port_num), pin_num);
    SET_BIT(GPIO_AFSEL_REG(port_num), pin_num);
    CLR_BIT(GPIO_AMSEL_REG(port_num), pin_num);
}
else
{
    // Invalid port pin mode
    error= PORT_INVALID_PARAM;
}
					if (PORT_PIN_PUR == ConfigPtr[u8_Pin_Counter].PortPinInternalAttach)
{
    SET_BIT(GPIO_PUR_REG(port_num), pin_num);
}
else if (PORT_PIN_PDR == ConfigPtr[u8_Pin_Counter].PortPinInternalAttach)
{
    SET_BIT(GPIO_PDR_REG(port_num), pin_num);
}
else if (PORT_PIN_ODR == ConfigPtr[u8_Pin_Counter].PortPinInternalAttach)
{
    SET_BIT(GPIO_ODR_REG(port_num), pin_num);
}
else
{
    // Invalid port pin internal attachment
 error= PORT_INVALID_PARAM;
}
		if(Port_Int==ConfigPtr[u8_Pin_Counter].PortIntPin)
		{if (IntSense_Edges == ConfigPtr[u8_Pin_Counter].PortIntSense)
{
    CLR_BIT(GPIO_IS_REG(port_num), pin_num);
}
else if (IntSense_Levels == ConfigPtr[u8_Pin_Counter].PortIntSense)
{
    SET_BIT(GPIO_IS_REG(port_num), pin_num);
}
else
{
    // Invalid interrupt sense
    return PORT_INVALID_PARAM;
}
				if (IntEvent_Falling == ConfigPtr[u8_Pin_Counter].PortIntEvent)
{
    CLR_BIT(GPIO_IEV_REG(port_num), pin_num);
}
else if (IntEvent_Rising == ConfigPtr[u8_Pin_Counter].PortIntEvent)
{
    SET_BIT(GPIO_IEV_REG(port_num), pin_num);
}
else if (IntEvent_Both == ConfigPtr[u8_Pin_Counter].PortIntEvent)
{
    SET_BIT(GPIO_IBE_REG(port_num), pin_num);
}
else
{
    // Invalid interrupt event
   error= PORT_INVALID_PARAM;
}
if (IntEvent_Masked == ConfigPtr[u8_Pin_Counter].PortIntMask)
{
    CLR_BIT(GPIO_IM_REG(port_num), pin_num);
}
else if (IntEvent_UnMaske == ConfigPtr[u8_Pin_Counter].PortIntMask)
{
    SET_BIT(GPIO_IM_REG(port_num), pin_num);
}
else
{
    // Invalid interrupt mask
    error= PORT_INVALID_PARAM;
}
				
		
		}
		
		
	}
return error;
}

Port_ErrorCode GPIO_Write(Port_Num port_num, Port_PinNum pin_num, uint8_t value)
{
	Port_ErrorCode error=PORT_OK;
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
	 error= PORT_INVALID_PARAM;
				 }				 
return error;
}
Port_ErrorCode GPIO_Read(Port_Num port_num, Port_PinNum pin_num,Port_PinLevel *value)
{	
	Port_ErrorCode error=PORT_OK;
if(port_num >6 ||pin_num> 7)
{
		 error= PORT_INVALID_PARAM;

}else
{
 
	*value= (GET_BIT(GPIO_DATA_REG(port_num), pin_num) != 0) ? 1 : 0;
}
	return error;
}

Port_ErrorCode GPIO_Toggle(Port_Num port_num, Port_PinNum pin_num)
{
		Port_ErrorCode error=PORT_OK;
if(port_num >6 ||pin_num> 7)
{
		 error= PORT_INVALID_PARAM;

}else
{
    TGL_BIT(GPIO_DATA_REG(port_num), pin_num);
}
	return error;
}
Port_ErrorCode GPIO_Enable_Interrupt(Port_Num port_num,Port_PinNum port_pinnum)
{
			Port_ErrorCode error=PORT_OK;

	SET_BIT(GPIO_IM_REG(port_num),port_pinnum);
	  NVIC_EnableIRQ(GPIOF_IRQn);
				__enable_irq();
	
	return error;

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