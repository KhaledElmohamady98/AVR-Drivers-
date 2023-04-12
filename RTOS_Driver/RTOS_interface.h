/*
 * RTOS_interface.h
 *
 *  Created on: Nov 12, 2021
 *      Author: user
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

U8 TickCount;

typedef struct{
    // put  variable name First delay U8
	U8 periodicity;    //mean which one of task get first and i am who control the periodicity of task
	void(*ptr)(void);
	U8 Task_state;
	U8 Delay_value;
	U8 IsDelay;
	U8 First_delay;
	U8 IsFirstDelay;
}Task;
#define NO_OF_TASKS  3
#define Active  1
#define Suspend 0

//FUNCTIONS use in program.c
void TaskCreation(U8 periority,U8 periodicity,void(*Fptr)(void),U8 first_delay);
void scheduler(void);

void Delete_Task(U8 priority);
void Task_Suspend(U8 priority);
void Task_Active(U8 priority);
void Task_Delay(U8 priority,U8 DelayVal);

#endif /* RTOS_INTERFACE_H_ */
