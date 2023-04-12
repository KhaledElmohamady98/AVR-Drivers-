/*
 * I2C_private.h
 *
 *  Created on: Nov 5, 2021
 *      Author: user
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWAR  *((volatile U8 *)0X22)
#define TWBR  *((volatile U8 *)0X20)
#define TWCR  *((volatile U8 *)0X56)
#define TWDR  *((volatile U8 *)0X23)
#define TWSR  *((volatile U8 *)0X21)



#endif /* I2C_PRIVATE_H_ */
