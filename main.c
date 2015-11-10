#include <msp430.h> 

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	// initialize timer
	DCOCTL = CALDCO_16MHZ;  			// |Set clock speed to 1 MHz|
	BCSCTL1 = CALBC1_16MHZ;  			// |                        |

	// setup Timer A
	// SMCLK clock, divided by 8, in up mode, and start by clearing the timer
	TACTL = TASSEL_2 | ID_3 | MC_1 | TACLR;

	// setup value for comparison
	// Create a timer interrupt which occurs at (700*32) Hz
	// 16 MHz / 8 = 2 MHz --> 90 ticks per 45 us
	TACCR0 = 90;

	// enable interrupt on capture-compare control register 0
	TACCTL0 |= CCIE;

	return 0;
}
