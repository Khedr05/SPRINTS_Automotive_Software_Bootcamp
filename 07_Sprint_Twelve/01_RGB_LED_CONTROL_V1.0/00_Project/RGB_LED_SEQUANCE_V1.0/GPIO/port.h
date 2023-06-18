

#include "TM4C123.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_Hw.h"
#include "port_lcfg.h"



typedef void (*InterruptHandler)(void);


// Define the 2D array for interrupt handlers

extern InterruptHandler interruptHandlers[6][8];




void Port_Init( Port_ConfigType* ConfigPtr);
void GPIO_Write(Port_Num port_num, Port_PinNum pin_num, uint8_t value);
void GPIO_Read(Port_Num port_num, Port_PinNum pin_num,Port_PinLevel* value);
void GPIO_Toggle(Port_Num port_num, Port_PinNum pin_num);
void GPIO_Enable_Interrupt(Port_Num port_num,Port_PinNum port_pinnum);
void GPIO_Disable_Interrupt(Port_Num,Port_PinNum);
