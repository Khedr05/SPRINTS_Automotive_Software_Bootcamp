/*
 * DIO_interface.h
 *
 *  Created on: 5 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include"../../SERVICES/STD_Types.h"
#include"DIO_config.h"
#include"DIO_private.h"
#include"../../SERVICES/BIT_Math.h"




Std_ReturnType GPIO_pin_direction_intialize(const ST_pin_config_t *_pin_config);
Std_ReturnType GPIO_pin_get_direction_status(const ST_pin_config_t *_pin_config , EN_direction_t *direction_status);
Std_ReturnType GPIO_pin_write_logic(const ST_pin_config_t *_pin_config , EN_logic_t logic);
Std_ReturnType GPIO_pin_read_logic(const ST_pin_config_t *_pin_config , EN_logic_t *logic_status);
Std_ReturnType GPIO_pin_toggle_logic(const ST_pin_config_t *_pin_config);
Std_ReturnType GPIO_pin_intialize(const ST_pin_config_t *_pin_config);




Std_ReturnType GPIO_port_direction_intialize(EN_port_index_t port , Uchar8_t direction);
Std_ReturnType GPIO_port_get_direction_status(EN_port_index_t port , Uchar8_t *direction_status);
Std_ReturnType GPIO_port_write_logic(EN_port_index_t port , Uchar8_t logic);
Std_ReturnType GPIO_port_read_logic(EN_port_index_t port , Uchar8_t *logic_status);
Std_ReturnType GPIO_port_toggle_logic(EN_port_index_t port);





#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
