/*
 * dio_config.h
 *
 *  Created on: 14 Jun 2023
 *      Author: 20101
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_



#define PINS_CFG_ARRAY_SIZE     5
#define PORTE_MAX_PIN           6
#define INTERRUPT_PIN_FIRED     1

typedef enum
{
    GPIO_INIT_OK = 0,
    GPIO_INIT_NOK,
    GPIO_DEINIT_OK,
    GPIO_NULL_PTR,
    GPIO_DIR_OK,
    GPIO_DIR_NOK,
    GPIO_DATA_OK,
    GPIO_DATA_NOK,
    GPIO_CUR_OK,
    GPIO_CUR_NOK,
    GPIO_PIN_MODE_OK,
    GPIO_PIN_MODE_NOK,
    GPIO_PIN_INTERNAL_REG_OK,
    GPIO_PIN_INTERNAL_REG_NOK,
    GPIO_INTERRUPT_OK,
    GPIO_INTERRUPT_NOK,
    GPIO_INTERRUPT_ENABLE_OK,
    GPIO_INTERRUPT_ENABLE_NOK,
    GPIO_INTERRUPT_DISABLE_OK,
    GPIO_INTERRUPT_DISABLE_NOK,
    GPIO_PORTE_VALID_PIN,
    GPIO_PORTE_INVALID_PIN,
    GPIO_CALLBACK_HANDLER_OK,
    GPIO_CALLBACK_HANDLER_NOK
}ENU_GPIO_systemState_t;


typedef enum
{
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF
}ENU_GPIO_port_t;


typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}ENU_GPIO_pin_t;


typedef enum
{
    GPIO_DIR_INPUT = 0,
    GPIO_DIR_OUTPUT
}ENU_GPIO_direction_t;

typedef enum
{
    GPIO_LOGIC_LOW = 0,
    GPIO_LOGIC_HIGH,
    GPIO_LOGIC_DISABLED
}ENU_GPIO_logic_t;


typedef enum
{
    GPIO_MODE_GPIO = 0,
    GPIO_MODE_ANALOG,
    GPIO_MODE_DIGITAL,
    GPIO_MODE_ALTERNATE
}ENU_GPIO_pinMode_t;



typedef enum
{
    GPIO_CUR_8MA = 0,
    GPIO_CUR_4MA,
    GPIO_CUR_2MA,
    GPIO_PIN_CUR_DISABLED
}ENU_GPIO_currentLevel_t;



typedef enum
{
    GPIO_PULL_UP = 0,
    GPIO_PULL_DOWN,
    GPIO_OPEN_DRAIN,
    GPIO_PIN_INTERNAL_REG_DISABLED
}ENU_GPIO_pinInternalAttach_t;

typedef enum
{
    GPIO_INTERRUPT_ENABLE = 0,
    GPIO_INTERRUPT_DISABLE
}ENU_GPIO_interruptStatus_t;

typedef enum
{
    GPIO_INTERRUPT_SENSE_LEVELS = 0,
    GPIO_INTERRUPT_SENSE_EDGES,
    GPIO_INTERRUPT_SENSE_DISABLED
}ENU_GPIO_interruptSenseControl_t;

typedef enum
{
    GPIO_INTERRUPT_EVENT = 0,
    GPIO_INTERRUPT_BOTH_EDGES,
    GPIO_INTERRUPT_EVENT_DISABLED
}ENU_GPIO_interruptEventStatus_t;

typedef enum
{
    GPIO_TRIGGER_LOW_EDGE_LOW_LEVEL = 0,
    GPIO_TRIGGER_HIGH_EDGE_HIGH_LEVEL,
    GPIO_INTERRUPT_TRIGGER_DISABLED
}ENU_GPIO_interruptEventTriggerStatus_t;


typedef struct{

    ENU_GPIO_pinMode_t                              pinMode;
    ENU_GPIO_currentLevel_t                         currentLevel;
    ENU_GPIO_direction_t                            pinDirection;
    ENU_GPIO_logic_t                                pinLogic;
    ENU_GPIO_pinInternalAttach_t                    pinInternalAttach;
    ENU_GPIO_interruptStatus_t                      interruptStatus;
    ENU_GPIO_interruptSenseControl_t                interruptSenseControl;
    ENU_GPIO_interruptEventStatus_t                 interruptEvent;
    ENU_GPIO_interruptEventTriggerStatus_t          triggerStatus;
    void(*ptrFucnPinIrqCallback)(void);
    ENU_GPIO_port_t                                 portNumber;
    ENU_GPIO_pin_t                                  pinNumber;

}ST_dio_pinCfg_t;


#endif /* MCAL_DIO_DIO_CONFIG_H_ */
