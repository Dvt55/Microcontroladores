# Microcontroladores

Projeto utilizando linguagem C e placa KL25Z para controle de temperatura ambiente.

Materiais utilizados:

- KL25Z
- Cooler 12V - 0.28A
- Sensor de temperatura
- Protoboard
- LED vermelho, verde e amarelo
- H L298N

O funcionamento é simples: Ao detectar uma temperatura muito acima do ideal o cooler é acionado com PWM de 100%.
Ao atingir uma temperatura razoável o PWM é diminuído.
Enquanto não estiver numa temperatura ideal, o led fica vermelho. Caso a temperatura esteja acima do normal por muito tempo
mesmo que o cooler esteja ligado então um led amarelo é acionado avisando que temos algum defeito no equipamento.
Caso a temperatura esteja ideal então o led verde ficará ligado.
