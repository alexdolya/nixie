/*
 * clock.h
 *
 * Created: 28.03.2019 10:53:41
 *  Author: user
 */ 


#ifndef CLOCK_H_
#define CLOCK_H_

void set_dechours (uint8_t dechour);
void set_hours (uint8_t hour);
void set_decmin (uint8_t decmin);
void set_min (uint8_t min);
uint8_t read_dechours (void);
uint8_t read_hours (void);
uint8_t read_decmins (void);
uint8_t read_mins (void);

#endif /* CLOCK_H_ */