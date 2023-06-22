#include "TM4C123.h"
#include "C:\Users\Speed\Documents\Mcu_Hw.h"
#include "C:\Users\Speed\Documents\BIT_MATH.h"
#include "GPT_lcfg.h"
#define GPT_CFG_NOT_CONCATE_BIT 2
#define GPT_TAMR_ONR_SHOT_MODE_A 0
#define GPT_TAMR_CONTINUOUS_MODE_A 1
#define GPT_TAMR_DIRECTION_A 4
#define GPT_TAMR_ONR_SHOT_MODE_B 0
#define GPT_TAMR_CONTINUOUS_MODE_B 1
#define GPT_TAMR_DIRECTION_B 4
#define GPT_CTL_STAL_BIT 1
#define GPT_TIMER_A_ENABLE 0
#define GPT_TIMER_B_ENABLE 8
#define GPT_TIMER_A_ENABLE_INTURRPT 0
#define TIMER_CONFIGRATION_32 0
#define F_CPU 16000000.0
#define MILISCOUND_CONVERT  1000.0
 extern void (*TIMER0A_Callback)(void) ;

Gpt_State Gpt_init(Gpt_ConfigType *Config);
Gpt_State GPT_enable_intturpt(Gpt_ChannelType channel_id);
 Gpt_State GPT_disable_intturpt(Gpt_ChannelType channel_id);
Gpt_State PWM_Init(uint32_t ui32Period, uint8_t ui8DutyCycle);
 Gpt_State GPT_Start_Timer(Gpt_ChannelType channel_id,uint32_t u32_time);
 Gpt_State GPT_STOP_Timer(Gpt_ChannelType channel_id);
 Gpt_State GPT_GetElapsedTime(Gpt_ChannelType channel_id,Timer_Use timer_use, uint32_t *time);
 Gpt_State GPT_GetRemainingTime(Gpt_ChannelType channel_id,Timer_Use timer_use,uint32_t time);
