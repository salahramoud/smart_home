/*
 * Servo.h
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>
#include "Types_Macros.h"
#include "Timer.h"

void servo_init();

void servo_rotate(float ang);

#endif /* SERVO_H_ */
