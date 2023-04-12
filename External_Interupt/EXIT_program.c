/*
 * EXIT_program.c
 *
 *  Created on: Oct 2, 2021
 *      Author: user
 */
#include"BIT_CALC.h"
#include"std_types.h"
#include"DIO_interface.h"
#include"EXIT_private.h"
#include"EXTI_interface.h"

static void (*PVoidCallBack[3])(void)={0,0,0};


void IntEnable(U8 INT_index)
{
	switch (INT_index)
	{
		case INT_0:
		set_bit(GICR,INT_0_E_Bit);
		break;

		case INT_1:
		set_bit(GICR,INT_1_E_Bit);
		break;
		case INT_2:
		set_bit(GICR,INT_2_E_Bit);
		break;
	}
}

void IntDisable(U8 INT_index)
{
	switch (INT_index)
	{
		case INT_0:
		clear_bit(GICR,INT_0_E_Bit);
		break;

		case INT_1:
			clear_bit(GICR,INT_1_E_Bit);
		break;
		case INT_2:
			clear_bit(GICR,INT_2_E_Bit);
		break;
	}
}

void IntSetLevel(U8 INT_index, U8 INT_level )
{
	switch (INT_index)
	{
		case INT_0:
		assign_bit(MCUCR,0,get_bit(INT_level ,0));
		assign_bit(MCUCR,1,get_bit(INT_level ,1));
		break;

		case INT_1:
			assign_bit(MCUCR,2,get_bit(INT_level ,0));
			assign_bit(MCUCR,3,get_bit(INT_level ,1));
			break;

		case INT_2:
		assign_bit(MCUCSR,6,INT_level);
		break;
	}
}

void IntGlobal(U8 INT_status)
{
	 assign_bit(SREG,7,INT_status);
}

void INT_Set_CallBack(U8 INT_Index, void (*ptr)(void))
{
	PVoidCallBack[INT_Index] = ptr;
}


void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	if(PVoidCallBack[0] != 0)
	{
	PVoidCallBack[0]();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(PVoidCallBack[1] != 0)
	{
	PVoidCallBack[1]();
	}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(PVoidCallBack[2] != 0)
	{
	PVoidCallBack[2]();
	}
}


