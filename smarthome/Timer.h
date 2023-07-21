/*
 * Timer.h
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Types_Macros.h"

typedef enum
{
	TIMER0,TIMER1,TIMER2
}Timer_Number;
typedef enum
{
	NORMAL,COMPARE
}Timer_Mode;
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Timer_Prescalar;

typedef struct
{
	Timer_Number number;
	Timer_Mode mode;
	Timer_Prescalar prescalar;
	uint16 initialCounter;
	uint16 compareValue;
}Timer_ConfigType;

void Timer_init(const Timer_ConfigType* config_ptr);

void Timer_DeInit(Timer_Number number);

#endif /* TIMER_H_ */
