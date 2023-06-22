#include "TM4C123.h"
#include "app.h"


/*
0x40000000,0x400FFFFF
*/

int main (void)
{
app_init();

	//    PWM_Init(16000, 50); // Initialize PWM with 1 kHz frequency and 50% duty cycle

	while(1)
	{
		app_superloop();

}
}