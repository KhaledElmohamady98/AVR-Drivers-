/*
 * EXTI_interface.h
 *
 *  Created on: Oct 1, 2021
 *      Author: user
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

//interrupt number of external interrupt
#define INT_0   0
#define INT_1   1
#define INT_2   2

//enable interrupt  bit
#define INT_0_E_Bit  6
#define INT_1_E_Bit  7
#define INT_2_E_Bit  5

//define the level of interrupt common for INT0 and INT1
#define INT_Low_Level  0b00
#define INT_Any_Logical 0b01
#define INT_falling_edge 0b10
#define INT_Rising_edge 0b11

//define the level of interrupt for int2
#define INT_2_Falling_edge 0b0
#define INT_2_Raising_edge 0b1

// define the global bit

#define INT_Global_En 0b1
#define INT_Global_dis 0b0

//function which implemented in EXIT_program.c

void IntEnable(U8 INT_index);
void IntDisable(U8 INT_index);
void IntSetLevel(U8 INT_index, U8 INT_level );
void IntGlobal(U8 INT_status);

void INT_Set_CallBack(U8 INT_Index, void (*ptr)(void));

#endif /* EXTI_INTERFACE_H_ */
