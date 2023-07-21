/*
 * USART.c
 *
 *  Created on: Apr 19, 2022
 *      Author: dell
 */

#include <avr/io.h>
#include "Types_Macros.h"
#include "USART.h"

void  USART_Init(){
   // Select the Transmission Speed (Double / Default)
   #if Transmission_Speed == Double_Speed
   SET_BIT(UCSRA, 1);
   #endif
   // Select the USART Mode
   #if Communication_Mode == Tx
   SET_BIT(UCSRB, TXEN);
   #elif Communication_Mode == Rx
   SET_BIT(UCSRB, RXEN);
   #elif Communication_Mode == Tx_Rx
   SET_BIT(UCSRB, TXEN);
   SET_BIT(UCSRB, RXEN);
   #endif
   // Setting the Baud Rate
   uint16 UBRR_Val = Calc_UBRR(1000000UL, Baud_Rate, Transmission_Speed);
   UBRRH = (uint8)(UBRR_Val>>8);
   UBRRL = (uint8)UBRR_Val;
   // Select the Data Length
   SET_BIT(UCSRC, 7);
   #if Data_Size == _5_Bits
   CLEAR_BIT(UCSRB, UCSZ2);
   CLEAR_BIT(UCSRC, UCSZ1);
   CLEAR_BIT(UCSRC, UCSZ0);
   #elif Data_Size == _6_Bits
   CLEAR_BIT(UCSRB, UCSZ2);
   CLEAR_BIT(UCSRC, UCSZ1);
   SET_BIT(UCSRC,   UCSZ0);
   #elif Data_Size == _7_Bits
   CLEAR_BIT(UCSRB, UCSZ2);
   SET_BIT(UCSRC,   UCSZ1);
   CLEAR_BIT(UCSRC, UCSZ0);
   #elif Data_Size == _8_Bits
   CLEAR_BIT(UCSRB, UCSZ2);
   SET_BIT(UCSRC,   UCSZ1);
   SET_BIT(UCSRC,   UCSZ0);
   #elif Data_Size == _9_Bits
   SET_BIT(UCSRB,   UCSZ2);
   SET_BIT(UCSRC,   UCSZ1);
   SET_BIT(UCSRC,   UCSZ0);
   #endif
   // Select the USART Mode
   #if USART_Mode == Syn
   SET_BIT(UCSRC, UMSEL);
   #elif USART_Mode == Asyn
   CLEAR_BIT(UCSRC, UCPOL);
   #endif
   // Select the Parity Bit Mode
   #if Parity_Bit == Even_Parity
   SET_BIT(UCSRC, UPM1);
   #elif Parity_Bit == Odd_Parity
   SET_BIT(UCSRC, UPM1);
   SET_BIT(UCSRC, UPM0);
   #endif
   // Select the number of stop bits
   #if Stop_Bit == _2_Bits
   SET_BIT(UCSRC, USBS);
   #elif Stop_Bit == _1_Bit
   CLEAR_BIT(UCSRC, USBS);
   #endif
}

#if Communication_Mode == Tx || Communication_Mode == Tx_Rx
void USART_SendData(uint8 data){
   while(BIT_IS_CLEAR(UCSRA, UDRE));   // Wait until Data Register to become empty
   UDR = data;
}
#endif

#if Communication_Mode == Rx || Communication_Mode == Tx_Rx
uint8 USART_ReceiveData(){
   while(BIT_IS_CLEAR(UCSRA, RXC));    // Wait until data coming from outside interface
   return UDR;
}
#endif
