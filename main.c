#include <stdint.h>
#include <avr/io.h>
#include "bits.h"
#include "blink.h"

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

	while(1)
	{
		switch_1 = toggle_state(&PIND, BIT_3, switch_1);
		blink_1(switch_1, &PORTD);
	}

	return 0;
}

