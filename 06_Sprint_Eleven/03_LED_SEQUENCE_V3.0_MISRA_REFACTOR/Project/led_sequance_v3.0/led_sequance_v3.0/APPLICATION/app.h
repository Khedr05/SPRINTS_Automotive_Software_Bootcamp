/*
 * APP.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../MCAL/dio/dio_interface.h"
#include "../ECUAL/led/led_interface.h"
#include "../ECUAL/push_button/pb_interface.h"
#include "../COMMON/std_types.h"
#include "../MCAL/exti/exti_interface.h"
#include "../MCAL/timer/timer0/timer0_interface.h"
#include "../MCAL/mcu_cfg/mcu_interface.h"


#define F_CPU 8000000UL

typedef enum
{
	ZERO_PRESS = 0,
	ONE_PRESS,
	TWO_PRESS,
	THREE_PRESS,
	FOUR_PRESS,
	FIVE_PRESS,
	SIX_PRESS,
	SEVEN_PRESS,
	EIGHT_PRESS,
	NINE_PRESS
}EN_PressCounter_t;


void appmain(void);
void BlinkModes(Uint32_t from,Uint32_t to);



#endif /* APP_APP_H_ */
