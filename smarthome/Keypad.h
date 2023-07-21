/*
 * Keypad.h
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Types_Macros.h"

#define NUM_OF_COL 3
#define NUM_OF_ROW 4
#define KEYPAD_DDRX DDRC
#define KEYPAD_PORTX PORTC
#define KEYPAD_PINX PINC
#define FIRST_COL PC4
#define FIRST_ROW PC0

uint8 get_Value(void);


#endif /* KEYPAD_H_ */
