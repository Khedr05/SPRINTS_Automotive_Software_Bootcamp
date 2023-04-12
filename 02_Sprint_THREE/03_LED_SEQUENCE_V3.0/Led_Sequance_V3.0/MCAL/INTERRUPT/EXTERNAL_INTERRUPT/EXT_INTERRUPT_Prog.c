/*
 * EXT_INTERRUPT_Prog.c
 *
 *  Created on: 9 Apr 2023
 *      Author: 20101
 */


#include"EXT_INTERRUPT_Interface.h"


static void(*INT0_InterruptHandler)(void) = NULL;
static void(*INT1_InterruptHandler)(void) = NULL;
static void(*INT2_InterruptHandler)(void) = NULL;


Std_ReturnType EXT_vINTERRUPT_Init(const  ST_EXT_INTERRUPTS_CFG *EXT_INTx)
{
	Std_ReturnType ret = E_NOT_OK;

	if(NULL == EXT_INTx)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(EXT_INTx->EXTERNAL_INTERRUPRT_Number)
		{
		case EXT0_INTERRUPTS:
		{

			if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == LOW_LEVEL_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == ANY_LOGICAL_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == FALLING_EDGE_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == RISING_EDGE_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT0_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC01_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC00_BITS);
				ret = E_OK;
			}
			else
			{
				ret = E_NOT_OK;
			}
			break;
		}
		case EXT1_INTERRUPTS:
		{

			if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == LOW_LEVEL_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == ANY_LOGICAL_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == FALLING_EDGE_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
				CLEAR_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == RISING_EDGE_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT1_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC11_BITS);
				SET_BIT(MCUCR_REG,MCUCR_REG_ISC10_BITS);
				ret = E_OK;
			}
			else
			{
				ret = E_NOT_OK;
			}
			break;
		}
		case EXT2_INTERRUPTS:
		{

			if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == FALLING_EDGE_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT2_BITS);
				CLEAR_BIT(MCUCSR_REG,MCUCSR_REG_ISC2_BITS);
				ret = E_OK;
			}
			else if(EXT_INTx->EXTERNAL_INTERRUPRT_Sense_Control == RISING_EDGE_SENSE_CONTROL)
			{
				MCU_vEnableInterrupt();
				SET_BIT(GICR_REG,GICR_REG_INT2_BITS);
				SET_BIT(MCUCSR_REG,MCUCSR_REG_ISC2_BITS);
				ret = E_OK;
			}
			else
			{
				ret = E_NOT_OK;
			}
			break;
		}
		}
	}
	return ret;
}
Std_ReturnType EXT_vINTERRUPT_Denit(const ST_EXT_INTERRUPTS_CFG *EXT_INTx)
{
	Std_ReturnType ret = E_NOT_OK;

	if(NULL == EXT_INTx)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(EXT_INTx->EXTERNAL_INTERRUPRT_Number)
		{
		case EXT0_INTERRUPTS:
		{
			CLEAR_BIT(GICR_REG,GICR_REG_INT0_BITS);
			ret = E_OK;
			break;
		}
		case EXT1_INTERRUPTS:
		{
			CLEAR_BIT(GICR_REG,GICR_REG_INT1_BITS);
			ret = E_OK;
			break;
		}
		case EXT2_INTERRUPTS:
		{
			CLEAR_BIT(GICR_REG,GICR_REG_INT1_BITS);
			ret = E_OK;
			break;
		}
		}
	}
	return ret;
}

static Std_ReturnType EXT0_INTERRUPT_SetInterruptHandler(void(*InterruptHandler)(void))
{
	Std_ReturnType ret = E_NOT_OK;
	if( NULL == InterruptHandler)
	{
		ret = E_NOT_OK;
	}
	else
	{
		INT0_InterruptHandler = InterruptHandler;
		ret = E_OK;
	}
	return ret;
}

static Std_ReturnType EXT1_INTERRUPT_SetInterruptHandler(void(*InterruptHandler)(void))
{
	Std_ReturnType ret = E_NOT_OK;
	if( NULL == InterruptHandler)
	{
		ret = E_NOT_OK;
	}
	else
	{
		INT1_InterruptHandler = InterruptHandler;
		ret = E_OK;
	}
	return ret;
}

static Std_ReturnType EXT2_INTERRUPT_SetInterruptHandler(void(*InterruptHandler)(void))
{
	Std_ReturnType ret = E_NOT_OK;
	if( NULL == InterruptHandler)
	{
		ret = E_NOT_OK;
	}
	else
	{
		INT2_InterruptHandler = InterruptHandler;
		ret = E_OK;
	}
	return ret;
}

Std_ReturnType EXT_INTERRUPT_SetInterruptHandler(const ST_EXT_INTERRUPTS_CFG *EXT_INTx)
{

    Std_ReturnType ret = E_NOT_OK;
    if(NULL == EXT_INTx)
    {
        ret = E_NOT_OK;
    }
    else
    {
       switch(EXT_INTx->EXTERNAL_INTERRUPRT_Number)
        {
           case EXT0_INTERRUPTS:
            {
                ret = EXT0_INTERRUPT_SetInterruptHandler(EXT_INTx->INTERRUPT_EXTERNAL_HANDLER);
                break;
            }
           case EXT1_INTERRUPTS:
            {
                ret = EXT1_INTERRUPT_SetInterruptHandler(EXT_INTx->INTERRUPT_EXTERNAL_HANDLER);
                break;
            }
           case EXT2_INTERRUPTS:
            {
                ret = EXT2_INTERRUPT_SetInterruptHandler(EXT_INTx->INTERRUPT_EXTERNAL_HANDLER);
                break;
            }
        }
    }
    return ret;
}



ISR(EXT_INT0)
{
	INT0_InterruptHandler();
}
ISR(EXT_INT1)
{
	INT1_InterruptHandler();
}
ISR(EXT_INT2)
{
	INT2_InterruptHandler();
}

