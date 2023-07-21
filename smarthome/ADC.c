/*
 * ADC.c
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#include <avr/io.h>
#include "Types_Macros.h"
#include "ADC.h"

void ADC_init(void){
	ADMUX = 0;
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channel_num){
	ADMUX = 0XE0;
	ADMUX = ADMUX | (channel_num & (0X1F));
	SET_BIT(ADCSRA , ADSC);
	while(BIT_IS_CLEAR(ADCSRA , ADIF));
	SET_BIT(ADCSRA , ADIF);
	return ADC;
}
