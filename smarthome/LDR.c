/*
 * LDR.c
 *
 *  Created on: Apr 18, 2022
 *      Author: dell
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Types_Macros.h"
#include "ADC.h"
#include "LCD.h"
#include "LDR.h"

uint8 HI[11] = "Lights on.";
uint8 LO[12] = "Lights off.";

uint16 LDR_readint(void)
{
	uint16 int_value = 0;
    uint16 adc_value = 0;
    adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	int_value = (uint16)(((uint64)adc_value*SENSOR_MAX_INTENSITY*ADC_V_REF)/(MAX_VALUE_ADC_REP*SENSOR_MAX_VOLT_VALUE));
	return int_value;
}

void LDR_check()
{
	/* if it less than 400 lights on */
	if(LDR_readint() <= 400)
	{
		SET_BIT(PORTA,7);
		SET_BIT(PORTA,6);
		SET_BIT(PORTA,5);

		LCD_SendCommand(DISPLAY_CLEAR);
		_delay_ms(20);
		LCD_PrintString(HI);
		_delay_ms(20);
		LCD_SendCommand(NEXT_LINE);
		_delay_ms(20);
		LCD_intgerToString(LDR_readint());
		_delay_ms(500);
	}
	else
	{
		CLEAR_BIT(PORTA,7);
		CLEAR_BIT(PORTA,6);
		CLEAR_BIT(PORTA,5);

		LCD_SendCommand(DISPLAY_CLEAR);
		_delay_ms(20);
		LCD_PrintString(LO);
		_delay_ms(20);
		LCD_SendCommand(NEXT_LINE);
		_delay_ms(20);
		LCD_intgerToString(LDR_readint());// display the temp
		_delay_ms(500);
	}
}
