


#include "systick_interface.h"

extern void systickCallback(void);

STR_SYSTICK_cfg_t a_systickCfg[SYSTICK_CFG_ARRAY_SIZE] =
{
	{SYSTICK_SYSTEM_CLOCK , SYSTICK_INTERRUPT_ENABLED , SYSTICK_ENABLED , systickCallback}
};