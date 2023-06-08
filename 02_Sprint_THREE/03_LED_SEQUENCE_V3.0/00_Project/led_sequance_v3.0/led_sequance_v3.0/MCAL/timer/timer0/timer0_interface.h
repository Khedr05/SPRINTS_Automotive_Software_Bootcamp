/*
 * timers_interface.h
 *
 * Created: 05/06/2023 18:32:29
 *  Author: 20101
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#include <math.h>
#include "../../../COMMON/bit_math.h"
#include "../../../COMMON/std_types.h"
#include "../../../COMMON/vect_table.h"
#include "../../../MCAL/mcu_cfg/mcu_interface.h"
#include "timer0_private.h"
#include "timer0_config.h"



enu_timer0_system_state TIMER0_init(const  str_timer0_init_config_t *str_timer0_cfg);
enu_timer0_system_state TIMER0_start(const str_timer0_init_config_t *str_timer0_cfg);
enu_timer0_system_state TIMER0_stop();
enu_timer0_system_state TIMER0_set_tcnt(Uint8_t arg_tcnt_value);
enu_timer0_system_state TIMER0_set_ocr(Uint8_t arg_ocr_value);
void TIMER0_delay_ms(Uint32_t arg_delay_in_ms);
void TIMER0_sync_delay_ms(Uint32_t arg_delay_in_ms);



#endif /* TIMERS_INTERFACE_H_ */