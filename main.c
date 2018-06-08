#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

/**
 * Arduino registers
 * B (digital pin 8 to 13)
 * C (analog input pins)
 * D (digital pins 0 to 7)
*/

enum bits {
	BIT_0 = (1 << 0),
	BIT_1 = (1 << 1),
	BIT_2 = (1 << 2),
	BIT_3 = (1 << 3),
	BIT_4 = (1 << 4),
	BIT_5 = (1 << 5),
	BIT_6 = (1 << 6),
	BIT_7 = (1 << 7)
};

uint8_t switch_state(volatile uint8_t* pin_set, const uint8_t bit_num);
uint8_t toggle_state(volatile uint8_t* pin_set, const uint8_t bit_num, const uint8_t prev_state);
void set_port(volatile uint8_t* port_set, const uint8_t bit_num, const uint8_t state);

int main()
{
	DDRB &= BIT_0; // set DDRB bit 0 as an input
	DDRD |= BIT_0 | BIT_1 | BIT_2; // set DDRD bit 0, 1 & 2 as outputs

	uint8_t switch_1 = 0; // set initial state of switch

	while(1)
	{
		switch_1 = toggle_state(&PINB, BIT_0, switch_1);

		set_port(&PORTD, BIT_0, switch_1);
		set_port(&PORTD, BIT_1, switch_1);
		set_port(&PORTD, BIT_2, switch_1);
	}

	return 0;
}

uint8_t switch_state(volatile uint8_t* pin_set, const uint8_t bit_num)
{
	if (*pin_set & bit_num)
	{
		_delay_ms(50);
		if (*pin_set & bit_num)
		{
			return 1;
		}
	}
	return 0;
}

uint8_t toggle_state(volatile uint8_t* pin_set, const uint8_t bit_num, const uint8_t prev_state)
{
	if (*pin_set & bit_num)
	{
		_delay_ms(50);
		if (*pin_set & bit_num)
		{
			_delay_ms(50);
			return (prev_state == 0) ? 1 : 0;
		}
	}
	return prev_state;
}

void set_port(volatile uint8_t* port_set, const uint8_t bit_num, const uint8_t state)
{
	if (state)
	{
		*port_set |= bit_num;
	}
	else
	{
		*port_set &= ~bit_num;
	}
}

