/*
 * timers_private.h
 *
 * Created: 05/06/2023 18:32:57
 *  Author: 20101
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

/* timer 0 registers addresses define */

#define TCCR0_REG		*(( VUint8_t *)0x53)
#define TCNT0_REG		*(( VUint8_t *)0x52)
#define OCR0_REG		*(( VUint8_t *)0x5C)
#define TIMSK_REG		*(( VUint8_t *)0x59)
#define TIFR_REG		*(( VUint8_t *)0x58)

/* define each bit in all registers */

typedef enum
{
		TCCR0_REG_CS00_BIT = 0,
		TCCR0_REG_CS01_BIT,
		TCCR0_REG_CS02_BIT,
		TCCR0_REG_WGM01_BIT,
		TCCR0_REG_COM00_BIT,
		TCCR0_REG_COM01_BIT,
		TCCR0_REG_WGM00_BIT,
		TCCR0_REG_FOC0_BIT
}enu_TCCR0_REG_BITS;

typedef enum
{
		TIMSK_REG_TOIE0_BIT = 0,
		TIMSK_REG_OCIE0_BIT
}enu_TIMSK_REG_BITS;

typedef enum
{
	TIFR_REG_TOV0_BIT = 0,
	TIFR_REG_OCF0_BIT
}enu_TIFR_REG_BITS;

#endif /* TIMERS_PRIVATE_H_ */