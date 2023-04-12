/*
 * Timer_private.h
 *
 *  Created on: Nov 1, 2021
 *      Author: user
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0 *((volatile U8 *)0X53)     //timer control register
#define TCCR0_WGM00   6                  //wave form generation bit 6
#define TCCR0_WGM01   3                  //wave form generation bit 3

#define TCCR0_COM01   5                  //Compare match output mode
#define TCCR0_COM00   4                  //Compare match output mode

#define TCCR0_CS02    2                  //clock select bit 2    (prescaler)
#define TCCR0_CS01    1                  //clock select bit 1    (prescaler)
#define TCCR0_CS00    0                  //clock select bit 0    (prescaler)

#define OCR0  *((volatile U8*)0x5C)      // output compare register

#define TIMSK *((volatile U8*)0x59)      //timer-counter interrupt mask register
#define TIMSK_OCIE0  1                   //Output Compare Match Interrupt Enable


#define TCCR1B  *((volatile U8*)0x4E)                 //timer one control register
#define TCCR1B_CS10  0                                //clock select bit 2    (prescaler)
#define TCCR1B_CS11  1                                //clock select bit 1    (prescaler)
#define TCCR1B_CS12  2                               //clock select bit 0    (prescaler)

#define TCNT1L  *((volatile U16*)0x4C)

#endif /* TIMER_PRIVATE_H_ */
