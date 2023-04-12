/*
 * main.c
 *
 *  Created on: Oct 12, 2021
 *      Author: user
 */

#include"avr/delay.h"
#include"std_types.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include"LCD_interface.h"
/*
S32 map(S32 InputMin,S32 InputMax,S32 OutputMin,S32 OutputMax,S32 InputValue)
{



}
*/

void main(void)
{

	// 8 bit in led
/*
     U8 Reading;

	DIO_set_pin_direction(Group_A,DIO_pin_A0, DIO_Input);
    DIO_set_port_direction(Group_C ,DIO_Max_port_direction);


	ADC_init();

while(1)
{
    Reading = ADC_ChannelReading(0);
    DIO_set_port_value(Group_C,Reading);
}
}

*/
	//temp sensor

/*
	U16 digital;
	F32 analog;
    U32 temp ;
	DIO_set_pin_direction(Group_A,DIO_pin_A7, DIO_Input);
    ADC_init();
    LCD_initial();

    while(1)
    {
          digital =ADC_Read_10(DIO_pin_A7);
          LCD_write_no(digital);
          analog=(digital*5.0)/1024;

          temp = (analog*100);
          LCD_write_string("temp=");
          LCD_write_no(temp);
          LCD_write_string("c");
          _delay_ms(1000);
          LCD_clear();
    }
    }


*/
//LDR SENSOR

	    U32 digital;
		DIO_set_pin_direction(Group_A,DIO_pin_A7, DIO_Input);
	    DIO_set_port_direction(Group_C,DIO_Max_port_direction);
	    ADC_init();
	    LCD_initial();
	    while(1)
	    {
	    	digital =ADC_ChannelReading(7);
	    	LCD_write_no(digital);
            if((digital>=0) &&(digital<=32))
            {
            	DIO_set_port_value(Group_C,DIO_Max_port_value);
            }
            else if((digital>32) && (digital<=64))
            {
            	DIO_set_port_value(Group_C,DIO_Min_port_direction);
            	for(int i=0;i<7;i++)
            	{
            		DIO_set_pin_value(Group_C,i,DIO_High);
            	}
            }

            else if((digital>64) && (digital<=96))
                {
                	DIO_set_port_value(Group_C,DIO_Min_port_direction);
                	for(int i=0;i<6;i++)
                	{
                		DIO_set_pin_value(Group_C,i,DIO_High);
                	}
                }

            else if((digital>96) && (digital<=128))
                {
                	DIO_set_port_value(Group_C,DIO_Min_port_direction);
                	for(int i=0;i<5;i++)
                	{
                		DIO_set_pin_value(Group_C,i,DIO_High);
                	}
                }



            else if((digital>128) && (digital<=160))
                {
                	DIO_set_port_value(Group_C,DIO_Min_port_direction);
                	for(int i=0;i<4;i++)
                	{
                		DIO_set_pin_value(Group_C,i,DIO_High);
                	}
                }


            else if((digital>160) && (digital<=192))
                {
                	DIO_set_port_value(Group_C,DIO_Min_port_direction);
                	for(int i=0;i<3;i++)
                	{
                		DIO_set_pin_value(Group_C,i,DIO_High);
                	}
                }
            else if((digital>129) && (digital<=224))
                         {
                         	DIO_set_port_value(Group_C,DIO_Min_port_direction);
                         	for(int i=0;i<2;i++)
                         	{
                         		DIO_set_pin_value(Group_C,i,DIO_High);
                         	}
                         }

            else if((digital>224) && (digital<=256))
                         {
                         	DIO_set_port_value(Group_C,DIO_Min_port_direction);
                         	for(int i=0;i<1;i++)
                         	{
                         		DIO_set_pin_value(Group_C,i,DIO_High);
                         	}
                         }



	       _delay_ms(2000);
	        LCD_clear();
	    }
	   }


