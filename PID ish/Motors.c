#include "Motors.h"

void timer0_init(){
	
	DDRB |= (1<<7);
	DDRD |= (1<<0);
	TCCR0A |= (1<<7)|(1<<5)|(1<<1)|1;
	TIMSK0 |= (1<<0);
	OCR0A = 0;
	OCR0B = 0;
	TCCR0B |= (1<<2);
	
	return;
}

void timer1_init(){
	
	DDRB |= (1<<6)|(1<<5);
	TCCR1A |= (1<<7)|(1<<5)|1;
	TCCR1B |= (1<<3);
	TIMSK1 |= (1<<0);
	OCR1A = 0;
	OCR1B = 0;
	TCCR1B |= (1<<2);
	
	return;
}

void setMotorSpeeds(uint8_t MotorSpeeds[2]){
	
	OCR0A = MotorSpeeds[0];
	OCR1A = MotorSpeeds[1];

	return;
}
	