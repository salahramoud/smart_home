/*
 * Lm35_Sensor.h
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "Types_Macros.h"
#include "ADC.h"

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

void ADC_init();

uint8 LM35_readtemp(void);

void check();

#endif /* LM35_SENSOR_H_ */
