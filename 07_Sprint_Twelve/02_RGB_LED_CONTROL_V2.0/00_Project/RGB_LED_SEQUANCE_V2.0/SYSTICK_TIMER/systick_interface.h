
#ifndef STSTICK_INTERFACE_H_
#define STSTICK_INTERFACE_H_

#include "TM4C123GH6PM.h"
#include "std_types.h"
#include "bit_math.h"
#include "systick_config.h"
#include "systick_private.h"



ENU_SYSTICK_systemState_t SYSTICK_init(STR_SYSTICK_cfg_t *systickCfg);

ENU_SYSTICK_systemState_t SYSTICK_deinit(void);

ENU_SYSTICK_systemState_t SYSTICK_enableInterrupt(void);

ENU_SYSTICK_systemState_t SYSTICK_disableInterrupt(void);

ENU_SYSTICK_systemState_t SYSTICK_setDelayMs(Uint32_t arg_delayInMs);



	
#endif /* STSTICK_INTERFACE_H_  */