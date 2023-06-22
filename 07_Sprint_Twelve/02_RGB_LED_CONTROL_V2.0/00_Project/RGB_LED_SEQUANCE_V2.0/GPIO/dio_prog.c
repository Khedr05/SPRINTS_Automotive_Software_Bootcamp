/*
 * dio_prog.c
 *
 *  Created on: 14 Jun 2023
 *      Author: 20101
 */

#include "dio_interface.h"


void GPIOA_Handler(void);
void GPIOB_Handler(void);
void GPIOC_Handler(void);
void GPIOD_Handler(void);
void GPIOE_Handler(void);
void GPIOF_Handler(void);

static void(*GPIO_ptrFuncportaIrqCallback[8])(void);
static void(*GPIO_ptrFuncportbIrqCallback[8])(void);
static void(*GPIO_ptrFuncportcIrqCallback[8])(void);
static void(*GPIO_ptrFuncportdIrqCallback[8])(void);
static void(*GPIO_ptrFuncporteIrqCallback[6])(void);
static void(*GPIO_ptrFuncportfIrqCallback[8])(void);

ENU_GPIO_systemState_t GPIO_init(ST_dio_pinCfg_t  *arg_pincfg)
{
    ENU_GPIO_systemState_t ret;
    if(PTR_NULL == arg_pincfg )
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        /* Check if the pin in PORTE it will be valid pin */

        if(GPIO_PORTE == arg_pincfg->portNumber)
        {
            /* check that the pin is less than the max number of PORTE pins*/
            if(PORTE_MAX_PIN < arg_pincfg->pinNumber)
            {
                /* Set Clock For The Port */
                SET_BIT(RCGCGPIO_REG , arg_pincfg->portNumber);
                ret = GPIO_PORTE_VALID_PIN;
            }
            else
            {
                ret = GPIO_PORTE_INVALID_PIN;
            }
        }
        else
        {
            /* Set Clock For The Port */
            SET_BIT(RCGCGPIO_REG , arg_pincfg->portNumber);
            ret = GPIO_PORTE_VALID_PIN;
        }

					GPIOLOCK_REG(arg_pincfg->portNumber) = GPIO_LOCK_KEY;
          GPIOCR_REG(arg_pincfg->portNumber) = GPIO_DUMP_LOCK_KEY;
        if(GPIO_PORTE_VALID_PIN == ret)
        {
            /* Set Pin Direction */
            if(GPIO_DIR_INPUT == arg_pincfg->pinDirection)
            {
                CLEAR_BIT(GPIODIR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_DIR_OK;
            }
            else if(GPIO_DIR_OUTPUT == arg_pincfg->pinDirection)
            {
                SET_BIT(GPIODIR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_DIR_OK;
            }
            else
            {
                ret = GPIO_DIR_NOK;
            }
        }
        else
        {
            /* Do Nothing */
        }

        /* Set Pin Logic */
        if(GPIO_DIR_OK == ret )
        {
            if(GPIO_LOGIC_HIGH == arg_pincfg->pinLogic)
            {
                SET_BIT(GPIODATA_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_DATA_OK;
            }
            else if(GPIO_LOGIC_LOW == arg_pincfg->pinLogic)
            {
                CLEAR_BIT(GPIODATA_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_DATA_OK;
            }
            else if(GPIO_LOGIC_DISABLED == arg_pincfg->pinLogic)
            {
                ret = GPIO_DATA_OK;
            }
            else
            {
                ret = GPIO_DATA_NOK;
            }
        }
        else
        {
            /* Do Nothing */
        }


        /* Set Current Level */

        if(GPIO_DATA_OK == ret)
        {

            if(GPIO_CUR_2MA == arg_pincfg->currentLevel)
            {
                SET_BIT(GPIODR2R_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_CUR_OK;
            }
            else if(GPIO_CUR_4MA == arg_pincfg->currentLevel)
            {
                SET_BIT(GPIODR4R_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_CUR_OK;
            }
            else if(GPIO_CUR_8MA == arg_pincfg->currentLevel)
            {
                SET_BIT(GPIODR8R_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_CUR_OK;

            }
            else if(GPIO_PIN_CUR_DISABLED == arg_pincfg->currentLevel)
            {
                ret = GPIO_CUR_OK;
            }
            else
            {
                ret = GPIO_CUR_NOK;
            }
        }
        else
        {
            /* Do Nothing */
        }

        /* Set Pin As Digital Or Analog or gpio or alternate */

        if(GPIO_CUR_OK == ret)
        {


            if(GPIO_MODE_DIGITAL == arg_pincfg->pinMode       )
            {
                CLEAR_BIT(GPIOAFSEL_REG(arg_pincfg->portNumber)  , arg_pincfg->pinNumber     );
                CLEAR_BIT(GPIOAMSEL_REG(arg_pincfg->portNumber)  , arg_pincfg->pinNumber     );
                SET_BIT(GPIODEN_REG(arg_pincfg->portNumber    )  , arg_pincfg->pinNumber     );
                ret = GPIO_PIN_MODE_OK;
            }
            else if(GPIO_MODE_ANALOG == arg_pincfg->pinMode   )
            {
                CLEAR_BIT(GPIOAFSEL_REG(arg_pincfg->portNumber)   , arg_pincfg->pinNumber    );
                CLEAR_BIT(GPIODEN_REG(arg_pincfg->portNumber  )   , arg_pincfg->pinNumber    );
                SET_BIT(GPIOAMSEL_REG(arg_pincfg->portNumber  )   , arg_pincfg->pinNumber    );
                ret = GPIO_PIN_MODE_OK;
            }
            else if(GPIO_MODE_GPIO == arg_pincfg->pinMode     )
            {
                CLEAR_BIT(GPIOAFSEL_REG(arg_pincfg->portNumber)   , arg_pincfg->pinNumber    );
                CLEAR_BIT(GPIOAMSEL_REG(arg_pincfg->portNumber)   , arg_pincfg->pinNumber    );
                CLEAR_BIT(GPIODEN_REG(arg_pincfg->portNumber  )   , arg_pincfg->pinNumber    );
                ret = GPIO_PIN_MODE_OK;
            }
            else if(GPIO_MODE_ALTERNATE == arg_pincfg->pinMode)
            {
                SET_BIT(GPIOAFSEL_REG(arg_pincfg->portNumber  )   , arg_pincfg->pinNumber    );
                CLEAR_BIT(GPIOAMSEL_REG(arg_pincfg->portNumber)   , arg_pincfg->pinNumber    );
                CLEAR_BIT(GPIODEN_REG(arg_pincfg->portNumber  )   , arg_pincfg->pinNumber    );
                ret = GPIO_PIN_MODE_OK;
            }
            else
            {
                ret = GPIO_PIN_MODE_NOK;
            }

        }
        else
        {
            /* Do Nothing */
        }

        /* Set Pin Register Pull-up Pull-down Open-drain Or None  */

        if(GPIO_PIN_MODE_OK == ret)
        {

            if(GPIO_PULL_UP == arg_pincfg->pinInternalAttach)
            {
                SET_BIT(GPIOPUR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                CLEAR_BIT(GPIOPDR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                CLEAR_BIT(GPIOODR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_PIN_INTERNAL_REG_OK;
            }
            else if(GPIO_PULL_DOWN == arg_pincfg->pinInternalAttach)
            {
                CLEAR_BIT(GPIOPUR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                SET_BIT(GPIOPDR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                CLEAR_BIT(GPIOODR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_PIN_INTERNAL_REG_OK;
            }
            else if(GPIO_OPEN_DRAIN == arg_pincfg->pinInternalAttach)
            {
                CLEAR_BIT(GPIOPUR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                CLEAR_BIT(GPIOPDR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                SET_BIT(GPIOODR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_PIN_INTERNAL_REG_OK;
            }
            else if(GPIO_PIN_INTERNAL_REG_DISABLED == arg_pincfg->pinInternalAttach)
            {
                /* No internal registar for the pin */
                ret = GPIO_PIN_INTERNAL_REG_OK;
            }
            else
            {
                ret = GPIO_PIN_INTERNAL_REG_NOK;
            }
        }
        else
        {
            /* Do Nothing */
        }

        /* Configure interrupt */

        if(GPIO_PIN_INTERNAL_REG_OK == ret)
        {
            if( GPIO_INTERRUPT_ENABLE == arg_pincfg->interruptStatus)
            {
                /* set the pointer of the callback function */
                ret = GPIO_setPinCallbackHandelr(arg_pincfg);

                if(GPIO_CALLBACK_HANDLER_OK == ret)
                {

                    /* Mask the corresponding port by clearing the IME field in the GPIOIM register */
                    CLEAR_BIT(GPIOIM_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                    if( GPIO_INTERRUPT_SENSE_LEVELS == arg_pincfg->interruptSenseControl)
                    {
                        /* Configure the IS field in the GPIOIS register to sense levels */
                        SET_BIT(GPIOIS_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                        ret = GPIO_INTERRUPT_OK;
                    }
                    else if(GPIO_INTERRUPT_SENSE_EDGES == arg_pincfg->interruptSenseControl)
                    {
                        /* Configure the IS field in the GPIOIS register to sense edges */
                        CLEAR_BIT(GPIOIS_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                        ret = GPIO_INTERRUPT_OK;
                    }
                    else
                    {
                        ret = GPIO_INTERRUPT_NOK;
                    }

                    if((GPIO_INTERRUPT_OK == ret) && (GPIO_INTERRUPT_EVENT == arg_pincfg->interruptEvent))
                    {
                        /*Configure the IBE field in the GPIOIBE  to enable interrupt event*/
                        CLEAR_BIT(GPIOIBE_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                        if(GPIO_TRIGGER_LOW_EDGE_LOW_LEVEL == arg_pincfg->triggerStatus)
                        {
                            /*Configure the IVE field in the GPIOIVE  to trigger on falling edges & low levels*/
                            CLEAR_BIT(GPIOIEV_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                            /* Clear the GPIORIS register to make sure that the flag is not setting */
                            CLEAR_BIT(GPIORIS_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                            /* Unmask the port by setting the IME field in the GPIOIM register */
                            SET_BIT(GPIOIM_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);

                            /* Enable Port Interrupt  */
                            ret = GPIO_interruptPortEnable(arg_pincfg);
                            if(GPIO_INTERRUPT_ENABLE_OK == ret)
                                ret = GPIO_INTERRUPT_OK;
                        }
                        else if(GPIO_TRIGGER_HIGH_EDGE_HIGH_LEVEL == arg_pincfg->triggerStatus)
                        {
                            /*Configure the IVE field in the GPIOIVE  to trigger on raising edges & high levels*/
                            SET_BIT(GPIOIEV_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                            /* Clear the GPIORIS register to make sure that the flag is not setting */
                            CLEAR_BIT(GPIORIS_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                            /* Unmask the port by setting the IME field in the GPIOIM register */
                            SET_BIT(GPIOIM_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);

                            /* Enable Port Interrupt  */
                            ret = GPIO_interruptPortEnable(arg_pincfg);
                            if(GPIO_INTERRUPT_ENABLE_OK == ret)
                                ret = GPIO_INTERRUPT_OK;
                        }
                        else
                        {
                            ret = GPIO_INTERRUPT_NOK;
                        }
                    }
                    else if((GPIO_INTERRUPT_OK == ret) && (GPIO_INTERRUPT_BOTH_EDGES == arg_pincfg->interruptEvent))
                    {
                        /*Configure the IBE field in the GPIOIBE  to trigger on both edges*/
                        SET_BIT(GPIOIBE_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                        /* Clear the GPIORIS register to make sure that the flag is not setting */
                        CLEAR_BIT(GPIORIS_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                        /* Unmask the port by setting the IME field in the GPIOIM register */
                        SET_BIT(GPIOIM_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                        /* Enable Port Interrupt  */
                        ret = GPIO_interruptPortEnable(arg_pincfg);
                        if(GPIO_INTERRUPT_ENABLE_OK == ret)
                            ret = GPIO_INTERRUPT_OK;
                    }
                    else
                    {
                        ret = GPIO_INTERRUPT_NOK;
                    }
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else if(GPIO_INTERRUPT_DISABLE == arg_pincfg->interruptStatus)
            {
                /*Mask the corresponding port by clearing the IME field in the GPIOIM register*/
                CLEAR_BIT(GPIOIM_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
                ret = GPIO_INTERRUPT_OK;
            }
        }
        else
        {
            /* Do Nothing */
        }



        if(GPIO_INTERRUPT_OK == ret)
        {
            ret = GPIO_INIT_OK;
        }
        else
        {
            ret = GPIO_INIT_NOK;
        }
    }

    return ret;
}



ENU_GPIO_systemState_t GPIO_portDeinit(ST_dio_pinCfg_t  *arg_pincfg)
{
    ENU_GPIO_systemState_t ret;

    /* Check Pointer */
    if( PTR_NULL == arg_pincfg)
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        /* Disable Port Clock */
        CLEAR_BIT(RCGCGPIO_REG , arg_pincfg->portNumber);
        ret = GPIO_DEINIT_OK;
    }

    return ret;
}

ENU_GPIO_systemState_t GPIO_writeLogic(ST_dio_pinCfg_t  *arg_pincfg , ENU_GPIO_logic_t arg_logicValue)
{
    ENU_GPIO_systemState_t ret;
    /* Set Pin Logic */
    if(GPIO_LOGIC_HIGH == arg_logicValue)
    {
        SET_BIT(GPIODATA_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
        ret = GPIO_DATA_OK;
    }
    else if(GPIO_LOGIC_LOW == arg_logicValue)
    {
        CLEAR_BIT(GPIODATA_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
        ret = GPIO_DATA_OK;
    }
    else
    {
        ret = GPIO_DATA_NOK;
    }

    return ret;
}

ENU_GPIO_systemState_t GPIO_readLogic(ST_dio_pinCfg_t  *arg_pincfg , ENU_GPIO_logic_t *arg_logicValue)
{
    ENU_GPIO_systemState_t ret;
    Uint8_t pinVal = 0;
    pinVal = GET_BIT(GPIODATA_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);

    if(pinVal == GPIO_LOGIC_LOW)
    {
        *arg_logicValue = GPIO_LOGIC_LOW;
        ret = GPIO_DATA_OK;
    }
    else if(pinVal == GPIO_LOGIC_HIGH)
    {
        *arg_logicValue = GPIO_LOGIC_HIGH;
        ret = GPIO_DATA_OK;
    }
    else
    {
        ret = GPIO_DATA_NOK;
    }
    return ret;
}


ENU_GPIO_systemState_t GPIO_toggleLogic(ST_dio_pinCfg_t  *arg_pincfg)
{
    ENU_GPIO_systemState_t ret;
    /* check pointer */
    if(PTR_NULL == arg_pincfg)
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        /* Toggle Pin */
        TOGGLE_BIT(GPIODATA_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
        ret = GPIO_DATA_OK;
    }
    return ret;
}



ENU_GPIO_systemState_t GPIO_setDirection(ST_dio_pinCfg_t  *arg_pincfg , ENU_GPIO_direction_t arg_diractionValue)
{
    ENU_GPIO_systemState_t ret;

    /* Check Pointer */
    if(PTR_NULL == arg_pincfg)
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        /* Set Pin Direction */
        if(GPIO_DIR_INPUT == arg_diractionValue)
        {
            CLEAR_BIT(GPIODIR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
            ret = GPIO_DIR_OK;
        }
        else if(GPIO_DIR_OUTPUT == arg_diractionValue)
        {
            SET_BIT(GPIODIR_REG(arg_pincfg->portNumber) , arg_pincfg->pinNumber);
            ret = GPIO_DIR_OK;
        }
        else
        {
            ret = GPIO_DIR_NOK;
        }
    }
    return ret;
}

ENU_GPIO_systemState_t GPIO_interruptPortEnable(ST_dio_pinCfg_t  *arg_pincfg)
{
    ENU_GPIO_systemState_t ret;
    /* Check Pointer */
    if( PTR_NULL == arg_pincfg)
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        /* Enable Interrupt For The Port Pins */
        if( GPIO_PORTA ==  arg_pincfg->portNumber)
        {
            NVIC_EnableIRQ(GPIOA_IRQn);
            __enable_irq();
            ret = GPIO_INTERRUPT_ENABLE_OK;
        }
        else if(GPIO_PORTB ==  arg_pincfg->portNumber)
        {
            NVIC_EnableIRQ(GPIOB_IRQn);
            __enable_irq();
            ret = GPIO_INTERRUPT_ENABLE_OK;
        }
        else if(GPIO_PORTC ==  arg_pincfg->portNumber)
        {
            NVIC_EnableIRQ(GPIOC_IRQn);
            __enable_irq();
            ret = GPIO_INTERRUPT_ENABLE_OK;
        }
        else if(GPIO_PORTD ==  arg_pincfg->portNumber)
        {
            NVIC_EnableIRQ(GPIOD_IRQn);
            __enable_irq();
            ret = GPIO_INTERRUPT_ENABLE_OK;
        }
        else if(GPIO_PORTE ==  arg_pincfg->portNumber)
        {
            NVIC_EnableIRQ(GPIOE_IRQn);
            __enable_irq();
            ret = GPIO_INTERRUPT_ENABLE_OK;
        }
        else if(GPIO_PORTF ==  arg_pincfg->portNumber)
        {
            NVIC_EnableIRQ(GPIOF_IRQn);
            __enable_irq();
            ret = GPIO_INTERRUPT_ENABLE_OK;
        }
        else
        {
            ret = GPIO_INTERRUPT_ENABLE_NOK;
        }
    }
    return ret;
}

ENU_GPIO_systemState_t GPIO_interruptPortDisable(ST_dio_pinCfg_t  *arg_pincfg)
{
    ENU_GPIO_systemState_t ret;
    /* Check Pointer */
    if( PTR_NULL == arg_pincfg)
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        /* Enable Interrupt For The Port Pins */
        if( GPIO_PORTA ==  arg_pincfg->portNumber)
        {
            NVIC_DisableIRQ(GPIOA_IRQn);
            __disable_irq();
            ret = GPIO_INTERRUPT_DISABLE_OK;
        }
        else if(GPIO_PORTB ==  arg_pincfg->portNumber)
        {
            NVIC_DisableIRQ(GPIOB_IRQn);
            __disable_irq();
            ret = GPIO_INTERRUPT_DISABLE_OK;
        }
        else if(GPIO_PORTC ==  arg_pincfg->portNumber)
        {
            NVIC_DisableIRQ(GPIOC_IRQn);
            __disable_irq();
            ret = GPIO_INTERRUPT_DISABLE_OK;
        }
        else if(GPIO_PORTD ==  arg_pincfg->portNumber)
        {
            NVIC_DisableIRQ(GPIOD_IRQn);
            __disable_irq();
            ret = GPIO_INTERRUPT_DISABLE_OK;
        }
        else if(GPIO_PORTE ==  arg_pincfg->portNumber)
        {
            NVIC_DisableIRQ(GPIOE_IRQn);
            __disable_irq();
            ret = GPIO_INTERRUPT_DISABLE_OK;
        }
        else if(GPIO_PORTF ==  arg_pincfg->portNumber)
        {
            NVIC_DisableIRQ(GPIOF_IRQn);
            __disable_irq();
            ret = GPIO_INTERRUPT_DISABLE_OK;
        }
        else
        {
            ret = GPIO_INTERRUPT_DISABLE_NOK;
        }
    }
    return ret;
}


ENU_GPIO_systemState_t GPIO_setPinCallbackHandelr(ST_dio_pinCfg_t  *arg_pincfg)
{
    ENU_GPIO_systemState_t ret;

    if(PTR_NULL == arg_pincfg && PTR_NULL == arg_pincfg->ptrFucnPinIrqCallback)
    {
        ret = GPIO_NULL_PTR;
    }
    else
    {
        if(GPIO_PORTA == arg_pincfg->portNumber)
        {
            GPIO_ptrFuncportaIrqCallback[arg_pincfg->pinNumber] = arg_pincfg->ptrFucnPinIrqCallback;
            ret = GPIO_CALLBACK_HANDLER_OK;
        }
        else if(GPIO_PORTB == arg_pincfg->portNumber)
        {
            GPIO_ptrFuncportbIrqCallback[arg_pincfg->pinNumber] = arg_pincfg->ptrFucnPinIrqCallback;
            ret = GPIO_CALLBACK_HANDLER_OK;
        }
        else if(GPIO_PORTC == arg_pincfg->portNumber)
        {
            GPIO_ptrFuncportcIrqCallback[arg_pincfg->pinNumber] = arg_pincfg->ptrFucnPinIrqCallback;
            ret = GPIO_CALLBACK_HANDLER_OK;
        }
        else if(GPIO_PORTD == arg_pincfg->portNumber)
        {
            GPIO_ptrFuncportdIrqCallback[arg_pincfg->pinNumber] = arg_pincfg->ptrFucnPinIrqCallback;
            ret = GPIO_CALLBACK_HANDLER_OK;
        }
        else if(GPIO_PORTE == arg_pincfg->portNumber)
        {
            if(PORTE_MAX_PIN < arg_pincfg->portNumber)
            {
                GPIO_ptrFuncporteIrqCallback[arg_pincfg->pinNumber] = arg_pincfg->ptrFucnPinIrqCallback;
                ret = GPIO_CALLBACK_HANDLER_OK;
            }
            else
            {
                ret = GPIO_PORTE_INVALID_PIN;
            }
        }
        else if(GPIO_PORTF == arg_pincfg->portNumber)
        {
            GPIO_ptrFuncportfIrqCallback[arg_pincfg->pinNumber] = arg_pincfg->ptrFucnPinIrqCallback;
            ret = GPIO_CALLBACK_HANDLER_OK;
        }
        else
        {
            ret = GPIO_CALLBACK_HANDLER_NOK;
        }
    }
    return ret;
}


void GPIOA_Handler(void)
{
   Uint8_t pinCounter;	
	for(pinCounter = 0 ; pinCounter<8;pinCounter++)
	{
		 if(GET_BIT(GPIORIS_REG(GPIO_PORTA) , pinCounter) == INTERRUPT_PIN_FIRED)
    {
			  SET_BIT(GPIOICR_REG(GPIO_PORTA) , pinCounter);
			if(PTR_NULL != GPIO_ptrFuncportaIrqCallback[pinCounter])
			{
				  GPIO_ptrFuncportaIrqCallback[pinCounter]();
				  break;
			}
			else
			{
				/* Do Nothing */
			}
				
    }
		else
		{
			/* Do Nothing */
		}
	}
}

void GPIOB_Handler(void)
{
Uint8_t pinCounter;	
	for(pinCounter = 0 ; pinCounter<8;pinCounter++)
	{
		 if(GET_BIT(GPIORIS_REG(GPIO_PORTB) , pinCounter) == INTERRUPT_PIN_FIRED)
    {
			  SET_BIT(GPIOICR_REG(GPIO_PORTB) , pinCounter);
			if(PTR_NULL != GPIO_ptrFuncportbIrqCallback[pinCounter])
			{
				  GPIO_ptrFuncportbIrqCallback[pinCounter]();
				  break;
			}
			else
			{
				/* Do Nothing */
			}
				
    }
		else
		{
			/* Do Nothing */
		}
	}
}

void GPIOC_Handler(void)
{
 Uint8_t pinCounter;	
	for(pinCounter = 0 ; pinCounter<8;pinCounter++)
	{
		 if(GET_BIT(GPIORIS_REG(GPIO_PORTC) , pinCounter) == INTERRUPT_PIN_FIRED)
    {
			  SET_BIT(GPIOICR_REG(GPIO_PORTC) , pinCounter);
			if(PTR_NULL != GPIO_ptrFuncportcIrqCallback[pinCounter])
			{
				  GPIO_ptrFuncportcIrqCallback[pinCounter]();
				  break;
			}
			else
			{
				/* Do Nothing */
			}
				
    }
		else
		{
			/* Do Nothing */
		}
	}
}



void GPIOD_Handler(void)
{
  Uint8_t pinCounter;	
	for(pinCounter = 0 ; pinCounter<8;pinCounter++)
	{
		 if(GET_BIT(GPIORIS_REG(GPIO_PORTD) , pinCounter) == INTERRUPT_PIN_FIRED)
    {
			  SET_BIT(GPIOICR_REG(GPIO_PORTD) , pinCounter);
			if(PTR_NULL != GPIO_ptrFuncportdIrqCallback[pinCounter])
			{
				  GPIO_ptrFuncportdIrqCallback[pinCounter]();
				  break;
			}
			else
			{
				/* Do Nothing */
			}
				
    }
		else
		{
			/* Do Nothing */
		}
	}
}

void GPIOE_Handler(void)
{
Uint8_t pinCounter;	
	for(pinCounter = 0 ; pinCounter<8;pinCounter++)
	{
		 if(GET_BIT(GPIORIS_REG(GPIO_PORTE) , pinCounter) == INTERRUPT_PIN_FIRED)
    {
			  SET_BIT(GPIOICR_REG(GPIO_PORTE) , pinCounter);
			if(PTR_NULL != GPIO_ptrFuncporteIrqCallback[pinCounter])
			{
				  GPIO_ptrFuncporteIrqCallback[pinCounter]();
				  break;
			}
			else
			{
				/* Do Nothing */
			}
				
    }
		else
		{
			/* Do Nothing */
		}
	}
}

void GPIOF_Handler(void)
{
	
	Uint8_t pinCounter;	
	for(pinCounter = 0 ; pinCounter<8;pinCounter++)
	{
		 if(GET_BIT(GPIORIS_REG(GPIO_PORTF) , pinCounter) == INTERRUPT_PIN_FIRED)
    {
			  SET_BIT(GPIOICR_REG(GPIO_PORTF) , pinCounter);
			if(PTR_NULL != GPIO_ptrFuncportfIrqCallback[pinCounter])
			{
				  GPIO_ptrFuncportfIrqCallback[pinCounter]();
				  break;
			}
			else
			{
				/* Do Nothing */
			}
				
    }
		else
		{
			/* Do Nothing */
		}
	}
}

