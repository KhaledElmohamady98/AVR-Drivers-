/*
 * TIMER_program.c
 *
 *  Created on: Nov 1, 2021
 *      Author: user
 */
#include"BIT_CALC.h"
#include"std_types.h"
#include"Timer_private.h"
#include"TIMER_config.h"
#include"Timer_interface.h"

static void (*Timer0_PVCallBackFunc)(void)=0;

void Timer0_voidInit(void)
{
	// make ctc mode
//	set_bit(TCCR0,TCCR0_WGM01);
//	clear_bit(TCCR0,TCCR0_WGM00);

	//choose fast PWM mode
	set_bit(TCCR0,TCCR0_WGM01);
	set_bit(TCCR0,TCCR0_WGM00);

	 //MAKE compare match interrupt enable
  //   set_bit(TIMSK,TIMSK_OCIE0);

	//make the compare match value == 64 for duty cycle
	OCR0 =64;
	//clear on compare match set on top
    set_bit(TCCR0,TCCR0_COM01);
    clear_bit(TCCR0,TCCR0_COM00);

    /*
    //make prescaler divistion by 64
	clear_bit(TCCR0,TCCR0_CS02);
	set_bit(TCCR0,TCCR0_CS01);
	set_bit(TCCR0,TCCR0_CS00);
*/
    //make prescaler divistion by 8
	clear_bit(TCCR0,TCCR0_CS02);
	set_bit(TCCR0,TCCR0_CS01);
	clear_bit(TCCR0,TCCR0_CS00);
}
	U8 Timer0_SetCallBack(void(*Copy_CallBackFun)(void))
	{
		U8 ErrorState= OK;

		if(Copy_CallBackFun !=NULL)
		{

			Timer0_PVCallBackFunc=Copy_CallBackFun;
		}
		else
		{
			ErrorState = NULL_pointer;
		}

		return ErrorState ;
	}



void __vector_10 (void) __attribute__((signal));

void __vector_10 (void)
{
	if(Timer0_PVCallBackFunc !=NULL)
	{

		Timer0_PVCallBackFunc();
	}
}

void TIMER0_SET_CompareMatchValue(U8 value)
{
	OCR0 = value;
}



void Timer1_SetTimerValue(U16 copy_value )
{
  TCNT1L = copy_value;
}

U16 Timer1_Read_Timer1_Value(void)
{
  return TCNT1L;
}


void Timer1_Init(void)
{
   //Initialize Timer1 at normal mode //prescaler =8
 	clear_bit(TCCR1B,TCCR1B_CS12);
	set_bit(TCCR1B_CS10,TCCR1B_CS11);
	clear_bit(TCCR1B,TCCR1B_CS10);
}
