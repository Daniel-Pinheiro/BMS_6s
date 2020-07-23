/*  ---------------------------------------------------------------
 *   Autor: Daniel Borges
 *   Data: julho de 2020
 *   Projeto: BMS escravo com equalização passiva p/ até 6 células
 *   Versão: 1.0
 *  ---------------------------------------------------------------
 */
#include "leituraCelulas.h"

uint16_t valorCelula[NumCel], menorValor;

void setup() {
  configADCports();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(57600);
  pinMode(pinoRele,OUTPUT); digitalWrite(pinoRele, LOW);
  pinMode(11,OUTPUT);
}

void runPWMs() {
  PINB=0B00001000;
  pwm0.process();
  pwm1.process();
  pwm2.process();
  pwm3.process();
  pwm4.process();
  pwm5.process();
  PINB=0B00001000;
}
void loop() {
  runPWMs();
  //Próxima implementação: chamar rotinas dos pwms por interrupções do timer2 para evitar grandes esperas 
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
