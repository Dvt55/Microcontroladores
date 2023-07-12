/*
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    Controlador_Temp.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "Sensor_Temp.h"
#include "Includes_sensor/Cooler.h"
#include "Includes_sensor/Bottom.h"
#include "Includes_sensor/LED.h"
#include "Includes_sensor/Timer.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int ativado = 1;


int main(void) {

    /* Init board hardware. */

	Sensor_Temp_Setup();
	PWM_SETUP();
	Configura_CLK_Bottom();
	TPM1_Init();
	Led_setup();
	Led_configure();

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();


	Desliga_led_amarelo();
    while(1) {

    	uint16_t value_sensor = Sensor_Temp_Read();
    	uint32_t mili_volts = (int32_t) ((value_sensor/4096.0)*(3300.0));
    	uint32_t Temperatura = mili_volts/10;
    	PRINTF("Temperatura: %d Graus\r\n", Temperatura);



    	if(TPM1->CNT == 0){
    		ativado = 1;
    	}
    	if(Temperatura >= 33){

    		if(ativado == 1){
    		   TPM1->SC |= (0b01U << 3 ); //Começa contagem até 20 segundos
    		   ativado = 0;
    		}
    		Liga_led_vermelho();
    		Desliga_led_verde();

    		Liga_Cooler();

    	}

    	if(Temperatura <= 30 && (Bottom_Ativado() == 0)){
    		Liga_led_verde();
    		Desliga_led_amarelo();
    		Desliga_led_vermelho();
    		Desliga_Cooler();
    		ativado = 1;
    	}
    	if(Temperatura <= 30 && Bottom_Ativado()){
    	    Liga_led_verde();
    	    Desliga_led_amarelo();
    	    Desliga_led_vermelho();
    	    Liga_Cooler_Controlado();
    	    ativado = 1;
    	 }

    	if((Temperatura > 30) && (Temperatura < 33)){
    		if(Bottom_Ativado()){
    			Liga_Cooler_Controlado();
    		}
    		else{
    			Desliga_Cooler();
    		}
    		Liga_led_verde();
    		Desliga_led_amarelo();
    		Desliga_led_vermelho();

    	}

    }

}
