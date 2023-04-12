/*
 * SPI_interface.h
 *
 *  Created on: Oct 30, 2021
 *      Author: user
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPCR *((volatile U8 *)0X2D)
#define SPSR *((volatile U8 *)0X2E)
#define SPDR *((volatile U8 *)0X2F)


void SPI_INIT_MASTER(void);
void SPI_INIT_SLAVE(void);
#endif /* SPI_INTERFACE_H_ */
