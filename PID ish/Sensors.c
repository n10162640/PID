#include "Sensors.h"

void ADC_init(){
	
	//ADC4 or Sensor1
	ADMUX |= (1<<REFS1)|(1<<REFS0)|(1 << ADLAR)| (1 << MUX1) | (1 << MUX2);
	ADCSRA |= (1<<ADEN)|(1 << ADATE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADCSRA |= (1 << ADSC);
	ADCSRA = 0;	
	
}

uint8_t SensorValue(){

	//ADCSRA |= (1<<ADSC);
	//while(ADCSRA & (1<<ADSC));
	//uint8_t sensor_out = ADCH;
int count = 0;
uint8_t sensor_out[2] = {0,0};
while (~ADCSRA&(1 << 4));				// delay Till ADC cycle ends
	//sensor matrix assinment
	if (count == 0) {
	// Switch to ADC6(sensor 3)
		sensor_out[1] = ADCH;
		ADCSRA |= (1 << MUX5);
		ADMUX &= ~(1 << MUX1);				
			}
	else if (count == 1) {
	// Switch to ADC10(sensor 6)
		sensor_out[0] = ADCH;
		ADMUX |= (1 << MUX1);
		ADCSRA &= ~(1 << MUX5);	

count == count + 1 % 2;	
	return sensor_out;
}
}