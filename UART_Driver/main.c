/*
 * main.c
 *
 *  Created on: Oct 29, 2021
 *      Author: user
 */
#include"std_types.h"
#include"BIT_CALC.h"
#include"LCD_interface.h"
#include"DIO_interface.h"
#include"UART_interface.h"
#include"avr/delay.h"
void main(void)
{

DIO_set_pin_direction(Group_D,DIO_pin_D0,DIO_Input);
DIO_set_pin_direction(Group_D,DIO_pin_D1,DIO_Output);
DIO_set_pin_direction(Group_D,DIO_pin_D3,DIO_Output);
U8 ch;
UART_Init();
LCD_initial();
/*
while(1)
{
	ch = UART_receive_char();
	LCD_write_data(ch);
	UART_send_character(ch);

	if(ch=='c')
	{
		DIO_set_pin_value(Group_D,DIO_pin_D3,DIO_High);
		UART_send_character('D');
	}

	else if(ch=='b')
	{
		DIO_set_pin_value(Group_D,DIO_pin_D3,DIO_Low);
	}

	else if(ch=='q')
	{
		LCD_clear();
	}
}
*/

U8 arr[10] = {'i','a','m','h','u','n','g','r','y','\0'};
while(1)
{
UART_send_string(arr);
_delay_ms(2000);
}
}
