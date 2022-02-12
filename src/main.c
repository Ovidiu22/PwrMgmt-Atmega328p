/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	15th January 2022	 ***/
/*******************************/

#include "Defines.h"
#include "PowerManagement.h"

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>

volatile int f_wdt = 1;


int main(void)
{
	/* Set LED pin as output */
	LED_DDR |= 1<<LED_pin;
	
	while( f_wdt == 1)
	{
		/* Some sequence */
		LED_port |= (1<<LED_pin);	// Turn LED on
		_delay_ms(3000);			// Wait 3 sec
		LED_port &= ~(1<<LED_pin);	// Turn LED off
		_delay_ms(3000);			// Wait 3 sec to stabilize current -> reference for sleep modes measurements
	
		/* Clear the watchdog flag */
		f_wdt = 0;
		
		/* Power management */
		PwrMngmnt_main();
	}
	return 0;
}

/***************************************************
 *  Name:        ISR(WDT_vect)
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Watchdog Interrupt Service. This
 *               is executed when watchdog timed out.
 *
 ***************************************************/
ISR(WDT_vect)
{
	if(f_wdt == 0)
	{
		f_wdt = 1;
	}

}