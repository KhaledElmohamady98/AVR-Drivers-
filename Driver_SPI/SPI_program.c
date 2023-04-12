/*
 * SPI_program.c
 *
 *  Created on: Oct 30, 2021
 *      Author: user
 */
#include"std_types.h"
#include"BIT_CALC.h"
#include"SPI_private.h"
#include"SPI_interface.h"

void SPI_INIT_MASTER(void)
{
	SPCR = 0b01010001;
}


void SPI_INIT_SLAVE(void)
{
	SPCR = 0b01000000;
}

U8 SPI_Transfer(U8 data)
{
  SPDR = data;
  while(get_bit(SPSR,7)==0);
  return SPDR;
}
