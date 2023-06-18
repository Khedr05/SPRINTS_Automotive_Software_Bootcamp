
#include "led_interface.h"

void LED_initialize(const ST_led_pinCfg_t *led)
{
  
        Port_ConfigType  dio_pinCfg =
        {PORT_MODE_DIGITAL ,  led->led_status, PORT_PIN_DIRECTION_OUT ,
         PORT_PIN_PDR , PORT_PIN_OUTPUT_CURRENT_8MA ,
        led->portNumber , led->pinNumber};

        Port_Init(&dio_pinCfg);

     
    }
	


void LED_turnOn(const ST_led_pinCfg_t *led)
{
  
        
        Port_ConfigType  dio_pinCfg =
        {PORT_MODE_DIGITAL ,  led->led_status, PORT_PIN_DIRECTION_OUT ,
         PORT_PIN_PDR , PORT_PIN_OUTPUT_CURRENT_8MA ,
        led->portNumber , led->pinNumber,Port_pin};

        GPIO_Write(led->portNumber, led->pinNumber, PORT_PIN_LEVEL_HIGH);

   
}


void LED_turnOff(const ST_led_pinCfg_t *led)
{
  
    Port_ConfigType  dio_pinCfg =
        {PORT_MODE_DIGITAL ,  led->led_status, PORT_PIN_DIRECTION_OUT ,
         PORT_PIN_PDR , PORT_PIN_OUTPUT_CURRENT_8MA ,
        led->portNumber , led->pinNumber,Port_pin};

          GPIO_Write(led->portNumber, led->pinNumber, PORT_PIN_LEVEL_LOW);

}


void LED_toggle(const ST_led_pinCfg_t *led)
{
   
           Port_ConfigType  dio_pinCfg =
        {PORT_MODE_DIGITAL ,  led->led_status, PORT_PIN_DIRECTION_OUT ,
         PORT_PIN_PDR , PORT_PIN_OUTPUT_CURRENT_8MA ,
        led->portNumber , led->pinNumber,Port_pin};
         GPIO_Toggle(led->portNumber,led->pinNumber);


}

