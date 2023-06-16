/*
 * common.h
 *
 *  Created on: 16 Jun 2023
 *      Author: 20101
 */

#ifndef COMMON_H_
#define COMMON_H_

/* INCLUDES*/

#include "stdint.h"


/* MACROS*/

#define SUCCESS               (0)
#define ERROR                 (-1)
#define INVALID_INPUT         (-2)
#define NULL                  ((void *)0)

#ifndef TRUE
#define TRUE                  (1)
#endif

#ifndef FALSE
#define FALSE                 (0)
#endif

/* TYPEDEFS*/


typedef unsigned char          boolean;


/* BIT MATH OPERATIONS*/


#define GET_BIT_STATUS(reg,bit_num)    ((reg>>bit_num)&1)
#define SET_BIT(reg,bit_num)    (reg|=(1<<bit_num))
#define CLR_BIT(reg,bit_num)  (reg&=(~(1<<bit_num)))
#define TOGGLE_BIT(reg,bit_num) (reg^=(1<<bit_num))
#endif
