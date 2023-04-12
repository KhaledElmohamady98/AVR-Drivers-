/*
 * main.c
 *
 *  Created on: Nov 12, 2021
 *      Author: user
 */
#include"std_types.h"
#include"BIT_CALC.h"
#include<avr/delay.h>
#include"DIO_interface.h"
#include"RTOS_interface.h"

#define TCCR0  *((volatile U8 *)0X53)
#define TCNT0  *((volatile U8 *)0X52)
#define TIMSK  *((volatile U8 *)0X59)
#define SREG   *((volatile U8 *)0X5F)

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static U16 count=0;
	count++;
	if(count == 3907)
	{
	   count = 0;
	   TCNT0 = 192;
       TickCount++;
       scheduler();
 	}
}

void LED_1(void)
{
	static U8 state_1=0;
	DIO_set_pin_value(Group_B,DIO_pin_B0,toggle_bit(state_1,0));
}

void LED_2(void)
{
	static U8 state_2=0;
	DIO_set_pin_value(Group_B,DIO_pin_B1,toggle_bit(state_2,0));
}

void LED_3(void)
{
	static U8 state_3=0;
	DIO_set_pin_value(Group_B,DIO_pin_B2,toggle_bit(state_3,0));
}


void main(void)
{
	DIO_set_pin_direction(Group_B,DIO_pin_B0,DIO_Output);
	DIO_set_pin_direction(Group_B,DIO_pin_B1,DIO_Output);
	DIO_set_pin_direction(Group_B,DIO_pin_B2,DIO_Output);
    TCNT0 =192;
    set_bit(TIMSK,0);
    set_bit(SREG,7);
    TCCR0 =0b00000010;
    TaskCreation(0,1,LED_1,0);
    TaskCreation(1,2,LED_2,0);
    TaskCreation(2,3,LED_3,0);

while(1)
 {

 }

}
