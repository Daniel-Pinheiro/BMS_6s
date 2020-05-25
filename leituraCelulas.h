#include "pwm.h"
#include <FastADC.h>  //Biblioteca para leitura rapida e paralela das entradas paralelas
                      //https://github.com/krisdover/FastADC
FastADC(analog, 8, true);

extern int valorCelula[8], menorValor;
void atualizarMenorValor()
{
  for(int8_t k=0; k<8; k++)
    if(valorCelula[k] < menorValor)
      menorValor = valorCelula[k];
}

#define declaraFuncaoLerCelula(N)                                 \
void lerCelula##N(uint16_t valorLido, uint16_t sampleTimeMicros)  \
{                                                                 \
  valorCelula[N]=valorLido;                                       \
  menorValor = valorLido;                                         \
  atualizarMenorValor();                                          \
  pwm##N.setDutycicle( valorCelula[N]-menorValor );               \
} //Macro que automatiza criação de funções para cada porta analógica

declaraFuncaoLerCelula(0);
declaraFuncaoLerCelula(1);
declaraFuncaoLerCelula(2);
declaraFuncaoLerCelula(3);
declaraFuncaoLerCelula(4);
declaraFuncaoLerCelula(5);
declaraFuncaoLerCelula(6);
declaraFuncaoLerCelula(7);

void configADCports()
{
  analog.handle(0, DEFAULT, lerCelula0);
  analog.handle(1, DEFAULT, lerCelula1);
  analog.handle(2, DEFAULT, lerCelula2);
  analog.handle(3, DEFAULT, lerCelula3);
  analog.handle(4, DEFAULT, lerCelula4);
  analog.handle(5, DEFAULT, lerCelula5);
  analog.handle(6, DEFAULT, lerCelula6);
  analog.handle(7, DEFAULT, lerCelula7);
}
