/*
 * DIO_prog.c
 *
 *  Created on: 5 Apr 2023
 *      Author: 20101
 */

#include"DIO_interface.h"


#if GPIO_CONFIGURATIONS == CONFIG_ENABLE

volatile Uint8_t *ddr_registers[] = {&DDRA_REG,&DDRB_REG,&DDRC_REG,&DDRD_REG};
volatile Uint8_t *port_registers[] = {&PORTA_REG,&PORTB_REG,&PORTC_REG,&PORTD_REG};
volatile Uint8_t *pin_registers[] = {&PINA_REG,&PINB_REG,&PINC_REG,&PIND_REG};

Std_ReturnType GPIO_pin_direction_intialize(const ST_pin_config_t *_pin_config)
{
	Std_ReturnType ret = E_NOT_OK;

	    if(PTR_NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER)
	    {
	        ret = E_NOT_OK;
	    }
	    else
	    {
	        switch(_pin_config->direction)
	      {
	          case GPIO_DIRECTION_OUTPUT:
	          {
	              SET_BIT(*ddr_registers[_pin_config->port],_pin_config->pin);
	              ret = E_OK;
	              break;
	          }
	          case GPIO_DIRECTION_INPUT:
	          {
	              CLEAR_BIT(*ddr_registers[_pin_config->port],_pin_config->pin);
	              ret = E_OK;
	              break;
	          }
	          default : ret = E_NOT_OK ;
	      }
	    }

	    return ret;
}


Std_ReturnType GPIO_pin_get_direction_status(const ST_pin_config_t *_pin_config , EN_direction_t *direction_status)
{
    Std_ReturnType ret = E_NOT_OK;

    if(PTR_NULL == _pin_config || PTR_NULL == direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = GET_BIT(*ddr_registers[_pin_config->port],_pin_config->pin);
		ret = E_OK;
    }
    return ret;
}
Std_ReturnType GPIO_pin_write_logic(const ST_pin_config_t *_pin_config , EN_logic_t logic)
{
	 Std_ReturnType ret = E_NOT_OK;

	    if(PTR_NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER)
	    {
	        ret = E_NOT_OK;
	    }
	    else
	    {
	        switch(logic)
	        {
	            case GPIO_LOGIC_LOW:
	            {
	                CLEAR_BIT(*port_registers[_pin_config->port],_pin_config->pin);
	                ret = E_OK;
	                break;
	            }
	            case GPIO_LOGIC_HIGH:
	            {
	                SET_BIT(*port_registers[_pin_config->port],_pin_config->pin);
	                ret = E_OK;
	                break;
	            }
	            default : ret = E_NOT_OK;
	        }
	    }
	    return ret;

}
Std_ReturnType GPIO_pin_read_logic(const ST_pin_config_t *_pin_config , EN_logic_t *logic_status)
{
    Std_ReturnType ret = E_NOT_OK;

    if(PTR_NULL == _pin_config || PTR_NULL == logic_status || _pin_config->pin > PORT_PIN_MAX_NUMBER)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic_status = GET_BIT(*pin_registers[_pin_config->port],_pin_config->pin);
        ret = E_OK;
    }

    return ret;
}
Std_ReturnType GPIO_pin_toggle_logic(const ST_pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_NOT_OK;

    if(PTR_NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
       TOGGLE_BIT(*port_registers[_pin_config->port],_pin_config->pin);
       ret = E_OK;
    }

    return ret;
}
Std_ReturnType GPIO_pin_intialize(const ST_pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_NOT_OK;

    if(PTR_NULL == _pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
       ret = GPIO_pin_direction_intialize(_pin_config);
       ret = GPIO_pin_write_logic(_pin_config,_pin_config->logic);
    }
    return ret;
}




Std_ReturnType GPIO_port_direction_intialize(EN_port_index_t port , Uint8_t direction)
{
    Std_ReturnType ret = E_NOT_OK;
    if(port > PORT_MAX_NUMBER)
    {
      ret = E_NOT_OK;
    }
    else
    {
        *ddr_registers[port] = direction;
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType GPIO_port_get_direction_status(EN_port_index_t port , Uint8_t *direction_status)
{
    Std_ReturnType ret = E_NOT_OK;

    if(PTR_NULL == direction_status || port > PORT_MAX_NUMBER)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = *ddr_registers[port];
        ret = E_OK;
    }

    return ret;
}
Std_ReturnType GPIO_port_write_logic(EN_port_index_t port , Uint8_t logic)
{
    Std_ReturnType ret = E_NOT_OK;
    if(port > PORT_MAX_NUMBER)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *port_registers[port] = logic;
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType GPIO_port_read_logic(EN_port_index_t port , Uint8_t *logic_status)
{
    Std_ReturnType ret = E_NOT_OK;

    if(PTR_NULL == logic_status || port > PORT_MAX_NUMBER)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic_status = *pin_registers[port];
        ret = E_OK;
    }

    return ret;
}
Std_ReturnType GPIO_port_toggle_logic(EN_port_index_t port)
{
	   Std_ReturnType ret = E_NOT_OK;
	       if(port > PORT_MAX_NUMBER)
	    {
	        ret = E_NOT_OK;
	    }
	    else
	    {
	           *port_registers[port] ^= PORT_TOOGLE_MASK;
	           ret = E_OK;
	    }
	    return ret;
}

#endif

