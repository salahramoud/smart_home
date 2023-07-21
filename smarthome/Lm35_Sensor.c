/*
 * Lm35_Sensor.c
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#include <util/delay.h>
#include "Types_Macros.h"
#include "ADC.h"
#include "Lm35_Sensor.h"
#include "LCD.h"
#include "Servo.h"

uint8 HT[20] = "High temperature";
uint8 Units[3] = "'C";

uint8 LM35_readtemp(void)
{
	uint8 temp_value = 0;
    uint16 adc_value;
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_V_REF)/(MAX_VALUE_ADC_REP*SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}

void check()
{
	if(LM35_readtemp() >= 30)
	{
		SET_BIT(PORTA,7);
		SET_BIT(PORTA,6);
		SET_BIT(PORTA,5);

		SET_BIT(PORTD,6);

		servo_init();
		servo_rotate(90);

		LCD_SendCommand(DISPLAY_CLEAR);
		_delay_ms(20);
		LCD_PrintString(HT);
		_delay_ms(20);
		LCD_SendCommand(NEXT_LINE);
		_delay_ms(20);
		LCD_intgerToString(LM35_readtemp());
		_delay_ms(20);
		LCD_PrintString(Units);
		_delay_ms(20);
		while(LM35_readtemp()>=30)
		{
		}
		servo_rotate(0);
		CLEAR_BIT(PORTA,7);
		CLEAR_BIT(PORTA,6);
		CLEAR_BIT(PORTA,5);
		CLEAR_BIT(PORTD,6);
	}

}
