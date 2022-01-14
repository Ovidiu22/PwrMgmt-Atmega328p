

#include "Defines.h"
#include "PowerManagement.h"

#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/io.h>
#include <util/delay.h>




int main(void)
{
	LED_DDR |= 1<<LED_pin;
	
	while(1)
	{
		LED_port |= (1<<LED_pin);	// Turn LED on
		_delay_ms(1000);			// Wait 1 sec
		LED_port &= ~(1<<LED_pin);	// Turn LED off
		_delay_ms(1000);			// Wait 1 sec
	}
	
	PwrMngmnt_main();
	
	return 0;
}
