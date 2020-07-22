#define Tpwm 1000
#define Ganho 5

class PseudoPWM
{
private:
  uint8_t bitPorta;
  uint8_t *PORTx;
  bool estado = LOW;
  unsigned int deltaT = 50;
  unsigned long tempoAnterior=0, tempoAtual, tempoProximo=0;

public:
  PseudoPWM(uint8_t *registradorPORTx, int n){
    bitPorta = (1<<n);
    PORTx = registradorPORTx;
  }
  
  void setDutycicle(uint8_t duty) {
    deltaT = (long)(duty * Ganho) * Tpwm >> 8;
  }
  
  void subir() {
    *PORTx |= bitPorta;
    estado = HIGH;
  }
  
  void descer() {
    *PORTx &= ~bitPorta;
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

PseudoPWM pwm0(&PORTD, 6),
          pwm1(&PORTD, 7),
          pwm2(&PORTD, 2),
          pwm3(&PORTD, 3),
          pwm4(&PORTD, 4),
          pwm5(&PORTD, 5);
