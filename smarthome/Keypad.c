/*
 * Keypad.c
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Keypad.h"
#include "Types_Macros.h"

#if(NUM_OF_COL == 3)
static uint8 getTheRightValue4X3(uint8);
#endif

#if(NUM_OF_COL == 4)
static uint8 getTheRightValue4X4(uint8);
#endif

uint8 get_Value(){
	SET_BIT(KEYPAD_DDRX , FIRST_COL );
	SET_BIT(KEYPAD_DDRX , (FIRST_COL + 1) );
	SET_BIT(KEYPAD_DDRX , (FIRST_COL + 2) );

#if(NUM_OF_COL == 4)
	SET_BIT(KEYPAD_DDRX , (FIRST_COL + 3) );
#endif

	CLEAR_BIT(KEYPAD_DDRX , FIRST_ROW );
	CLEAR_BIT(KEYPAD_DDRX , (FIRST_ROW + 1) );
	CLEAR_BIT(KEYPAD_DDRX , (FIRST_ROW + 2) );
	CLEAR_BIT(KEYPAD_DDRX , (FIRST_ROW + 3) );

	uint8 col=0 , row =0;
	while(1){
		for(col=0 ; col < NUM_OF_COL ; col ++){
			CLEAR_BIT(KEYPAD_PORTX , FIRST_COL );
			CLEAR_BIT(KEYPAD_PORTX , (FIRST_COL + 1) );
			CLEAR_BIT(KEYPAD_PORTX , (FIRST_COL + 2) );
#if(NUM_OF_COL == 4)
			CLEAR_BIT(KEYPAD_PORTX , (FIRST_COL + 3) );
#endif

			SET_BIT(KEYPAD_PORTX , (FIRST_COL + col));

			for(row=0 ; row < NUM_OF_ROW ; row++){
				if(BIT_IS_SET(KEYPAD_PINX, (FIRST_ROW + row) )){
					_delay_ms(30);
					if(BIT_IS_SET(KEYPAD_PINX, (FIRST_ROW + row) )){

#if(NUM_OF_COL == 3)
						return getTheRightValue4X3((row * NUM_OF_COL) + col + 1);
#endif

#if(NUM_OF_COL == 4)
						return getTheRightValue4X4((row * NUM_OF_COL) + col + 1);
#endif
					}
				}
			}
		}
	}
}

#if(NUM_OF_COL == 3)

uint8 getTheRightValue4X3(uint8 value){
	uint8 number = value;
	switch(value){
	case 10:
		number = '*';
		break;
	case 11:
		number = 0;
		break;
	case 12:
		number = '#';
		break;
	default:
		number = value;
	}
	 return number;
}

#endif

#if(NUM_OF_COL == 4)

uint8 getTheRightValue4X4(uint8 value){
	uint8 number = value;
	switch(value){
	case 1:
		number = 7;
		break;
	case 2:
		number = 8;
		break;
	case 3:
		number = 9;
		break;
	case 4:
		number = '/';
		break;
	case 5:
		number = 4;
		break;
	case 6:
		number = 5;
		break;
	case 7:
		number = 6;
		break;
	case 8:
		number = '*';
		break;
	case 9:
		number = 1;
		break;
	case 10:
		number = 2;
		break;
	case 11:
		number = 3;
		break;
	case 12:
		number = '-';
		break;
	case 13:
		number = 13;
		break;
	case 14:
		number = 0;
		break;
	case 15:
		number = '=';
		break;
	case 16:
		number = '+';
		break;

	}
	 return number;
}

#endif
