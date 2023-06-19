/*
 * push_btn.c
 *
 *  Created on: 17 Jun 2023
 *      Author: 20101
 */


#include "push_btn_interface.h"


ENU_PUSH_BTN_systemState_t PUSH_BTN_intialize(const ST_PUSH_BTN_pinCfg_t *btn)
{
      ENU_PUSH_BTN_systemState_t  PUSH_BTN_ret;
      ENU_GPIO_systemState_t GPIO_ret;

       if(PTR_NULL == btn)
       {
           PUSH_BTN_ret = PUSH_BTN_NULL_PTR;
       }
       else
       {
           ST_dio_pinCfg_t  dio_pinCfg =
           {GPIO_MODE_DIGITAL , GPIO_CUR_8MA , GPIO_DIR_INPUT , GPIO_LOGIC_DISABLED,
            btn->pushBtnConnection, GPIO_INTERRUPT_DISABLE ,
            GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
            GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL , btn->portNumber , btn->pinNumber};

           GPIO_ret = GPIO_init(&dio_pinCfg);

           if(GPIO_INIT_OK  == GPIO_ret)
           {
               PUSH_BTN_ret = PUSH_BTN_INIT_OK;
           }
           else
           {
               PUSH_BTN_ret = PUSH_BTN_INIT_NOK;
           }
       }
       return PUSH_BTN_ret;
}


ENU_PUSH_BTN_systemState_t PUSH_BTN_read_state(const ST_PUSH_BTN_pinCfg_t *btn , ENU_PUSH_BTN_state_t *btn_state)
{
    ENU_PUSH_BTN_systemState_t  PUSH_BTN_ret;
    ENU_GPIO_systemState_t GPIO_ret;

    if(PTR_NULL == btn || PTR_NULL == btn_state)
    {
        PUSH_BTN_ret = PUSH_BTN_NULL_PTR;
    }
    else
    {
        ENU_GPIO_logic_t btnLogic;

        ST_dio_pinCfg_t  dio_pinCfg =
        {GPIO_MODE_DIGITAL , GPIO_CUR_8MA , GPIO_DIR_INPUT , GPIO_LOGIC_DISABLED,
         btn->pushBtnConnection, GPIO_INTERRUPT_DISABLE ,
         GPIO_INTERRUPT_SENSE_DISABLED ,GPIO_INTERRUPT_EVENT_DISABLED ,
         GPIO_INTERRUPT_TRIGGER_DISABLED , PTR_NULL , btn->portNumber , btn->pinNumber};

        GPIO_ret = GPIO_readLogic(&dio_pinCfg, &btnLogic);
         
				if(GPIO_DATA_OK == GPIO_ret)
				{
					 if(GPIO_PULL_UP == btn->pushBtnConnection)
            {
							if(GPIO_LOGIC_HIGH == btnLogic)
							{
									*btn_state = PUSH_BTN_STATE_RELEASED;
								 PUSH_BTN_ret = PUSH_BTN_READ_OK;
							}
							else
							{
									*btn_state = PUSH_BTN_STATE_PRESSED;
									PUSH_BTN_ret = PUSH_BTN_READ_OK;
							}
            }
					else if(GPIO_PULL_DOWN == btn->pushBtnConnection)
					{
            if(GPIO_LOGIC_HIGH == btnLogic)
            {
                *btn_state = PUSH_BTN_STATE_PRESSED;
                PUSH_BTN_ret = PUSH_BTN_READ_OK;
            }
            else
            {
                *btn_state = PUSH_BTN_STATE_RELEASED;
                PUSH_BTN_ret = PUSH_BTN_READ_OK;
            }
					}
					else
					{
            PUSH_BTN_ret = PUSH_BTN_INVALD_CONNECTION;
					}
    }						
		else
		{
				/* Do Nothing*/
		}					
       
    if(PUSH_BTN_INVALD_CONNECTION == PUSH_BTN_ret)
    {
        PUSH_BTN_ret = PUSH_BTN_READ_NOK;
    }
    else
    {
        /* Do Nothing */
    }

    return PUSH_BTN_ret;
  }
}
