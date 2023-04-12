/*
 * main.c
 *
 *  Created on: Sep 11, 2021
 *      Author: user
 */

#include "BIT_CALC.h"
#include "std_types.h"
#define F_CPU 8000000
#include "avr/delay.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
void main(void)
{
	//code of arabic name
  /*
	 LCD_initial();

	U8 pattern1[8]={0b00000100,0b00000000,0b00001100,0b00000010,0b00011111,0b00000000,0b00000000,0b00000000};
	 U8 pattern2[8]={0b00000001,0b00000001,0b00000001,0b00000001,0b00000001,0b00000000,0b00000000,0b00000000};
	 U8 pattern3[8]={0b00000001,0b00000001,0b00000001,0b00000001,0b00011111,0b00000000,0b00000000,0b00000000};
	 U8 pattern4[8]={0b00000000,0b00000001,0b00000001,0b00000001,0b00011111,0b00000000,0b00000000,0b00000000};


	while(1)
	{
	    LCD_write_special_character(pattern1,0,0,15);
	    LCD_write_special_character(pattern2,1,0,14);
	    LCD_write_special_character(pattern3,2,0,13);
	    LCD_write_special_character(pattern4,3,0,12);
	    _delay_ms(200);
	     LCD_clear();

	     LCD_write_special_character(pattern1,0,1,11);
	     LCD_write_special_character(pattern2,1,1,10);
	     LCD_write_special_character(pattern3,2,1,9);
	     LCD_write_special_character(pattern4,3,1,8);
	     _delay_ms(200);
	      LCD_clear();

	      LCD_write_special_character(pattern1,0,0,6);
	      LCD_write_special_character(pattern2,1,0,5);
	      LCD_write_special_character(pattern3,2,0,4);
	      LCD_write_special_character(pattern4,3,0,3);
	      _delay_ms(200);
	       LCD_clear();

	     LCD_write_special_character(pattern1,0,1,4);
	     LCD_write_special_character(pattern2,1,1,3);
	     LCD_write_special_character(pattern3,2,1,2);
	     LCD_write_special_character(pattern4,3,1,1);
	     _delay_ms(200);
	     LCD_clear();


	}
	}
*/

	//code of string
/*
	LCD_initial();
	LCD_write_string("boshy");
	while(1)
	{


	}
	*/
//code of showing number
	/*
	LCD_initial();
	LCD_write_no(1234567897);
}
*/

	 LCD_initial();
	 U8 human_stand[8]= {0b00001110,0b00001010,0b00001110,0b00000100,0b00011111,0b00000100,0b00001110,0b00010001};
	 U8 human_play[8]= {0b00001110,0b00001010,0b00001110,0b00000100,0b00011111,0b00000100,0b00011110,0b00000001};
	 U8 ball_down[8]= {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000001,0b00000000,0b00000000};
	 U8 ball_middle[8]= {0b00000000,0b00000000,0b00000000,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000};
	 U8 ball_up[8]= {0b00000000,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
	 U8 run_front[8]= {0b00001110,0b00001010,0b00001110,0b00000100,0b00011111,0b00000100,0b00011110,0b00000001};
	 U8 run_back[8]= {0b00001110,0b00001010,0b00001110,0b00000100,0b00011111,0b00000100,0b00001111,0b00010000};
	 U8 hide_pattern[8]= {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
	 while(1)
	 {

     LCD_write_string("yassin");
     LCD_write_special_character(human_stand,0,1,15);
     _delay_ms(2000);
     LCD_clear();
     LCD_write_string("I love football");
     LCD_write_special_character(human_stand,0,1,15);
     _delay_ms(1000);
     for(int i=0;i<5;i++)
     {
     LCD_write_special_character(human_play,0,1,15);
     LCD_write_special_character(ball_down,1,1,14);
     _delay_ms(200);
     LCD_write_special_character(ball_middle,1,1,14);
     LCD_write_special_character(human_stand,0,1,15);
     _delay_ms(200);
     LCD_write_special_character(ball_up,1,1,14);
     _delay_ms(200);
     LCD_write_special_character(ball_middle,1,1,14);
     LCD_write_special_character(human_play,0,1,15);
     _delay_ms(200);
     LCD_write_special_character(ball_down,1,1,14);
     }
     LCD_clear();

	 LCD_write_string("i love running");
	 LCD_write_special_character(human_stand,0,1,15);
	 _delay_ms(1000);
	 LCD_clear();
	 LCD_write_string("now ruuuuun");
	 _delay_ms(1000);
	 LCD_clear();
	 int j=15;
	 for(int i=7;i>=0;i--)
	 {
		 LCD_write_special_character(run_front,0,1,j);
		 _delay_ms(350);
		 j--;
		 LCD_clear();
		 LCD_write_special_character(run_back,0,1,j);
		 _delay_ms(350);
		 LCD_clear();
         j--;
	 }
	 LCD_clear();

	 }

}
