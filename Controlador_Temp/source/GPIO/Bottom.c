#include <MKL25Z4.h>
#include "Includes_sensor/Bottom.h"
#include "Includes_sensor/Cooler.h"
#define  BTN_PIN 17


int Bottom_Pressed = 0;

void PORTA_IRQHandler(){
	if(PORTA->ISFR & (1U << BTN_PIN)) {
		if(Bottom_Pressed == 0){
			Bottom_Pressed = 1;
			Liga_Cooler_Controlado();
			//Desliga_Cooler();
		}
		else{
			Bottom_Pressed = 0;
			Desliga_Cooler();
			//Liga_Cooler_Controlado();
		}


	}
	PORTA->ISFR |= (1U << BTN_PIN);
}

void Configura_CLK_Bottom(){
	SIM->SCGC5 |= (1 << 9);
	PORTA->PCR[BTN_PIN] |= (1 << 8);  // Enable GPIO
	GPIOA->PDDR &= ~(1 << BTN_PIN);
	PORTA->PCR[BTN_PIN] |= PORT_PCR_IRQC(9);  // Enable GPIO
	PORTA->PCR[BTN_PIN] |= (1 << 1);  // Pull Enable
	PORTA->PCR[BTN_PIN] &= ~(1 << 0);  // Pull Select
	NVIC_EnableIRQ(PORTA_IRQn);







}
int Bottom_Ativado(){
	if(Bottom_Pressed == 1){
		return 1;
	}
	return 0;
}

