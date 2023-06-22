/*
 * led_prog.c
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */


#include "led_interface.h"

/*
 * led_prog.c
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */




ENU_LED_systemState_t LED_initialize(const ST_led_pinCfg_t *led)
{
    ENU_LED_systemState_t LED_ret;
    ENU_GPIO_systemState_t GPIO_ret;

    if(PTR_NULL == led)
    {
        LED_ret = LED_NULL_PTR;
    }
    else
    {
        ST_dio_pinCfg_t  dio_pinCfg =
        {GPIO_MODE_DIGITAL , GPIO_PIN_CUR_DISABLED , GPIO_DIR_OUTPUT , led->led_status,
         GPIO_PIN_INTERNAL_REG_DISABLED , GPIO_INTERRUPT_DISABLE ,
         GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
         GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL ,led->portNumber , led->pinNumber};

        GPIO_ret = GPIO_init(&dio_pinCfg);

        if(GPIO_INIT_OK  == GPIO_ret)
        {
            LED_ret = LED_INIT_OK;
        }
        else
        {
            LED_ret = LED_INIT_NOK;
        }
    }
    return LED_ret;
}


ENU_LED_systemState_t LED_turnOn(const ST_led_pinCfg_t *led)
{
    ENU_LED_systemState_t LED_ret;
    ENU_GPIO_systemState_t GPIO_ret;

    if(PTR_NULL == led)
    {
        LED_ret = LED_NULL_PTR;
    }
    else
    {
        ST_dio_pinCfg_t  dio_pinCfg =
        {GPIO_MODE_DIGITAL , GPIO_PIN_CUR_DISABLED , GPIO_DIR_OUTPUT , led->led_status,
         GPIO_PIN_INTERNAL_REG_DISABLED , GPIO_INTERRUPT_DISABLE ,
         GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
         GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL ,led->portNumber , led->pinNumber};

        GPIO_ret = GPIO_writeLogic(&dio_pinCfg , GPIO_LOGIC_HIGH);

        if(GPIO_DATA_OK  == GPIO_ret)
        {
            LED_ret = LED_INIT_OK;
        }
        else
        {
            LED_ret = LED_INIT_NOK;
        }
    }
    return LED_ret;
}


ENU_LED_systemState_t LED_turnOff(const ST_led_pinCfg_t *led)
{
    ENU_LED_systemState_t LED_ret;
    ENU_GPIO_systemState_t GPIO_ret;

    if(PTR_NULL == led)
    {
        LED_ret = LED_NULL_PTR;
    }
    else
    {
        ST_dio_pinCfg_t  dio_pinCfg =
        {GPIO_MODE_DIGITAL , GPIO_PIN_CUR_DISABLED , GPIO_DIR_OUTPUT , led->led_status,
         GPIO_PIN_INTERNAL_REG_DISABLED , GPIO_INTERRUPT_DISABLE ,
         GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
         GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL ,led->portNumber , led->pinNumber};

        GPIO_ret = GPIO_writeLogic(&dio_pinCfg , GPIO_LOGIC_LOW);

        if(GPIO_DATA_OK  == GPIO_ret)
        {
            LED_ret = LED_INIT_OK;
        }
        else
        {
            LED_ret = LED_INIT_NOK;
        }
    }
    return LED_ret;
}


ENU_LED_systemState_t LED_toggle(const ST_led_pinCfg_t *led)
{
    ENU_LED_systemState_t LED_ret;
    ENU_GPIO_systemState_t GPIO_ret;

    if(PTR_NULL == led)
    {
        LED_ret = LED_NULL_PTR;
    }
    else
    {
        ST_dio_pinCfg_t  dio_pinCfg =
        {GPIO_MODE_DIGITAL , GPIO_PIN_CUR_DISABLED , GPIO_DIR_OUTPUT , led->led_status,
         GPIO_PIN_INTERNAL_REG_DISABLED , GPIO_INTERRUPT_DISABLE ,
         GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
         GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL ,led->portNumber , led->pinNumber};

        GPIO_ret = GPIO_toggleLogic(&dio_pinCfg);

        if(GPIO_DATA_OK  == GPIO_ret)
        {
            LED_ret = LED_INIT_OK;
        }
        else
        {
            LED_ret = LED_INIT_NOK;
        }
    }
    return LED_ret;
}

