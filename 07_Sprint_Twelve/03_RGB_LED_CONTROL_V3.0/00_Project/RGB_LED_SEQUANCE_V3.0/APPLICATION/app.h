#include "TM4C123.h"
#include "port.h"
#include "BUTTON_interface.h"
#include "led_interface.h"
#include "C:\Users\Speed\Documents\gpio\GPT.h"
#define LED_PIN 0
#define PERIOD 500
#define FIRST_DUTY 30
#define SECOUND_DUTY 60
#define THIRD_DUTY 90

void app_init(void);
void app_superloop(void);
