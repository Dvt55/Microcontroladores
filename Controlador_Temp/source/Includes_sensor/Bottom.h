#include <MKL25Z4.h>

/**
 * @brief Habilita o clock para PORTA, define pino como GPIO e como entrada
 */
void Configura_CLK_Bottom();

/**
 * @brief Verifica se o botão está ativado
 *
 * @return Retorna 1 se o botão está ativo e 0 se não está ativo.
 */
int Bottom_Ativado();

