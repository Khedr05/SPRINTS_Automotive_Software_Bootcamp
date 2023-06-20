
#include "TM4C123.h"
#include "std_types.h"
#include "dio_interface.h"
#include "PUSH_BTN_interface.h"
#include "led_interface.h"
#include "systick_interface.h"


extern ST_dio_pinCfg_t a_cfgPins[PINS_CFG_ARRAY_SIZE];

extern ST_led_pinCfg_t a_ledCfgPins[LED_PIN_CFG_ARRAY_SIZE];

extern ST_PUSH_BTN_pinCfg_t a_pushBtnCfgPins[PUSH_BTN_PIN_CFG_ARRAY_SIZE];

extern STR_SYSTICK_cfg_t a_systickCfg[SYSTICK_CFG_ARRAY_SIZE];

#define DEBOUNCING_ERROR_DETECT_1		200
#define DEBOUNCING_ERROR_DETECT_2		1000

#define PRESS_ONE                       1
#define PRESS_TWO						2
#define PRESS_THREE						3
#define PRESS_FOUR						4
#define PRESS_FIVE						5


#define SYSTICK_FLAG_FIRED				1

void app_init(void);
void app_superloop(void);
