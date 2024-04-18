#include <avr/io.h>
#include <avr/interrupt.h>

int pin4 = 4;

int button1pin = 2; //source for INT0 input interrupt

//since not using input interrupt you can change the pin number for this pin to anything
int button2pin = 8; 

int num1 = 0;

void setup() {

  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(pin4, OUTPUT);
  

  // enable pull up resistor
  digitalWrite(button1pin, HIGH);


  pinMode(button2pin, INPUT_PULLUP);
  
  
  //interupt
  cli();
  //enable external interrupt INT0
  EIMSK |= (1<< INT0);

  //trigger INT0 on falling edge
  EICRA |= (1 << CS01);

  sei();

}

void loop() {
  // put your main code here, to run repeatedly:

  //this is code I just used to test if the input interrupt works with interrupting code here.
  num1 += 1;
  Serial.print("This is num1: ");
  Serial.println(num1);

  delay(4000);
}


ISR(INT0_vect){
  //turn on LED
  digitalWrite(pin4, HIGH);

  //add whatever code to stop the motor from spinning.

  while (digitalRead(button2pin) != LOW){
    //meaning the button2 is not pressed it will keep looping
    continue;

  }
  //turn off LED
  digitalWrite(pin4, LOW);
}

