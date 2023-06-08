/*
 * DIO_private.h
 *
 *  Created on: 5 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_




// intialize PORTA registers
#define PORTA_REG *(( VUint8_t *)0x3B)  // register for pin output
#define DDRA_REG *(( VUint8_t *)0x3A)  // register for port direction
#define PINA_REG *(( VUint8_t *)0x39) // register for pin input

// intialize PORTB registers
#define PORTB_REG *(( VUint8_t *)0x38)  // register for pin output
#define DDRB_REG *(( VUint8_t *)0x37)  // register for port direction
#define PINB_REG *(( VUint8_t *)0x36) // register for pin input

// intialize PORTC registers
#define PORTC_REG *(( VUint8_t *)0x35)  // register for pin output
#define DDRC_REG *(( VUint8_t *)0x34)  // register for port direction
#define PINC_REG *(( VUint8_t *)0x33) // register for pin input

// intialize PORTD registers
#define PORTD_REG *(( VUint8_t *)0x32)   // register for pin output
#define DDRD_REG *(( VUint8_t *)0x31)   // register for port direction
#define PIND_REG *(( VUint8_t *)0x30)  // register for pin input





#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
