#include <MKL25Z4.h>

/**
 * @brief Habilita clock para o PORTE e configura os pinos dos leds como GPIO
 */
void Led_setup();

/**
 * @brief Define os pinos dos leds como pinos de saída
 */
void Led_configure();

/**
 * @brief Seta o pino do led vermelho como 1 para ligar o led
 */
void Liga_led_vermelho();

/**
 * @brief Seta o pino do led vermelho como zero para desligar
 */
void Desliga_led_vermelho();
void Liga_led_amarelo();
void Desliga_led_amarelo();
void Liga_led_verde();
void Desliga_led_verde();
