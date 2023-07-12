#include <MKL25Z4.h>
#include "Includes_sensor/LED.h"

#define LED_VERMELHO_PIN 30
#define LED_AMARELO_PIN 29
#define LED_VERDE_PIN 23

void Led_setup(){
	SIM->SCGC5 |= (1<<13);
	PORTE->PCR[LED_VERMELHO_PIN] |= (1<<8);
	PORTE->PCR[LED_AMARELO_PIN] |= (1<<8);
	PORTE->PCR[LED_VERDE_PIN] |= (1<<8);
}
void Led_configure(){
	GPIOE->PDDR |= (1<<LED_VERMELHO_PIN);
	GPIOE->PSOR |= (1<<LED_VERMELHO_PIN);

	GPIOE->PDDR |= (1<<LED_AMARELO_PIN);
	GPIOE->PSOR |= (1<<LED_AMARELO_PIN);

	GPIOE->PDDR |= (1<<LED_VERDE_PIN);
	GPIOE->PSOR |= (1<<LED_VERDE_PIN);
}
void Liga_led_vermelho(){
	GPIOE->PSOR |= (1<<LED_VERMELHO_PIN);
}
void Desliga_led_vermelho(){
	GPIOE->PCOR |= (1<<LED_VERMELHO_PIN);
}
void Liga_led_amarelo(){
	GPIOE->PSOR |= (1<<LED_AMARELO_PIN);
}
void Desliga_led_amarelo(){
	GPIOE->PCOR |= (1<<LED_AMARELO_PIN);
}
void Liga_led_verde(){
	GPIOE->PSOR |= (1<<LED_VERDE_PIN);
}
void Desliga_led_verde(){
	GPIOE->PCOR |= (1<<LED_VERDE_PIN);
}
