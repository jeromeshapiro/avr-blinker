//#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include "bits.h"
#include "state.h"

/**
 * Arduino registers
 * B (digital pin 8 to 13)
 * C (analog input pins)
 * D (digital pins 0 to 7)
*/

int main()
{
	DDRD |= BIT_0 | BIT_1 | BIT_2 | BIT_4;

	uint8_t switch_1 = 0; // set initial state of switch
	uint8_t is_on;

	while(1)
	{
		switch_1 = toggle_state(&PIND, BIT_3, switch_1);
		is_on = switch_1;

		set_port(&PORTD, BIT_0, is_on);
		set_port(&PORTD, BIT_1, is_on);
		set_port(&PORTD, BIT_2, is_on);
	}

	return 0;
}

