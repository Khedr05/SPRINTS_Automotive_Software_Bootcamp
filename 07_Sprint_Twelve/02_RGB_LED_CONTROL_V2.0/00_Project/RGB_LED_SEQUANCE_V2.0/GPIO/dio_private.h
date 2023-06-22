/*
 * dio_private.h
 *
 *  Created on: 14 Jun 2023
 *      Author: 20101
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#define RCGCGPIO_REG            *((VUint32_t *) 0x400FE608)
/*#define SYSCTL_RCGC2_R          (*((volatile uint32_t *)0x400FE108))*/

#define GPIO_OFFSET(x)          (x<4?((0x40004000) + ((x)*0x1000)) : ((0x40024000) + ((x-4) *0x1000)))

#define GPIODATA_REG(x)          *((VUint32_t *)(GPIO_OFFSET(x) + 0x3FC))
#define GPIODIR_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0400))
#define GPIOIS_REG(x)            *((VUint32_t *)(GPIO_OFFSET(x) + 0x0404))
#define GPIOIBE_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0408))
#define GPIOIEV_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x040C))
#define GPIOIM_REG(x)            *((VUint32_t *)(GPIO_OFFSET(x) + 0x0410))
#define GPIORIS_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0414))
#define GPIOMIS_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0418))
#define GPIOICR_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x041C))
#define GPIOAFSEL_REG(x)         *((VUint32_t *)(GPIO_OFFSET(x) + 0x0420))
#define GPIODR2R_REG(x)          *((VUint32_t *)(GPIO_OFFSET(x) + 0x0500))
#define GPIODR4R_REG(x)          *((VUint32_t *)(GPIO_OFFSET(x) + 0x0504))
#define GPIODR8R_REG(x)          *((VUint32_t *)(GPIO_OFFSET(x) + 0x0508))
#define GPIOODR_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x050C))
#define GPIOPUR_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0510))
#define GPIOPDR_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0514))
#define GPIOSLR_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x0518))
#define GPIODEN_REG(x)           *((VUint32_t *)(GPIO_OFFSET(x) + 0x051C))
#define GPIOLOCK_REG(x)          *((VUint32_t *)(GPIO_OFFSET(x) + 0x0520))
#define GPIOCR_REG(x)            *((VUint32_t *)(GPIO_OFFSET(x) + 0x0524))
#define GPIOAMSEL_REG(x)         *((VUint32_t *)(GPIO_OFFSET(x) + 0x0528))
#define GPIO_LOCK_KEY            0x4C4F434B 
#define GPIO_DUMP_LOCK_KEY			 0x03
















#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
