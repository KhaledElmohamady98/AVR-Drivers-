/*
 * main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: user
 */
#include"std_types.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"

#define TCCR0  *((volatile U8 *)0X53)
#define TCNT0  *((volatile U8 *)0X52)
#define TIMSK  *((volatile U8 *)0X59)
#define SREG  *((volatile U8 *)0X5F)

U8 LedCounter=0;
U8 flag=0;

//3 led

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static U16 count=0;
	static U8 var=0;
	count++;
	if(count == 3907)
	{
		count = 0;
		TCNT0 = 192;

		LedCounter++;
		flag=1;

	}
}


//for one led
/*
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static U16 count=0;
	static U8 var=0;
	count++;
	if(count == 3907)
	{
		count = 0;
		TCNT0 = 192;

		toggle_bit(var,0);
		DIO_set_pin_value(Group_C, DIO_pin_C0,var);

	}
}
*/

void main(void)
{
	//VARIABLE of toggle leds

	U8 state_1=0;
	U8 state_2=0;
	U8 state_3=0;

    // start timing first time from 0.25
    TCNT0 = 192;

	//prescaler =8
	//normal mode
	TCCR0 = 0b00000010;
	DIO_set_pin_direction(Group_C, DIO_pin_C0,DIO_Output);
	DIO_set_pin_direction(Group_C, DIO_pin_C1,DIO_Output);
	DIO_set_pin_direction(Group_C, DIO_pin_C2,DIO_Output);

	//Enable interrupt
	set_bit(TIMSK,0);

	//Enable global
	set_bit(SREG,7);

  while(1)
   {
	  if(flag==1)
	  {
		  if(LedCounter%1==0)
		  {
			  DIO_set_pin_value(Group_C, DIO_pin_C0,toggle_bit(state_1,0));
		  }

		  if(LedCounter%2==0)
		  {
			  DIO_set_pin_value(Group_C, DIO_pin_C1,toggle_bit(state_2,0));
		  }

		  if(LedCounter%3==0)
		  {
			  DIO_set_pin_value(Group_C, DIO_pin_C2,toggle_bit(state_3,0));
		  }

      flag=0;


	  }

   }
}

