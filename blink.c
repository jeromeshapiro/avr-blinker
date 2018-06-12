#include "blink.h"
#include "state.h"
#include "bits.h"

static uint32_t time = 0;
static uint8_t cycle = 0;

void blink_1(uint8_t is_on, volatile uint8_t* pin_set)
{
	if (is_on)
	{
		switch (cycle)
		{
			case 0:
				set_port(pin_set, BIT_0, 1);
				set_port(pin_set, BIT_1, 0);
				set_port(pin_set, BIT_2, 0);
				break;
			case 1:
				set_port(pin_set, BIT_0, 0);
				set_port(pin_set, BIT_1, 1);
				set_port(pin_set, BIT_2, 0);
				break;
			case 2:
				set_port(pin_set, BIT_0, 0);
				set_port(pin_set, BIT_1, 0);
				set_port(pin_set, BIT_2, 1);
				break;
		}

		if (++time >= 20000)
		{
			if (cycle == 0)
			{
				cycle = 1;
			}
			else if (cycle == 1)
			{
				cycle = 2;
			}
			else if (cycle == 2)
			{
				cycle = 0;
			}
			time = 0;
		}
	}
	else
	{
		set_port(pin_set, BIT_0, 0);
		set_port(pin_set, BIT_1, 0);
		set_port(pin_set, BIT_2, 0);
		time = 0;
		cycle = 0;
	}
}

