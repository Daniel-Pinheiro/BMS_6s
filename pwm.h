#define Tpwm 400
#define Ganho 5

class PseudoPWM
{
private:
  uint8_t bitPorta;
  bool estado = LOW;
  unsigned int deltaT = 50;
  unsigned long tempoAnterior=0, tempoAtual, tempoProximo=0;

public:
  PseudoPWM(int n){
    bitPorta = (1<<n);
  }
  
  void setDutycicle(uint8_t duty) {
    deltaT = (long)(duty * Ganho) * Tpwm >> 8;
  }
  
  void subir() {
    PORTB |= bitPorta;
    estado = HIGH;
  }
  
  void descer() {
    PORTB &= ~bitPorta;
    estado = LOW;
  }
  
  void process()
  {
    tempoAtual = micros();
  
    if(tempoAtual >= tempoProximo) {
      descer();
      tempoAnterior = tempoAtual;
      tempoProximo = tempoAnterior + Tpwm;
    }
    
    if(estado==LOW) if(tempoAtual > (tempoProximo - deltaT) ) 
      subir();
  }
};

PseudoPWM pwm0(0), pwm1(1), pwm2(2), pwm3(3), pwm4(4), pwm5(5), pwm6(6), pwm7(7);
/*
void pwm0_exec()
{
  if(pwm0.process())
    PORTD |= bitPorta;
  else
    PORTD &= ~bitPorta;
    
}
*/
