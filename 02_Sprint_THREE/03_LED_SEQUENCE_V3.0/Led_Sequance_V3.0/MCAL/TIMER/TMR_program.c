
#include"TMR_interface.h"

#include <avr/io.h>

void delay_ms(uint16_t delay_time)
{
    TCCR1A = 0;
    TCCR1B = (1 << CS01) | (1 << CS00);
    uint16_t timer_counts = (F_CPU / 64UL) * (delay_time / 1000.0);
    TCNT1 = 0;
    while (TCNT1 < timer_counts);
    TCCR1B = 0;
}
