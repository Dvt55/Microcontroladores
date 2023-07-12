#include <MKL25Z4.h>

/**
 * @brief Guarda no registrador CNV o valor do duty cycle que pode ser
 * calculado como: (Valor do MOD)*X%
 */
void PWM_Write(uint16_t duty_cycle);

/**
 * @brief Configura o PWM usando o registrador TPM0 para o pino 1 do PORTD
 * que vai ser o pino do cooler
 */
void PWM_SETUP();

/**
 * @brief Liga o Cooler com Duty Cycle de 100%
 */
void Liga_Cooler();

/**
 * @brief Duty Cycle de 0% é usado para desligar o cooler
 */
void Desliga_Cooler();

/**
 * @brief Liga o cooler com duty cycle de 50%
 */
void Liga_Cooler_Controlado();
