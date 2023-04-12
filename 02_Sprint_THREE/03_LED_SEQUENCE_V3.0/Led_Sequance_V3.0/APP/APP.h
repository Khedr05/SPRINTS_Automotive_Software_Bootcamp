/*
 * APP.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include"../MCAL/DIO/DIO_interface.h"
#include"../ECU/LED/LED_interface.h"
#include"../ECU/PUSH_BUTTON/PB_interface.h"
#include"../SERVICES/STD_Types.h"
#include"../MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXT_INTERRUPT_Interface.h"
#include"../MCAL/TIMER/TMR_interface.h"
#include"../MCAL/MCU_CFG/MCU_Interface.h"


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
