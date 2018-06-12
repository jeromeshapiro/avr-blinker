#ifndef STATE_H_
#define STATE_H_

#include <stdint.h>

uint8_t set_state(volatile uint8_t* pin_set, const uint8_t bit_num);
uint8_t toggle_state(volatile uint8_t* pin_set, const uint8_t bit_num, const uint8_t prev_state);
void set_port(volatile uint8_t* port_set, const uint8_t bit_num, const uint8_t state);

#endif // STATE_H_
