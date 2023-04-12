/*
 * main.c
 *
 *  Created on: Sep 14, 2021
 *      Author: user
 */

#include"std_types.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"

int main(void)
{



    DIO_set_port_direction(Group_C, DIO_Max_port_direction );
    DIO_set_port_value(Group_C,DIO_Max_port_value);

	 while(1)
	 {

	 }



return 0;
}
