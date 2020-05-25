/*  -----------------------------------------------------------
 *   Autor: Daniel Borges
 *   Data: maio de 2020
 *   Projeto: BMS escravo com equalização passiva p/ 8 células
 *  -----------------------------------------------------------
 */
#include "leituraCelulas.h"

int valorCelula[8], menorValor;

void setup() {
  Serial.begin(57600);
  configADCports();
  DDRB = 0b11111111;
}

void loop() {
  while(1){
    pwm0.process();
    pwm1.process();
    pwm2.process();
    pwm3.process();
    pwm4.process();
    pwm5.process();
    pwm6.process();
    pwm7.process();
  }
  /*
  Serial.print(sampleTime);
  Serial.print(", ");
  Serial.print(menorValor);
  Serial.print(", ");
  Serial.print(valorCelula[0]);
  Serial.print(" ");
  Serial.print(valorCelula[1]);
  Serial.print(" ");
  Serial.print(valorCelula[2]);
  Serial.print(" ");
  Serial.print(valorCelula[3]);
  Serial.print(" ");
  Serial.print(valorCelula[4]);
  Serial.print(" ");
  Serial.print(valorCelula[5]);
  Serial.print(" ");
  Serial.print(valorCelula[6]);
  Serial.print(" ");
  Serial.println(valorCelula[7]);

  delay(1);*/
}
