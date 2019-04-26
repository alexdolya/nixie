/*
 * twi.h
 *
 * Created: 06.07.2018 14:17:30
 *  Author: user
 */ 


#ifndef TWI_H_
#define TWI_H_

void twi_Init (void);
void twi_Start(void);
void twi_Stop(void);
void twi_sendbyte(unsigned char c);
unsigned char twi_readbyte (void);
unsigned char twi_readlastbyte(void);


#endif /* TWI_H_ */