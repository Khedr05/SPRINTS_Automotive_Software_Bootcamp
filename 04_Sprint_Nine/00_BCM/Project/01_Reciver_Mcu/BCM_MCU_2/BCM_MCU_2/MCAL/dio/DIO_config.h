/*
 * DIO_config.h
 *
 *  Created on: 5 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

#include"../../COMMON/std_types.h"

#define CONFIG_ENABLE  1
#define CONFIG_DISABLE  0

#define GPIO_CONFIGURATIONS		CONFIG_ENABLE

#define PORT_PIN_MAX_NUMBER      7
#define PORT_MAX_NUMBER          4

#define PORT_TOOGLE_MASK               0xFF


/*
Enum : EN_logic_t

Description: Enumeration for the two possible logic states of a GPIO (General Purpose Input/Output) 
pin on a micro-controller.

Members:
-  GPIO_LOGIC_LOW  : This member represents the logic level of a GPIO pin when it is set to low (0V).
-  GPIO_LOGIC_HIGH : This member represents the logic level of a GPIO pin when it is set to high 
					 (3.3V or 5V depending on the specific micro-controller).

Overall, the EN_logic_t enumeration provides a standardized way to represent and configure the logic 
levels of GPIO pins on a micro-controller, making it easier to write and maintain software that interacts 
with these pins.
*/
typedef enum{
    GPIO_LOGIC_LOW = 0,
    GPIO_LOGIC_HIGH
}EN_logic_t;


/*
Enum : EN_direction_t

Description: Enumeration for the two possible directions of a GPIO (General Purpose Input/Output) 
pin on a micro-controller.

Members:
-  GPIO_DIRECTION_INPUT	 : This member represents the direction of a GPIO pin when it is set to input mode,
						   allowing it to receive and read external signals.
-  GPIO_DIRECTION_OUTPUT : This member represents the direction of a GPIO pin when it is set to output mode, 
						   allowing it to send signals to external devices.
Overall, the EN_direction_t enumeration provides a standardized way to represent and configure the direction 
of GPIO pins on a micro-controller, making it easier to write and maintain software that interacts 
with these pins.
*/
typedef enum
{
    GPIO_DIRECTION_INPUT = 0,
    GPIO_DIRECTION_OUTPUT
}EN_direction_t;



/*
Enum : EN_pin_index_t

Description	: Enumeration for the index of each GPIO (General Purpose Input/Output) pin on a port.

Members:
- GPIO_PIN0	: This member represents the index of the first GPIO pin on a port.
- GPIO_PIN1	: This member represents the index of the second GPIO pin on a port.
- GPIO_PIN2	: This member represents the index of the third GPIO pin on a port.
- GPIO_PIN3	: This member represents the index of the fourth GPIO pin on a port.
- GPIO_PIN4	: This member represents the index of the fifth GPIO pin on a port.
- GPIO_PIN5	: This member represents the index of the sixth GPIO pin on a port.
- GPIO_PIN6	: This member represents the index of the seventh GPIO pin on a port.
- GPIO_PIN7	: This member represents the index of the eighth GPIO pin on a port.

Overall, the EN_pin_index_t enumeration provides a standardized way to represent and identify each 
GPIO pin on a port, making it easier to write and maintain software that interacts with these pins.
*/
typedef enum
{
   GPIO_PIN0 = 0,
   GPIO_PIN1,
   GPIO_PIN2,
   GPIO_PIN3,
   GPIO_PIN4,
   GPIO_PIN5,
   GPIO_PIN6,
   GPIO_PIN7
}EN_pin_index_t;


/*
Enum : EN_port_index_t

Description	 : Enumeration for the index of each GPIO (General Purpose Input/Output) port on a micro-controller.

Members :
- GPIO_PORTA_INDEX : This member represents the index of the first GPIO port on a micro-controller.
- GPIO_PORTB_INDEX : This member represents the index of the second GPIO port on a micro-controller.
- GPIO_PORTC_INDEX : This member represents the index of the third GPIO port on a micro-controller.
- GPIO_PORTD_INDEX : This member represents the index of the fourth GPIO port on a micro-controller.

Overall, the EN_port_index_t enumeration provides a standardized way to represent and identify each 
GPIO port on a micro-controller, making it easier to write and maintain software that interacts 
with these ports and their associated pins.
*/
typedef enum
{
    GPIO_PORTA_INDEX = 0,
    GPIO_PORTB_INDEX,
    GPIO_PORTC_INDEX,
    GPIO_PORTD_INDEX,
}EN_port_index_t;

/*
Struct : ST_pin_config_t

Description  : A structure that contains the configuration settings for a GPIO (General Purpose Input/Output)
pin on a micro-controller.

Members:
-  port		 : A 3-bit field that specifies the index of the GPIO port to which the pin belongs (0-3).
-  pin		 : A 3-bit field that specifies the index of the GPIO pin on the port (0-7).
-  direction : A 1-bit field that specifies the direction of the GPIO pin (input or output).
-  logic	 : A 1-bit field that specifies the logic level of the GPIO pin (high or low).

Overall, the ST_pin_config_t structure provides a standardized way to represent and configure the settings 
for a single GPIO pin on a micro-controller, making it easier to write and maintain software that interacts
with these pins. The use of bit fields for the port, pin , direction , and logic members allows for 
efficient use of memory and reduces the size of the structure. The Uchar8_t type is likely a custom data 
type defined in the software to represent an 8-bit unsigned character.
*/

typedef struct
{
    Uchar8_t port : 3;
    Uchar8_t pin : 3;
    Uchar8_t direction : 1;
    Uchar8_t logic : 1;
}ST_pin_config_t;


#endif /* MCAL_DIO_DIO_CONFIG_H_ */
