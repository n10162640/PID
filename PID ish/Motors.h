#ifndef MOTORS_H
#define MOTORS_H

#include <avr/io.h>


void timer0_init();
void timer1_init();
void setMotorSpeeds(uint8_t MotorSpeeds[2]);

#endif 