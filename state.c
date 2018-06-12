#include <util/delay.h>
#include "state.h"
#include "bits.h"

uint8_t set_state(volatile uint8_t* pin_set, const uint8_t bit_num)
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

