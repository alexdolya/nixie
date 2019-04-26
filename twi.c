#define F_CPU 8000000

#include <avr/io.h>

void twi_Init (void)
{
	TWBR=0x20;
}

void twi_Start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}

void twi_Stop(void)

{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void twi_sendbyte(unsigned char c)

{
	TWDR = c;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}

unsigned char twi_readbyte (void)

{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));//ожидание установки бита TWIN
	return TWDR;//читаем регистр данных
}

unsigned char twi_readlastbyte(void)

{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));//ожидание установки бита TWIN
	return TWDR;//читаем регистр данных
}