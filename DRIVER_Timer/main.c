/*
 * main.c
 *
 *  Created on: Nov 1, 2021
 *      Author: user
 */
#include"std_types.h"
#include "BIT_CALC.h"
#include"DIO_interface.h"
#include"Timer_interface.h"
#include "avr/delay.h"

//void blink_led(void);
//void pwm(void);
//#define SREG   *((volatile U8 *)0X5F)       //GLOBAL interrupt enable

void main(void)
{
   //make OC0 bin output to control pwm by hardware
	DIO_set_pin_direction(Group_B,DIO_pin_B3,DIO_Output);
/*
	// multI PWM signal in three pins and we test compare match in on led
	DIO_set_pin_direction(Group_A,DIO_pin_A7,DIO_Output);
	DIO_set_pin_value(Group_A,DIO_pin_A7,DIO_High);



	DIO_set_pin_direction(Group_A,DIO_pin_A6,DIO_Output);
	DIO_set_pin_value(Group_A,DIO_pin_A6,DIO_High);


	DIO_set_pin_direction(Group_A,DIO_pin_A5,DIO_Output);
	DIO_set_pin_value(Group_A,DIO_pin_A5,DIO_High);

	//check the ISR function occur
	DIO_set_pin_direction(Group_D,DIO_pin_D0,DIO_Output);
*/
	U8 Local_counter;
    Timer0_voidInit();
  //  Timer0_SetCallBack(&pwm);
   // set_bit(SREG,7);    //global interrupt enable
while(1)
 {
     for(Local_counter =0;Local_counter<255;Local_counter++)
     {

    	 TIMER0_SET_CompareMatchValue(Local_counter);
    	 _delay_ms(10);
     }


     for(Local_counter =255;Local_counter>0;Local_counter--)
     {

    	 TIMER0_SET_CompareMatchValue(Local_counter);
    	 _delay_ms(10);
     }

 }
}


/*
void blink_led(void)
{
	static U16 counter =0;
	static U16 value=0;
	counter++;
	DIO_set_pin_value(Group_D,DIO_pin_D0,DIO_High);
	if(counter == 4000)
	{

		DIO_set_pin_value(Group_A,DIO_pin_A7,toggle_bit(value,0));
	    counter =0;
	}

}

*/
/*
void pwm(void)
{
	static U16 counter =0;
		counter++;
		DIO_set_pin_value(Group_D,DIO_pin_D0,DIO_High);
		if(counter == 5)
		{

			DIO_set_pin_value(Group_A,DIO_pin_A7,DIO_Low);

		}

		else if(counter == 10)
		{
			DIO_set_pin_value(Group_A,DIO_pin_A6,DIO_Low);
		}

		else if(counter == 15)
		{
			DIO_set_pin_value(Group_A,DIO_pin_A5,DIO_Low);
		}

		else if(counter == 20)
		{

			DIO_set_pin_value(Group_A,DIO_pin_A7,DIO_High);
			DIO_set_pin_value(Group_A,DIO_pin_A6,DIO_High);
			DIO_set_pin_value(Group_A,DIO_pin_A5,DIO_High);
			counter =0;
		}
}
*/
