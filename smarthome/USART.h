/*
 * USART.h
 *
 *  Created on: Apr 19, 2022
 *      Author: dell
 */

#ifndef USART_H_
#define USART_H_

/***********************************************/
// These are Private Macros (Don't Modify them)
/*** Macros For USART Mode (Synchronous/Asynchronous) ***/
#define Syn            0
#define Asyn           1
/*** Macros For Communication Mode (Transmitter/Receiver/Tx_Rx) ***/
#define Tx             0
#define Rx             1
#define Tx_Rx          2
/*** Macros For Selecting the Data Length & Number of Stop Bits ***/
#define _1_Bit         0     // For Stop Bits
#define _2_Bits        1     // For Stop Bits
#define _5_Bits        2
#define _6_Bits        3
#define _7_Bits        4
#define _8_Bits        5
#define _9_Bits        6
/*** Macros For Selecting the Parity Bit Type***/
#define Disable_Parity 0
#define Even_Parity    1
#define Odd_Parity     2
/*** Macros For Selecting the Transmission Speed ***/
#define Default_Speed  0
#define Double_Speed   1
/*** Macros for Calculating the UBRR Value Based on The Specified Baud-Rate ***/
#define Calc_UBRR(Fosc,Baud,U2X)   ((Fosc * (U2X + 1) / (16 * Baud)) - 1)
/************************************************************/
/************************************************************/
// USART Configuration Macros
/*******************************/
#define USART_Mode           Asyn
/* Choices:
 * 1- Syn
 * 2- Asyn
 */
/*******************************/
#define Communication_Mode   Rx
/* Choices:
 * 1- Tx
 * 2- Rx
 * 3- Tx_Rx
 */
/*******************************/
#define Parity_Bit           Disable_Parity
/* Choices:
 * 1- Disable_Parity
 * 2- Even_Parity
 * 3- Odd_Parity
 */
/*******************************/
#define Data_Size            _8_Bits
/* Choices:
 * 1- _5_Bits
 * 2- _6_Bits
 * 3- _7_Bits
 * 4- _8_Bits
 * 5- _9_Bits
 */
/*******************************/
#define Stop_Bit             _1_Bit
/* Choices:
 * 1- _1_Bit
 * 2- _2_Bits
 */
/*******************************/
#define Baud_Rate            9600UL
/* Choices:
 * 1- 2400
 * 2- 4800
 * 3- 9600
 * 4- 14400
 * ...
 * ...
 */
/*******************************/
#define Transmission_Speed   Default_Speed
/* Choices:
 * 1- Default_Speed
 * 2- Double_Speed
 */
/************************************************************/
/************************************************************/
// Functions prototypes
void  USART_Init();
void  USART_SendData(uint8);
uint8 USART_ReceiveData();

#endif /* USART_H_ */
