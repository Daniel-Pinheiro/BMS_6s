#include "pwm.h"
#include <FastADC.h>  //Biblioteca para leitura rapida e paralela das entradas paralelas
        //https://github.com/krisdover/FastADC

#define NumCel 6 //Número de células a serem lidas/controladas
#define pinoRele 9
#define maxValorCarga (int)(1024/5.0 * 3.65)

FastADC(analog, NumCel, true);

extern uint16_t valorCelula[NumCel], menorValor;
uint32_t erroAcumulado[NumCel];

void atualizarMenorValor()
{
  for(int8_t k=0; k<NumCel; k++)
    if(valorCelula[k] < menorValor)
      menorValor = valorCelula[k];
}

void interrompeCarga(){
  digitalWrite(pinoRele, HIGH);
}

#define verificaValorExcedido(valor)         \
  if(valor > maxValorCarga) interrompeCarga();

#define declaraFuncaoLerCelula(N)                                 \
void lerCelula##N(uint16_t valorLido, uint32_t sampleTimeMicros)  \
{                                                                 \
  valorLido = (valorCelula[N]+valorLido) >> 1;                    \
  valorCelula[N] = valorLido;                                     \
  menorValor = valorLido;                                         \
  atualizarMenorValor();                                          \
  pwm##N.setDutycicle( valorLido - menorValor );                  \
  verificaValorExcedido(valorLido);                               \
} //Macro que automatiza criação de funções para cada porta analógica

declaraFuncaoLerCelula(0);
declaraFuncaoLerCelula(1);
declaraFuncaoLerCelula(2);
declaraFuncaoLerCelula(3);
declaraFuncaoLerCelula(4);
declaraFuncaoLerCelula(5);

void configADCports()
{
  analog.handle(0, DEFAULT, lerCelula0);
  analog.handle(1, DEFAULT, lerCelula1);
  analog.handle(2, DEFAULT, lerCelula2);
  analog.handle(3, DEFAULT, lerCelula3);
  analog.handle(4, DEFAULT, lerCelula4);
  analog.handle(5, DEFAULT, lerCelula5);
}
