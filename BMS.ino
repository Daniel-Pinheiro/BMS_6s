/*  -----------------------------------------------------------
 *   Autor: Daniel Borges
 *   Data: maio de 2020
 *   Projeto: BMS escravo com equalização passiva p/ 8 células
 *  -----------------------------------------------------------
 */
#include "leituraCelulas.h"

int valorCelula[7], menorValor;

void setup() {
  valorCelula[6]=0;
  configADCports();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(57600);
}

void loop() {
  while(1){
    pwm0.process();
    pwm1.process();
    pwm2.process();
    pwm3.process();
    pwm4.process();
    pwm5.process();
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
