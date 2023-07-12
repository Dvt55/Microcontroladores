#include <MKL25Z4.h>
#include "Sensor_Temp.h"

void Sensor_Temp_Setup(){

	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	ADC0->CFG1 |= ADC_CFG1_MODE(0b01);
}

uint16_t Sensor_Temp_Read(){
	ADC0->SC1[0] = 9;
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
	return ADC0->R[0];
}
