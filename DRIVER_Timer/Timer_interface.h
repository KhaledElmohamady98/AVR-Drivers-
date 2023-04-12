/*
 * Timer_interface.h
 *
 *  Created on: Nov 1, 2021
 *      Author: user
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer0_voidInit(void);
U8 Timer0_SetCallBack(void(*Copy_CallBackFun)(void));
void TIMER0_SET_CompareMatchValue(U8 value);

void Timer1_Init(void);
void Timer1_SetTimerValue(U16 value);
U16 Timer1_Read_Timer1_Value(void);
#endif /* TIMER_INTERFACE_H_ */
