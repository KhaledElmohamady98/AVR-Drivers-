/*
 * main.c
 *
 *  Created on: Nov 5, 2021
 *      Author: user
 */
#include"BIT_CALC.h"
#include"std_types.h"
#include"avr/delay.h"
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"I2C_interface.h"

void main(void)
{

	DIO_set_pin_direction(Group_C,DIO_pin_C0,DIO_Output);
	DIO_set_pin_direction(Group_C,DIO_pin_C1,DIO_Output);
	LCD_initial();
	U8 arr[]="KHALED";
	U8 LCD[7];
    U8 i =0;
	I2C_MASTER_INIT();
	I2C_START();
	I2C_MASTER_TRANSMIT(0b10100000);
	I2C_MASTER_TRANSMIT(0b00000000);
	for(i=0;i<6;i++)
	{
		I2C_MASTER_TRANSMIT(arr[i]);
	}
	 I2C_STOP();
	 _delay_ms(10);

	 I2C_START();
	 I2C_MASTER_TRANSMIT(0b10100000);
	 I2C_MASTER_TRANSMIT(0b00000000);
	 I2C_START();
	 I2C_MASTER_TRANSMIT(0b10100001);
	 for(i=0;i<6;i++)
	 {
		 LCD[i] = I2C_MASTER_RECIEVE_ACK();
	 }
	 I2C_MASTER_RECIEVE_NACK();
	 I2C_STOP();
	 LCD[i]='\0';
	 LCD_write_string(LCD);

while(1)
 {

 }
}


