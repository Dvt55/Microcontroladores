#include <MKL25Z4.h>

//Habilita o clock para o ADC0;
//Configura resolução;
void Sensor_Temp_Setup();


//Configura o canal
//Verifica se o canal recebe sinal
//retorna valor de sinal digital
uint16_t Sensor_Temp_Read();

