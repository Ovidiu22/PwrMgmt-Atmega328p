#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "Defines.h"
#include "PowerManagement.h"


int main(void)
{
	LED_DDR |= 1<<LED_pin;
	
	while(1)
	{
		LED_DDR |= (1<<LED_pin);	// Turn LED on
		_delay_ms(1000);			// Wait 1 sec
		LED_DDR &= ~(1<<LED_pin);	// Turn LED off
	}
	
	PwrMngmnt_main();
	
	return 0;
}
