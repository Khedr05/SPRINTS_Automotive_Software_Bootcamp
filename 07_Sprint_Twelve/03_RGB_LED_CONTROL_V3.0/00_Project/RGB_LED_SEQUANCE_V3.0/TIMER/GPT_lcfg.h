#include "STD_TYPES.h"
#include "stdint.h" 
#define MAX_CHANNELS 1
typedef enum {
    GPT_OK,                   // No error
    GPT_ERROR_INVALID_CHANNEL, // Invalid GPT channel
    GPT_ERROR_DISABLED,       // GPT is disabled
    GPT_ERROR_INVALID_MODE,    // Invalid GPT mode
    GPT_ERROR_INTERRUPT,       // Error configuring interrupts
    // Add more error codes as needed
} Gpt_State;
typedef enum {
    GPT_CHANNEL_0,
    GPT_CHANNEL_1,
    GPT_CHANNEL_2,
    GPT_CHANNEL_3,
	 GPT_CHANNEL_4,
    GPT_CHANNEL_5,
    GPT_CHANNEL_6,
    GPT_CHANNEL_7,
	 GPT_CHANNEL_8,
    GPT_CHANNEL_9,
    GPT_CHANNEL_10,
    GPT_CHANNEL_11,
	GPT_MAX_CHANNELS,
} Gpt_ChannelType;

typedef enum {
    GPT_MODE_CONTINUOUS,
    GPT_MODE_ONE_SHOT
} Gpt_ModeType;
typedef enum {
    up,
    down
} Count_Direction;


typedef enum {
    timerA,
    timerB,
    concatenated
} Timer_Use;





typedef struct {
    Gpt_ChannelType GptChannelId;
    Gpt_ModeType ChannelMode;
    Timer_Use      timeruse;
	Count_Direction   countdirection;

} Gpt_ConfigType;