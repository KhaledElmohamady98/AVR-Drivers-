/*
 * main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: user
 */
#include"std_types.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
#include"ADC_interface.h"

#define TCCR0  *((volatile U8 *)0X53)
#define TCNT0  *((volatile U8 *)0X52)
#define TIMSK  *((volatile U8 *)0X59)
#define SREG   *((volatile U8 *)0X5F)
#define OCR0   *((volatile U8 *)0X5C)


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{

		static U8 var=0;
		toggle_bit(var,0);
		DIO_set_pin_value(Group_B, DIO_pin_B0,var);
}



void main(void)
{
DIO_set_pin_direction(Group_A,DIO_pin_A7,DIO_Input);
DIO_set_pin_direction(Group_B,DIO_pin_B0,DIO_Output);

//for buzzer
TCCR0=0b00001010; //CTC MODE AND PRESCALER = 8 AND TOGG,E EACH COMPARE MATCH

// for motor
//TCCR0 =0b01111010;


set_bit(TIMSK,1);   //ENable interrupt peripheral

set_bit(SREG,7);    //global interrupt enable

ADC_init();

while(1)
  {
   OCR0 =ADC_ChannelReading(7);
  }
}
