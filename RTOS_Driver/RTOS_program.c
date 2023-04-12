/*
 * RTOS_program.c
 *
 *  Created on: Nov 12, 2021
 *      Author: user
 */
#include"BIT_CALC.h"
#include"std_types.h"
#include"RTOS_interface.h"


Task arr[NO_OF_TASKS];

void TaskCreation(U8 periority,U8 periodicity,void(*Fptr)(void),U8 first_delay)
{
  arr[periority].periodicity = periodicity;
  arr[periority].ptr=Fptr;

  //INITIALIZE IS DELAY =0 DISBALE AT FIRST
  arr[periority].IsDelay=0;
  // arr[periority].FIRST_delay=firstdelay as varibale send in function;
  if(first_delay>1)
  {
	  arr[periority].First_delay=first_delay;
	  arr[periority].IsFirstDelay=1;
  }
  else if(first_delay==0)      //may be else rather than else if
  {
	  arr[periority].First_delay=0;
	  arr[periority].IsFirstDelay=0;
  }
}

void scheduler(void)
{
	for(U8 i=0;i<NO_OF_TASKS;i++)
	{
		if((arr[i]).Task_state ==Active)
		{
			if(arr[i].IsDelay==1)
			{
				arr[i].Delay_value--;
				if(arr[i].Delay_value==0)
				{
					arr[i].IsDelay=0;
				}
			}
  else
	{
	  if(arr[i].IsFirstDelay==1)
	  {
		  if(TickCount%arr[i].First_delay==0)
		  {
			  arr[i].ptr();
			  arr[i].IsFirstDelay=0;
		  }
	  }
	  else
	  {
  if(TickCount %arr[i].periodicity==0)
  {
	  arr[i].ptr();
  }
	  }
	}

	}

	else
	{

	}
	}
}

//delete task
void Delete_Task(U8 priority)
{
	arr[priority].ptr = NULL;
}

//stop function
void Task_Suspend(U8 priority)
{
	arr[priority].Task_state= Suspend;
}

//Active function
void Task_Active(U8 priority)
{
	arr[priority].Task_state= Active;
}

void Task_Delay(U8 priority,U8 DelayVal)
{
	arr[priority].Delay_value = DelayVal;
	arr[priority].IsDelay = 1;
}


