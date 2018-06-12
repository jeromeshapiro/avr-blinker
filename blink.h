#ifndef BLINK_H_
#define BLINK_H_

#include <stdint.h>
#include "state.h"

void blink_1(uint8_t is_on, volatile uint8_t* pin_set);

#endif // BLINK_H_
