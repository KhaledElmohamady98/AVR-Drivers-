/*
 * I2C_program.c
 *
 *  Created on: Nov 5, 2021
 *      Author: user
 */
#include"BIT_CALC.h"
#include"std_types.h"
#include"I2C_private.h"
#include"I2C_interface.h"

void I2C_MASTER_INIT(void)
{
	//FREQ 20HZ
   TWSR = 0b00000000;
   TWBR = 192;
}

void I2C_START(void)
{
//CLEAR INTERuptT FLAGH BIT 7  //NACK BIT 6 //GRNERAT STARTY CONDITION BIT 5
//BIT 4 STOP CONDTION ,// WRITE COLLICION FLAG CHECK THE COLLISION 3
// TWI ENABLE FLAG (ENABLE I2C)2// BIT 1 RESERVED //BIT 0 INTERRUPT TWI ENABLE
  TWCR = 0B10100100;
  while (get_bit(TWCR,7)==0);
}

void I2C_MASTER_TRANSMIT(U8 data)
{
   TWDR = data ;
   //interrupt enable clear flag and start next condition bit 7
   // and disable start condition  by bit 5
   TWCR = 0b10000100;
   while (get_bit(TWCR,7)==0);
}

void I2C_STOP(void)
{
	//GENERATE STOP BU BIT 4// STILL ENABLE INTERRUPT BY BIT 2 // CLEAR INTERUUPT FLAG BY BIT 7
	TWCR = 0b10010100;
	while(get_bit(TWCR,4)==1);
}

U8 I2C_MASTER_RECIEVE_ACK(void)
{
	//ACK ENABLE BIT 6
	TWCR = 0b11000100;
	while(get_bit(TWCR,7)==0);
	return TWDR;
}


U8 I2C_MASTER_RECIEVE_NACK(void)
{
	//NACK ENABLE BIT 6
	TWCR = 0b10000100;
	while(get_bit(TWCR,7)==0);
	return TWDR;
}

void I2C_INIT_SLAVE(U8 slave_address)
{
	TWAR =slave_address;
	//ENABLE I2C
	//ACK
	//CLEAR INTERRUPT FLAG  //AND ENABLE TO NEXT OPERATION
	TWCR = 0b011000100;
}
void I2C_SLAVE_LISTEN(void)
{
	while(get_bit(TWCR,7)==0);
}

void I2C_SLAVE_TRANSMIT(U8 data)
{
	TWDR = data;
	TWCR= 0b10000100;
	while(get_bit(TWCR,7)==0);
}


U8 I2C_SLAVE_RECIEVE_ACK(void)
{
	//ACK ENABLE BIT 6
	TWCR = 0b11000100;
	while(get_bit(TWCR,7)==0);
	return TWDR;
}

U8 I2C_SLAVE_RECIEVE_NACK(void)
{
	//NACK ENABLE BIT 6
	TWCR = 0b10000100;
	while(get_bit(TWCR,7)==0);
	return TWDR;
}
