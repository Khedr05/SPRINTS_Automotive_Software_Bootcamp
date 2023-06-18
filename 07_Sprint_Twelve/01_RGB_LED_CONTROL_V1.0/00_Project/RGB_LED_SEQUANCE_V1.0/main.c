
#include "app.h"


/*
0x40000000,0x400FFFFF
*/
int main (void)
{
app_init();

	while(1)
	{
		app_superloop();

}
}