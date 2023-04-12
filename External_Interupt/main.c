/*
 * main.c
 *
 *  Created on: Oct 1, 2021
 *      Author: user
 */
#include "BIT_CALC.h"
#include "std_types.h"
#include "avr/delay.h"
#include "EXTI_interface.h"
#include "DIO_interface.h"



void led_blink(void)
{
	static U8 var =0;

	toggle_bit(var,0);

	DIO_set_pin_value(Group_A,DIO_pin_A0,var);

}
void main(void)

{

	DIO_set_pin_direction(Group_A,DIO_pin_A0,DIO_Output);

	DIO_set_pin_direction(Group_D,DIO_pin_D2,DIO_Input);
	DIO_set_pin_value(Group_D,DIO_pin_D2,DIO_High);

	IntSetLevel(INT_0,INT_falling_edge);
    INT_Set_CallBack(INT_0, led_blink);
	IntEnable(INT_0);
	IntGlobal(INT_Global_En);

while(1)
 {

 }

}


