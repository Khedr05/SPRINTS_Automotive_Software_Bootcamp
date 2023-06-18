
#include "BUTTON_interface.h"


void PUSH_BTN_intialize(const ST_PUSH_BTN_pinCfg_t *btn)
{
  Port_ConfigType  STR_PortsConfig =
           {PORT_MODE_DIGITAL , PORT_PIN_LEVEL_LOW , PORT_PIN_DIRECTION_IN , btn->pushBtnConnection,
             PORT_PIN_OUTPUT_CURRENT_4MA ,btn->portNumber, btn->pinNumber,
            Port_pin };

           Port_Init(&STR_PortsConfig);

         
}


void	PUSH_BTN_read_state(const ST_PUSH_BTN_pinCfg_t *btn , ENU_PUSH_BTN_state_t *btn_state)
{
   


        Port_PinLevel btnLogic;

        Port_ConfigType  dio_pinCfg =
         {PORT_MODE_DIGITAL , PORT_PIN_LEVEL_LOW , PORT_PIN_DIRECTION_IN , btn->pushBtnConnection,
             PORT_PIN_OUTPUT_CURRENT_4MA ,btn->portNumber, btn->pinNumber,
            Port_pin };

         GPIO_Read(btn->portNumber, btn->pinNumber,&btnLogic);

        if(PORT_PIN_PUR == btn->pushBtnConnection)
        {
            if(PORT_PIN_LEVEL_HIGH == btnLogic)
            {
                *btn_state = PUSH_BTN_STATE_RELEASED;
            }
            else
            {
                *btn_state = PUSH_BTN_STATE_PRESSED;
            }

        }
        else if(PORT_PIN_PDR == btn->pushBtnConnection)
        {
            if(PORT_PIN_LEVEL_HIGH == btnLogic)
            {
                *btn_state = PUSH_BTN_STATE_PRESSED;
            }
            else
            {
                *btn_state = PUSH_BTN_STATE_RELEASED;
            }
        }
      
    }



