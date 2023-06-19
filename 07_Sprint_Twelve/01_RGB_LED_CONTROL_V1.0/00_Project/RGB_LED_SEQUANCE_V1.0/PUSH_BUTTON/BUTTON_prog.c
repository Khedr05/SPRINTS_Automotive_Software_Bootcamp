
#include "BUTTON_interface.h"

ENU_PUSH_BTN_systemState_t PUSH_BTN_intialize(const ST_PUSH_BTN_pinCfg_t *btn)
{
	ENU_PUSH_BTN_systemState_t error;
    Port_ConfigType STR_PortsConfig = {
        .PortPinMode = PORT_MODE_DIGITAL,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinDirection = PORT_PIN_DIRECTION_IN,
        .PortPinInternalAttach = btn->pushBtnConnection,
        .PortPinOutputCurrent = PORT_PIN_OUTPUT_CURRENT_4MA,
        .PortNum = btn->portNumber,
        .PortPinNum = btn->pinNumber,
        .PortIntPin = Port_pin
    };

    if (Port_Init(&STR_PortsConfig) == PORT_OK)
    {
        error= PUSH_BTN_INIT_OK;
    }
    else
    {
        error= PUSH_BTN_INIT_NOK;
    }
		return error;
}
ENU_PUSH_BTN_systemState_t PUSH_BTN_read_state(const ST_PUSH_BTN_pinCfg_t *btn, ENU_PUSH_BTN_state_t *btn_state)
{
	ENU_PUSH_BTN_systemState_t error;
    Port_PinLevel btnLogic;

    Port_ConfigType dio_pinCfg = {
        .PortPinMode = PORT_MODE_DIGITAL,
        .PortPinLevelValue = PORT_PIN_LEVEL_LOW,
        .PortPinDirection = PORT_PIN_DIRECTION_IN,
        .PortPinInternalAttach = btn->pushBtnConnection,
        .PortPinOutputCurrent = PORT_PIN_OUTPUT_CURRENT_4MA,
        .PortNum = btn->portNumber,
        .PortPinNum = btn->pinNumber,
        .PortIntPin = Port_pin
    };

    if (Port_Init(&dio_pinCfg) != PORT_OK)
    {
        error= PUSH_BTN_INIT_NOK;  // Return initialization error
    }

    GPIO_Read(btn->portNumber, btn->pinNumber, &btnLogic);

    if (btn->pushBtnConnection == PORT_PIN_PUR)
    {
        if (btnLogic == PORT_PIN_LEVEL_HIGH)
        {
            *btn_state = PUSH_BTN_STATE_RELEASED;
        }
        else
        {
            *btn_state = PUSH_BTN_STATE_PRESSED;
        }
    }
    else if (btn->pushBtnConnection == PORT_PIN_PDR)
    {
        if (btnLogic == PORT_PIN_LEVEL_HIGH)
        {
            *btn_state = PUSH_BTN_STATE_PRESSED;
        }
        else
        {
            *btn_state = PUSH_BTN_STATE_RELEASED;
        }
    }
    else
    {
        error= PUSH_BTN_NULL_PTR;  // Return error for invalid connection type
    }

    error= PUSH_BTN_READ_OK;  // Return success
		return error;
}

