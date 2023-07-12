#include "Includes_sensor/Timer.h"
#include "Includes_sensor/LED.h"

void TPM1_Init () {

	//Define clock de 32768 Khz do registrador MCG
	MCG->C1 |= (1U << 1 );
	MCG->C2 &= ~(1U << 0 );

	// SELECT 32768 KHz.
	SIM->SOPT2 |= (0b11<<24);

	//Habilita TPM1 clock
	SIM->SCGC6 |= (1U << 25);

	TPM1->SC |= (0b101U << 0) ;
	TPM1->SC |= (1U<< 6);
	TPM1->MOD = 20480;
	NVIC->ISER[0] |= (1U << 18 );

}
void TPM1_IRQHandler (){

	//Limpa flag de interrupção
	TPM1->SC |= (1U << 7 );
	Liga_led_amarelo();
	Desliga_led_verde();
	Desliga_led_vermelho();

}
