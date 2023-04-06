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
#include"util/delay.h"


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

#endif /* APP_APP_H_ */
