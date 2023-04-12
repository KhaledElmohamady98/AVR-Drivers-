/*
 * EXIT_private.h
 *
 *  Created on: Oct 1, 2021
 *      Author: user
 */

#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_

#define MCUCR  *((volatile U8 *)0X55)
#define MCUCSR *((volatile U8 *)0X54)
#define GICR   *((volatile U8 *)0X5B)
#define GIFR   *((volatile U8 *)0X5A)
#define SREG   *((volatile U8 *)0X5F)
 // define function prototype of interrupt




#endif /* EXIT_PRIVATE_H_ */
