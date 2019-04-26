#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "twi.h"
#include "clock.h"
#include "nixie.h"

uint8_t min=0, decmin=0, hour=0, dechour=0; 
uint8_t state=0, but_state=0;
uint8_t p_timer=0;
uint8_t dark_mode=1;
uint8_t blink_counter=0;
uint8_t b_state=0;

ISR (TIMER0_OVF_vect) {
	++p_timer;	
}

ISR (TIMER2_OVF_vect) {
	++blink_counter;
	if (blink_counter>=63) 
	{
		if (dark_mode)
		{
			dark_mode=0;
			blink_counter=0;
		}
		else 
		{
			dark_mode=1;
			blink_counter=0;
		}
	}	
}

void port_ini (void) {
	    DDRB=0xFF;
	    PORTB=0x00;
	    DDRC=0xFF;
	    PORTC=0xFF;
	    DDRD=0x00;
	    PORTD=0b00001100;
}

int but1_check (void) {
	if (!(PIND&0b00000100))
	{
		if (p_timer>=150)
		{
			if (state==4)
			{
				state=0;
				p_timer=0;
			}
			else
			{
				++state;
				p_timer=0;
			}
		}
	}
	else
	{
		p_timer=0;
	}
	return state;
}

void timer_ini (void) {
	TCCR0A=0;
	TCCR0B=0b00000100;
	TIMSK0=1;
	TCNT0=0;
	
	TCCR2A=0;
	TCCR2B=0b00000100;
	TIMSK2=1;
	TCNT2=0;
}

int main(void)
{
	enum HState
	{
		Time_show,
		Blink__Dec_Hour,
		Blink_Hour,
		Blink__Dec_Min,
		Blink_Min
	};
	
	set_dechours(2);
	set_hours(2);
	set_decmin(1);
	set_min(1);
	port_ini();
 	timer_ini();
 	sei();
	while (1) 
    {			
		state=but1_check();		
		
		switch (state)
		{				
			case (Time_show):
			 {
				dechour=read_dechours();
				hour=read_hours();
				decmin=read_decmins();
				min=read_mins();
				nixie_on(dechour, hour, decmin, min);

 				break;		
			}
					
			case (Blink__Dec_Hour):
			{	
			
				dechour=read_dechours();
				hour=read_hours();
				decmin=read_decmins();
				min=read_mins();
				if (dark_mode)
				{				
					nixie_on(10, hour, decmin, min);					
				}
				else
				{					
					nixie_on(dechour, hour, decmin, min);					
				}				
				
				if (!(PIND&0b00001000)&&b_state==0)
				{
					b_state=1;						
					dechour=read_dechours();
					++dechour;
					if(dechour>2)
					{
						dechour=0;
					}
					set_dechours(dechour);									
				}				
				
				if (PIND&0b00001000)
				{
					b_state=0;					
				}
				
				break;				
			}	
			

			
			
			case (Blink_Hour):
			{
				
				dechour=read_dechours();
				hour=read_hours();
				decmin=read_decmins();
				min=read_mins();
				if (dark_mode)
				{
					nixie_on(dechour, 10, decmin, min);
				}
				else
				{
					nixie_on(dechour, hour, decmin, min);
				}
				
				if (!(PIND&0b00001000)&&b_state==0)
				{
					b_state=1;
					hour=read_hours();
					++hour;
					if(hour>4)
					{
						hour=0;
					}
					set_hours(hour);
				}
				
				if (PIND&0b00001000)
				{
					b_state=0;
				}
				
				break;
			}
			
			
			
			case (Blink__Dec_Min):
			{
				
				dechour=read_dechours();
				hour=read_hours();
				decmin=read_decmins();
				min=read_mins();
				if (dark_mode)
				{
					nixie_on(dechour, hour, 10, min);
				}
				else
				{
					nixie_on(dechour, hour, decmin, min);
				}
				
				if (!(PIND&0b00001000)&&b_state==0)
				{
					b_state=1;
					decmin=read_decmins();
					++decmin;
					if(decmin>5)
					{
						decmin=0;
					}
					set_decmin(decmin);
				}
				
				if (PIND&0b00001000)
				{
					b_state=0;
				}
				
				break;
			}			


			case (Blink_Min):
			{
				
				dechour=read_dechours();
				hour=read_hours();
				decmin=read_decmins();
				min=read_mins();
				if (dark_mode)
				{
					nixie_on(dechour, hour, decmin, 10);
				}
				else
				{
					nixie_on(dechour, hour, decmin, min);
				}
				
				if (!(PIND&0b00001000)&&b_state==0)
				{
					b_state=1;
					min=read_mins();
					++min;
					if(decmin>9)
					{
						min=0;
					}
					set_min(min);
				}
				
				if (PIND&0b00001000)
				{
					b_state=0;
				}
				
				break;
			}			
		}			
	}	
}