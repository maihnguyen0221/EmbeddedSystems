#include <avr/io.h>
#include <avr/interrupt.h>

int pin4 = 4;
int pin5 = 5;
int pin7 = 7;
int pin2 = 2;
int pin3 = 3;


void setup() {

  // put your setup code here, to run once:
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin7, OUTPUT);

  // enable pull up resistor
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);

  //interupt
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 31250;
  TIMSK1 = (1 << OCIE1A);
  TCCR1B |= (1 << WGM12);

  //prescalar
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);

  sei();

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_COMPA_vect){

  digitalWrite(pin5, HIGH);

  EIMSK |= (1 << INT0);
  EIMSK |= (1 << INT1);

}

ISR(INT0_vect){
  
  EIMSK = 0;
  TIMSK1 = 0;

  digitalWrite(pin5, LOW);
  digitalWrite(pin4, HIGH);
  

}

ISR(INT1_vect){
  EIMSK = 0;
  TIMSK1 = 0;

  digitalWrite(pin5, LOW);
  digitalWrite(pin7, HIGH);

  

}
