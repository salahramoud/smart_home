/*
 * LCD.h
 *
 *  Created on: Apr 16, 2022
 *      Author: dell
 */

#ifndef LCD_H_
#define LCD_H_

typedef enum{
	DISPLAY_CLEAR = 0x01,
	HOME_RETURN = 0x02,
	ENTERY_MODE = 0x06,
	DISPLAY_ON_CURSOR_ON_BLINKING = 0x0F,
	DISPLAY_ON_CURSOR_ON = 0x0E,
	DISPLAY_ON_CURSOR_OFF = 0x0C,
	DISPLAY_OFF_CURSOR_OFF = 0x08,
	DISPLAY_SHIFT_RIGHT = 0x1C,
	DISPLAY_SHIT_LEFT = 0x18,
	CURSOR_SHIFT_RIGHT = 0x14,
	CURSOR_SHIFT_LEFT = 0x10,
	NEXT_LINE = 0xC0,
	FUNCTION_SET = 0x20
}COMMAND_LIST;

typedef enum{
	_4bits = 0x00,
	_8bits = 0x10
}DATA_LENGTH;

typedef enum{
	_1Line = 0x00,
	_2Line = 0x08
}NUM_LINES;

typedef enum{
	_5_8  = 0x00,
	_5_10 = 0x04
}MATRIX_FONT;

typedef enum{
	PortA,
	PortB,
	PortC,
	PortD
}_PORT;

typedef struct{
	uint8 RS_Pin;
	uint8 RW_Pin;
	uint8 EN_Pin;
	_PORT ControlPort;
	_PORT LCD_Port;
	DATA_LENGTH DL;
	NUM_LINES N;
	MATRIX_FONT F;
}Configuration;

void LCD_Init(const Configuration *);
void LCD_SendCommand(const uint8);
void LCD_PrintCharacter(const uint8);
void LCD_PrintString(const uint8 *);

#endif /* LCD_H_ */
