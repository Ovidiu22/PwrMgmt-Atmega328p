
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include "PowerManagement.h"

extern int f_wdt;

/* *****************************************************************
Name:		PwrMngmnt_main()
Inputs:		none
Outputs:	none
Description:main function of power management
******************************************************************** */
void PwrMngmnt_main(void)
{
	/* Initialize watchdog */
	PwrMngmnt_init();
	
	/* Start watchdog */
	WDG_TRIG;
	
	/* Re-enter sleep mode. */
	enterSleep();
}

/* *****************************************************************
Name:		PwrMngmnt_ini()
Inputs:		none
Outputs:	none
Description:initialization of power management / watchdog
******************************************************************** */
void PwrMngmnt_init(void)
{
  /* Clear the reset flag. */
  MCUSR &= ~(1<<WDRF);
  
  /* In order to change WDE or the prescaler, we need to
   * set WDCE (This will allow updates for 4 clock cycles).
   */
  WDTCSR |= (1<<WDCE) | (1<<WDE);

  /* set new watchdog timeout prescaler value */
  WDTCSR = 1<<WDP0 | 1<<WDP3; /* 8.0 seconds */
}

/* *****************************************************************
Name:		enterSleep()
Inputs:		none
Outputs:	none
Description:configures the sleep mode
******************************************************************** */
void enterSleep(void)
{
	
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   /* EDIT: could also use SLEEP_MODE_PWR_DOWN for lowest power consumption. */
  
  /* Enable sleep */
  sleep_enable();
  
  /* Now enter sleep mode. */
  sleep_mode();
  
  /* The program will continue from here after the WDT timeout*/
  sleep_disable(); /* First thing to do is disable sleep. */
  
  /* Re-enable the peripherals. */
  power_all_enable();
  
}