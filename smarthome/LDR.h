/*
 * LDR.h
 *
 *  Created on: Apr 18, 2022
 *      Author: dell
 */

#ifndef LDR_H_
#define LDR_H_

#include "Types_Macros.h"
#include "ADC.h"

#define SENSOR_CHANNEL_ID         0
#define SENSOR_MAX_VOLT_VALUE     5
#define SENSOR_MAX_INTENSITY    1000

void ADC_init();

uint16 LDR_readint(void);

void LDR_check();

#endif /* LDR_H_ */
