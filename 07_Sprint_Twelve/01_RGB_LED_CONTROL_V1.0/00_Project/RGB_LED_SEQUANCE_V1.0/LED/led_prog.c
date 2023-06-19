
#include "led_interface.h"

ENU_LED_systemState_t LED_initialize(const ST_led_pinCfg_t *led)
{
	ENU_LED_systemState_t error;
  
        Port_ConfigType  dio_pinCfg =
        {PORT_MODE_DIGITAL ,  led->led_status, PORT_PIN_DIRECTION_OUT ,
         PORT_PIN_PDR , PORT_PIN_OUTPUT_CURRENT_8MA ,
        led->portNumber , led->pinNumber};

        Port_Init(&dio_pinCfg);
 if (Port_Init(&dio_pinCfg) != PORT_OK) {
        error= LED_INIT_NOK;
    }

    error= LED_INIT_OK;
      return error;
    }
	

ENU_LED_systemState_t LED_turnOn(const ST_led_pinCfg_t *led)
{
	ENU_LED_systemState_t led_error;
    Port_ErrorCode error = GPIO_Write(led->portNumber, led->pinNumber, PORT_PIN_LEVEL_HIGH);
    
    if (error == PORT_OK)
    {
        led_error= LED_INIT_OK;
    }
    else
    {
        led_error= LED_INIT_NOK;
    }
		return led_error;
}
ENU_LED_systemState_t LED_turnOff(const ST_led_pinCfg_t *led)
{
    ENU_LED_systemState_t led_error;
    Port_ErrorCode error = GPIO_Write(led->portNumber, led->pinNumber, PORT_PIN_LEVEL_LOW);

    if (error == PORT_OK)
    {
        led_error = LED_INIT_OK;
    }
    else
    {
        led_error = LED_INIT_NOK;
    }

    return led_error;
}


ENU_LED_systemState_t LED_toggle(const ST_led_pinCfg_t *led)
{
    ENU_LED_systemState_t led_error;
    GPIO_Toggle(led->portNumber, led->pinNumber);
    led_error = LED_INIT_OK;

    return led_error;
}
