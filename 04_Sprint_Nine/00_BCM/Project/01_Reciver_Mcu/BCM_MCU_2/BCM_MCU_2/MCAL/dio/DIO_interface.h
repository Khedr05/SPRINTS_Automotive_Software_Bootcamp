/*
 * DIO_interface.h
 *
 *  Created on: 5 Apr 2023
 *      Author: 20101
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include"../../COMMON/std_types.h"
#include"DIO_config.h"
#include"DIO_private.h"
#include"../../COMMON//bit_math.h"


/*
Function: GPIO_pin_direction_intialize

Description: Initializes the direction of a GPIO pin on a micro-controller 
			 based on the pin configuration specified in the input parameter.

Parameters: _pin_config: A pointer to an instance of the ST_pin_config_t struct that contains 
the pin number, port number, pin logic on the pin and desired direction of the GPIO pin.

Return Type: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
		     software development to indicate the success or failure of a function call. 
The possible return values for this function are:
E_OK	: The function has completed successfully.
E_NOT_OK: The function has encountered an error and could not complete successfully.

Overall, the GPIO_pin_direction_intialize function provides a way to initialize the direction of a GPIO pin 
based on its configuration, allowing the software to set the direction of the pin 
as needed for its specific functionality.
*/

Std_ReturnType GPIO_pin_direction_intialize(const ST_pin_config_t *_pin_config);

/*
Function: GPIO_pin_get_direction_status

Description: Gets the current direction status of a GPIO (General Purpose Input/Output) pin on a micro-controller
			 based on the pin configuration specified in the input parameter.

Parameters:
- _pin_config		: A pointer to an instance of the ST_pin_config_t struct that contains the pin number, 
					  port number,pin logic and desired direction of the GPIO pin.
- direction_status  : A pointer to a variable of type EN_direction_t where the current direction status of
                      the GPIO pin will be stored.

Return Type	: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
			  software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		: The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.

Overall, the GPIO_pin_get_direction_status function provides a way to retrieve the current direction status of
a GPIO pin based on its configuration, allowing the software to check the pin's direction as needed.
*/

Std_ReturnType GPIO_pin_get_direction_status(const ST_pin_config_t *_pin_config , EN_direction_t *direction_status);


/*
Function: GPIO_pin_write_logic

Description : Writes the logic level of a GPIO (General Purpose Input/Output) pin on a micro-controller based on 
			  the pin configuration and desired logic level specified in the input parameters.

Parameters:
- _pin_config : A pointer to an instance of the ST_pin_config_t struct that contains the pin number, 
				port number, pin logic and current direction of the GPIO pin.
- logic		  : The desired logic level to be written to the GPIO pin, either GPIO_LOGIC_LOW or GPIO_LOGIC_HIGH.

Return Type   : Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
				software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		  : The function has completed successfully.
-  E_NOT_OK   : The function has encountered an error and could not complete successfully.

Overall, the GPIO_pin_write_logic function provides a way to write a logic level to a GPIO pin based on 
its configuration, allowing the software to set the output of the pin as needed for its specific functionality.
*/
Std_ReturnType GPIO_pin_write_logic(const ST_pin_config_t *_pin_config , EN_logic_t logic);

/*
Function: GPIO_pin_read_logic

Description: Reads the current logic level of a GPIO (General Purpose Input/Output) pin on a micro-controller 
			 based on the pin configuration specified in the input parameter.

Parameters:
-  _pin_config	: A pointer to an instance of the ST_pin_config_t struct that contains the pin number, 
				  port number, pin logic and current direction of the GPIO pin.
-  logic_status : A pointer to a variable of type EN_logic_t where the current logic level of the 
			      GPIO pin will be stored.

Return Type: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
			 software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		: The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.


Overall, the GPIO_pin_read_logic function provides a way to read the current logic level of a GPIO pin based on 
its configuration, allowing the software to check the input of the pin as needed for its specific functionality.
The current logic level is stored in the logic_status parameter.
*/

Std_ReturnType GPIO_pin_read_logic(const ST_pin_config_t *_pin_config , EN_logic_t *logic_status);

/*
Function: GPIO_pin_toggle_logic

Description: Toggles the logic level of a GPIO (General Purpose Input/Output) pin on a micro-controller based on
			 the pin configuration specified in the input parameter.

Parameters:
-  _pin_config : A pointer to an instance of the ST_pin_config_t struct that contains the pin number, 
				port number, pin logic and current direction of the GPIO pin.

Return Type : Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
			 software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		: The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.


Overall, the GPIO_pin_toggle_logic function provides a way to toggle the logic level of a GPIO pin based on 
its configuration, allowing the software to change the output of the pin between high and low states as 
needed for its specific functionality.
*/
Std_ReturnType GPIO_pin_toggle_logic(const ST_pin_config_t *_pin_config);


/*
Function: GPIO_pin_intialize

Description		: Initializes a GPIO (General Purpose Input/Output) pin on a micro-controller based on 
				  the pin configuration specified in the input parameter.

Parameters:
-  _pin_config : A pointer to an instance of the ST_pin_config_t struct that contains the pin number, 
				 port number, direction, and initial logic level of the GPIO pin.

Return Type		: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
				  software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		: The function has completed successfully.
-  E_NOT_OK : The function has encountered an error and could not complete successfully.


Overall, the GPIO_pin_intialize function provides a way to initialize a GPIO pin based 
on its configuration, allowing the software to set the initial direction and logic level 
of the pin as needed for its specific functionality.
*/
Std_ReturnType GPIO_pin_intialize(const ST_pin_config_t *_pin_config);


/*
Function     : GPIO_port_direction_intialize

Description	 : Initializes the direction of all GPIO (General Purpose Input/Output) pins on a micro-controller 
			   port based on the port index and desired direction specified in the input parameters.

Parameters:
-  port		 : The index of the GPIO port on the micro-controller, specified as a member of 
			   the EN_port_index_t enumeration.
-  direction : The desired direction for all GPIO pins on the port in hex.

Return Type	 : Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
			   software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK		 : The function has completed successfully.
-  E_NOT_OK  : The function has encountered an error and could not complete successfully.

Overall, the GPIO_port_direction_intialize function provides a way to initialize the direction of all GPIO 
pins on a port based on the port index and desired direction, allowing the software to set the initial 
direction of all pins on the port as needed for its specific functionality.
*/
Std_ReturnType GPIO_port_direction_intialize(EN_port_index_t port , Uchar8_t direction);

/*
Function		: GPIO_port_get_direction_status

Description		: Gets the current direction status of all GPIO (General Purpose Input/Output) pins on 
				  a micro-controller port based on the port index specified in the input parameter.

Parameters		:
-  port			: The index of the GPIO port on the micro-controller, specified as a member of the 
				  EN_port_index_t enumeration.
-  direction_status : A pointer to an 8-bit unsigned character where the current direction status of all GPIO
 pins on the port will be stored. Each bit in the character corresponds to a pin on the port, 
 with a value of 1 indicating the pin is set to output and a value of 0 indicating the pin is set to input.

Return Type		: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
				  software development to indicate the success or failure of a function call. 
The possible return values for this function are:
-  E_OK			: The function has completed successfully.
-  E_NOT_OK		: The function has encountered an error and could not complete successfully.


Overall, the GPIO_port_get_direction_status function provides a way to retrieve the current direction status 
of all GPIO pins on a port based on its index, allowing the software to check the direction of the pins as needed.
The current direction status is stored in the direction_status parameter as an 8-bit unsigned
character, with each bit corresponding to a pin on the port.
*/
Std_ReturnType GPIO_port_get_direction_status(EN_port_index_t port , Uchar8_t *direction_status);


/*
Function		: GPIO_port_write_logic

Description		: Writes the logic level to all GPIO (General Purpose Input/Output) pins on a micro-controller 
				  port based on the port index and desired logic level specified in the input parameters.

Parameters:
- port			: The index of the GPIO port on the micro-controller, specified as a member of the 
				  EN_port_index_t enumeration.
- logic			: The desired logic level to be written to all GPIO pins on the port. Each bit in the 8-bit 
				  unsigned character corresponds to a pin on the port, with a value of 1 indicating a high logic
				  level and a value of 0 indicating a low logic level.

Return Type: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
software development to indicate the success or failure of a function call. 
The possible return values for this function are:
- E_OK			: The function has completed successfully.
- E_NOT_OK		: The function has encountered an error and could not complete successfully.


Overall, the GPIO_port_write_logic function provides a way to write the same logic level to all GPIO pins on
a port based on its index, allowing the software to set the output of all pins on the port as needed for its 
specific functionality. The desired logic level is specified in the logic parameter as an 8-bit unsigned 
character, with each bit corresponding to a pin on the port.
*/
Std_ReturnType GPIO_port_write_logic(EN_port_index_t port , Uchar8_t logic);

/*
Function		: GPIO_port_read_logic

Description		: Reads the current logic level of all GPIO (General Purpose Input/Output) pins on a 
				  micro-controller port based on the port index specified in the input parameter.
			  
Parameters:
-  port			: The index of the GPIO port on the micro-controller, specified as a member of the 
				  EN_port_index_t enumeration.
-  logic_status : A pointer to an 8-bit unsigned character where the current logic level of all GPIO pins on the
				  port will be stored. Each bit in the character corresponds to a pin on the port, with a 
				  value of 1 indicating a high logic level and a value of 0 indicating a low logic level.

Return Type		: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
software development to indicate the success or failure of a function call. 
The possible return values for this function are:
E_OK			: The function has completed successfully.
E_NOT_OK		: The function has encountered an error and could not complete successfully.


Overall, the GPIO_port_read_logic function provides a way to read the current logic level of all GPIO pins 
on a port, allowing the software to check the input of the pins as needed for its specific functionality. 
The current logic level is stored in the logic_status parameter as an 8-bit unsigned character, with each 
bit corresponding to a pin on the port.
*/

Std_ReturnType GPIO_port_read_logic(EN_port_index_t port , Uchar8_t *logic_status);

/*
Function		: GPIO_port_toggle_logic

Description		: Toggles the logic level of all GPIO (General Purpose Input/Output) pins on a micro-controller
				  port based on the port index specified in the input parameter.

Parameters:
-  port			: The index of the GPIO port on the micro-controller, specified as a member of the 
				  EN_port_index_t enumeration.

Return Type		: Std_ReturnType. This is a standard type used in AUTOSAR (Automotive Open System Architecture) 
				  software development to indicate the success or failure of a function call. 
The possible return values for this function are:
- E_OK			: The function has completed successfully.
- E_NOT_OK		: The function has encountered an error and could not complete successfully.

Overall, the GPIO_port_toggle_logic function provides a way to toggle the logic level of all GPIO pins on 
a port based on its index, allowing the software to change the output of all pins on the port between high 
and low states as needed for its specific functionality.
*/
Std_ReturnType GPIO_port_toggle_logic(EN_port_index_t port);





#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
