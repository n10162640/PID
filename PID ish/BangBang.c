#define F_CPU 16000000UL

#include <avr/io.h>
#include "Motors.h"


#define THRESHOLD 128
#define FULL_SPEED 254
#define HALF_SPEED FULL_SPEED/2

int main()
{
   
	timer0_init();
	timer1_init();
	ADC_init();

	uint8_t motorSpeeds[2] = {0,0};
	uint8_t sensorReading[2] = {0,0};

	
while(1){

	sensorReading = SensorValue();

	if(sensorReading == THRESHOLD){
		motorSpeeds[0] = FULL_SPEED;
		motorSpeeds[1] = FULL_SPEED;
	}else if(sensorReading < THRESHOLD){
		motorSpeeds[0] = HALF_SPEED;
		motorSpeeds[1] = FULL_SPEED;
	}else if(sensorReading > THRESHOLD){
		motorSpeeds[0] = FULL_SPEED;
		motorSpeeds[1] = HALF_SPEED;
	}
	setMotorSpeeds(motorSpeeds);
}		
	return 0;
}