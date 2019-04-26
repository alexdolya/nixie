/*
 * nixie.c
 *
 * Created: 28.03.2019 14:39:43
 *  Author: user
 */
#define  F_CPU 8000000

#define	SET_0 PORTC=0b00000000
#define	SET_1 PORTC=0b00000001
#define	SET_2 PORTC=0b00000010
#define	SET_3 PORTC=0b00000011
#define	SET_4 PORTC=0b00000100
#define	SET_5 PORTC=0b00000101
#define	SET_6 PORTC=0b00000110
#define	SET_7 PORTC=0b00000111
#define	SET_8 PORTC=0b00001000
#define	SET_9 PORTC=0b00001001
#define	SET_HD PORTB=0b00001000
#define	SET_H PORTB=0b00000100
#define	SET_MD PORTB=0b00000010
#define	SET_M PORTB=0b00000001
#define	SET_DARK PORTB=0b00000000

#include <avr/io.h>
#include <util/delay.h>

void nixie_on (uint8_t dechour, uint8_t hour, uint8_t decmin, uint8_t min) {
	
	switch (dechour) {
		case 0: SET_HD; SET_0; break;
		case 1: SET_HD; SET_1; break;
		case 2: SET_HD; SET_2; break;
		case 3: SET_HD; SET_3; break;
		case 4: SET_HD; SET_4; break;
		case 5: SET_HD; SET_5; break;
		case 6: SET_HD; SET_6; break;
		case 7: SET_HD; SET_7; break;
		case 8: SET_HD; SET_8; break;
		case 9: SET_HD; SET_9; break;	
		case 10: SET_DARK; break;		
	}
	_delay_ms(250);
	
	
	switch (hour) {
		case 0: SET_H; SET_0; break;
		case 1: SET_H; SET_1; break;
		case 2: SET_H; SET_2; break;
		case 3: SET_H; SET_3; break;
		case 4: SET_H; SET_4; break;
		case 5: SET_H; SET_5; break;
		case 6: SET_H; SET_6; break;
		case 7: SET_H; SET_7; break;
		case 8: SET_H; SET_8; break;
		case 9: SET_H;SET_9; break;
		case 10: SET_DARK; break;		
	}
	_delay_ms(250);

	
	switch (decmin) {
		case 0: SET_MD; SET_0; break;
		case 1: SET_MD; SET_1; break;
		case 2: SET_MD; SET_2; break;
		case 3: SET_MD; SET_3; break;
		case 4: SET_MD; SET_4; break;
		case 5: SET_MD; SET_5; break;
		case 6: SET_MD; SET_6; break;
		case 7: SET_MD; SET_7; break;
		case 8: SET_MD; SET_8; break;
		case 9: SET_MD; SET_9; break;
		case 10: SET_DARK; break;		
	}
	_delay_ms(250);

	
	switch (min) {
		case 0: SET_M; SET_0; break;
		case 1: SET_M; SET_1; break;
		case 2: SET_M; SET_2; break;
		case 3: SET_M; SET_3; break;
		case 4: SET_M; SET_4; break;
		case 5: SET_M; SET_5; break;
		case 6: SET_M; SET_6; break;
		case 7: SET_M; SET_7; break;
		case 8: SET_M; SET_8; break;
		case 9: SET_M; SET_9; break;
		case 10: SET_DARK; break;		
	}
	_delay_ms(250);
}