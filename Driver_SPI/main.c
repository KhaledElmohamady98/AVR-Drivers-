/*
 * main.c
 *
 *  Created on: Oct 30, 2021
 *      Author: user
 */
#include"std_types.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
#include"SPI_interface.h"

void main(void)
{
	/*Master pin*/
    //CLOCK
	DIO_set_pin_direction(Group_B,DIO_pin_B7,DIO_Output);
	//MISO
	DIO_set_pin_direction(Group_B,DIO_pin_B6,DIO_Input);
    //MOSI
	DIO_set_pin_direction(Group_B,DIO_pin_B5,DIO_Output);
	//SLAVE SELECT
	DIO_set_pin_direction(Group_B,DIO_pin_B4,DIO_Output);
	DIO_set_pin_value(Group_B,DIO_pin_B4,DIO_Low);

   //CHECK PIN
	DIO_set_pin_direction(Group_A,DIO_pin_A4,DIO_Output);

	SPI_INIT_MASTER();
	U8 Recieved_data;
     LCD_initial();

	while(1)
	{


		Recieved_data =SPI_Transfer('A');
		if(Recieved_data=='B')
		{
			LCD_clear();
			LCD_write_data(Recieved_data);
		}

		else
		{
			LCD_clear();
			LCD_write_string("no signal");
		}
	}
}

