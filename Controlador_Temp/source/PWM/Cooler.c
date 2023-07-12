#include <MKL25Z4.h>
#include "Includes_sensor/Cooler.h"
#include "Includes_sensor/Bottom.h"
#define PWM_MIN_DUTY_CYCLE 0
#define PWM_MAX_DUTY_CYCLE 2000

void PWM_Write(uint16_t duty_cycle) {
	TPM0->CONTROLS[1].CnV = duty_cycle;
}

void PWM_SETUP(){
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD->PCR[1] |= PORT_PCR_MUX(4);
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(0b11);
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;
	MCG->C2 |= MCG_C2_IRCS_MASK;
	TPM0->SC = 0;
	TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
	TPM0->MOD = 2000;
	TPM0->SC |= TPM_SC_CMOD(0b01);
	PWM_Write(PWM_MIN_DUTY_CYCLE);
	}
void Liga_Cooler(){
	PWM_Write(PWM_MAX_DUTY_CYCLE);
	//Desabilita_Bottom();
}
void Desliga_Cooler(){
	PWM_Write(PWM_MIN_DUTY_CYCLE);
}
void Liga_Cooler_Controlado(){

	PWM_Write(1000);
}
