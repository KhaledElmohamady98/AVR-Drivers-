/*
 * I2C_interface.h
 *
 *  Created on: Nov 5, 2021
 *      Author: user
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_MASTER_INIT(void);
void I2C_START(void);
void I2C_MASTER_TRANSMIT(U8 data);
void I2C_STOP(void);
U8 I2C_MASTER_RECIEVE_ACK(void);
U8 I2C_MASTER_RECIEVE_NACK(void);
void I2C_INIT_SLAVE(U8 slave_address);
void I2C_SLAVE_LISTEN(void);
void I2C_SLAVE_TRANSMIT(U8 data);
U8 I2C_SLAVE_RECIEVE_ACK(void);
U8 I2C_SLAVE_RECIEVE_NACK(void);

#endif /* I2C_INTERFACE_H_ */
