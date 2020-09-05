#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Assign and cast the address of P1OUT to a pointer
	uint8_t *pP1OUT = (uint8_t*)0x40004C02;

	//Assign and cast the address of P1DIR to a pointer
	uint8_t *pP1DIR = (uint8_t*)0x40004C04;

	//Set all PORT1 as low
	*pP1OUT = 0b00000000;

	//Set P1.0 as output
	*pP1DIR = 0b00000001;

	unsigned int i;

	while(1){

	    //Toggle the led in P1.0
	    *pP1OUT ^= 0b00000001;

	    //Delay to see the led toggling
	    for(i = 0; i < 20000; i++);
	}
}
