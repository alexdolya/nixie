/*
 * clock.c
 *
 * Created: 28.03.2019 10:53:31
 *  Author: user
 */ 
#include "avr/io.h"
#include "twi.h"

void set_dechours (uint8_t dechour){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(2);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t clock_hours=twi_readlastbyte();
	twi_Stop();
	dechour=dechour<<4;
	clock_hours&=0b00001111;
	clock_hours|=dechour;
	twi_Init();
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(2);
	twi_sendbyte(clock_hours);
	twi_Stop();
}

void set_hours (uint8_t hour){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(2);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t clock_hours=twi_readlastbyte();
	twi_Stop();	
	clock_hours&=0b11110000;
	clock_hours|=hour;
	twi_Init();
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(2);
	twi_sendbyte(clock_hours);
	twi_Stop();
}

void set_decmin (uint8_t decmin){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(1);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t clock_mins=twi_readlastbyte();
	twi_Stop();
	decmin=decmin<<4;
	clock_mins&=0b00001111;
	clock_mins|=decmin;
	twi_Init();
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(1);
	twi_sendbyte(clock_mins);
	twi_Stop();
}

void set_min (uint8_t min){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(1);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t clock_mins=twi_readlastbyte();
	twi_Stop();
	clock_mins&=0b11110000;
	clock_mins|=min;
	twi_Init();
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(0);
	twi_sendbyte(0);
	twi_sendbyte(clock_mins);
	twi_Stop();
}

uint8_t read_dechours (void){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(2);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t dh=twi_readlastbyte();
	twi_Stop();
	dh=dh>>4;
	return dh;	
}

uint8_t read_hours (void){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(2);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t h=twi_readlastbyte();
	twi_Stop();
	h&=0b00001111;
	return h;
}


uint8_t read_decmins (void){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(1);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t dm=twi_readlastbyte();
	twi_Stop();
	dm=dm>>4;
	return dm;
}

uint8_t read_mins (void){
	twi_Start();
	twi_sendbyte(0b11010000);
	twi_sendbyte(1);
	twi_Stop();
	twi_Start();
	twi_sendbyte(0b11010001);
	uint8_t m=twi_readlastbyte();
	twi_Stop();
	m&=0b00001111;
	return m;
}
