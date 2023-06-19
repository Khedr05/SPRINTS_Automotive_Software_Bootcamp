#ifndef PORT_TYPES_H
#define PORT_TYPES_H

#define PORT_PINS_NUMS 1
typedef enum {
  PORT_MODE_DIGITAL,
    PORT_MODE_ANALOG,
    PORT_MODE_ALTERNATE,
	PORT_MODE_INTTERUPT
} Port_PinModeType;

typedef enum {
    PORT_PIN_LEVEL_LOW,
    PORT_PIN_LEVEL_HIGH
} Port_PinLevel;

typedef enum {
    PORT_PIN_DIRECTION_IN,
    PORT_PIN_DIRECTION_OUT
} Port_PinDirectionType;

typedef enum {
    PORT_PIN_PUR,
    PORT_PIN_PDR,
	  PORT_PIN_ODR,
	PORT_PIN_RES_INVALID
} Port_PinInternalAttachType;

typedef enum {
    PORT_PIN_OUTPUT_CURRENT_2MA,
    PORT_PIN_OUTPUT_CURRENT_4MA,
    PORT_PIN_OUTPUT_CURRENT_8MA
} Port_PinOutputCurrentType;

typedef enum {
    PORTA=0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
} Port_Num;

typedef enum {
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} Port_PinNum;

typedef enum {
Port_pin,   
	Port_Int
	  	
} Port_Int_Pin;
typedef enum {
    IntSense_Edges,
	  IntSense_Levels	
} Port_IntSense;
typedef enum {
    IntEvent_Falling,
	  IntEvent_Rising,	
	  IntEvent_Both
} Port_IntEvent;
typedef enum {
    IntEvent_Masked,
	  IntEvent_UnMaske	
} Port_IntMask;
typedef enum {
    PORT_OK,
    PORT_INVALID_PARAM,
    PORT_ERROR
} Port_ErrorCode;

typedef struct {
    Port_PinModeType PortPinMode;
    Port_PinLevel PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_PinInternalAttachType PortPinInternalAttach;
    Port_PinOutputCurrentType PortPinOutputCurrent;
    Port_Num PortNum;
    Port_PinNum PortPinNum;
	 Port_Int_Pin PortIntPin;
	Port_IntSense PortIntSense;
	Port_IntEvent PortIntEvent;
	Port_IntMask PortIntMask;
	
} Port_ConfigType;

#endif /* PORT_TYPES_H */