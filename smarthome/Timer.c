/*
 * Timer.c
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#include "avr/io.h"
#include <avr/interrupt.h>
#include "Timer.h"
#include "LCD.h"
#include "Servo.h"
#include "Lm35_sensor.h"

uint8 trick = 0;

ISR(TIMER0_OVF_vect)
{
	trick++;
	SET_BIT(PORTD,6);
	TOGGLE_BIT(PORTD,0);
	if(trick == 97)
	{
		CLEAR_BIT(PORTD,0);
		CLEAR_BIT(PORTD,6);
		trick=0;
		Timer_DeInit(TIMER0);
	}
}
ISR(TIMER0_COMP_vect)
{

}
ISR(TIMER1_OVF_vect)
{

}
ISR(TIMER1_COMPA_vect)
{

}
ISR(TIMER2_OVF_vect)
{
	trick++;
	servo_init();
	servo_rotate(90);
	if(trick == 97)
	{
		servo_rotate(0);
		trick = 0;
		Timer_DeInit(TIMER2);
	}

}
ISR(TIMER2_COMP_vect)
{

}

void Timer_init(const Timer_ConfigType* config_ptr){
	switch(config_ptr->number)
	{
	case TIMER0:
		TCNT0 = (uint8)config_ptr->initialCounter;
		SET_BIT(TCCR0,FOC0);
		TCCR0 = (TCCR0 & 0xF8) | (config_ptr->prescalar & 0x07);
		if (config_ptr->mode == COMPARE){
			SET_BIT(TCCR0,WGM01);
			OCR0 = (uint8)config_ptr->compareValue;
			SET_BIT(TIMSK,OCIE0);
		}
		else if(config_ptr->mode == NORMAL){
			SET_BIT(TIMSK,TOIE0);
		}
		break;
	case TIMER1:
		TCNT1 = config_ptr->initialCounter;
		SET_BIT(TCCR1A, FOC1A);
		SET_BIT(TCCR1A, FOC1B);
		TCCR1B = (TCCR1B & 0xF8) | (config_ptr->prescalar & 0x07);
		if (config_ptr->mode == COMPARE){
			SET_BIT(TCCR1B,WGM12);
			OCR1A = config_ptr->compareValue;
			SET_BIT(TIMSK,OCIE1A);
		}
		else if(config_ptr->mode == NORMAL){
			SET_BIT(TIMSK,TOIE1);
		}
		break;
	case TIMER2 :
		TCNT2 = (uint8)config_ptr->initialCounter;
		SET_BIT(TCCR2,FOC2);
		TCCR2 = (TCCR2 & 0xF8) | (config_ptr->prescalar & 0x07);
		if (config_ptr->mode == COMPARE){
			SET_BIT(TCCR2,WGM21);
			OCR2 = (uint8)config_ptr->compareValue;
			SET_BIT(TIMSK,OCIE2);
		}
		else if(config_ptr->mode == NORMAL){
			SET_BIT(TIMSK,TOIE2);
		}
		break;
	}
}

void Timer_DeInit(Timer_Number number){
	switch(number)
	{
	case TIMER0:
		TCCR0 = 0;
		TCNT0 = 0;
		OCR0 = 0;
		CLEAR_BIT(TIMSK,TOIE0);
		CLEAR_BIT(TIMSK,OCIE0);
		break;
	case TIMER1:
		TCCR1A = 0;
		TCCR1B = 0;
		TCNT1 = 0;
		OCR1A = 0;
		OCR1B = 0;
		CLEAR_BIT(TIMSK,TOIE1);
		CLEAR_BIT(TIMSK,OCIE1A);
		CLEAR_BIT(TIMSK,OCIE1B);
		break;
	case TIMER2:
		TCCR2 = 0;
		TCNT2 = 0;
		OCR2 = 0;
		CLEAR_BIT(TIMSK,TOIE2);
		CLEAR_BIT(TIMSK,OCIE2);
		break;
	}
}
