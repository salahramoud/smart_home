/*
 * ADC.h
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#ifndef ADC_H_
#define ADC_H_

#include "Types_Macros.h"

#define ADC_V_REF 5
#define MAX_VALUE_ADC_REP 1023

void ADC_init(void);

uint16 ADC_readChannel(uint8);

#endif /* ADC_H_ */
