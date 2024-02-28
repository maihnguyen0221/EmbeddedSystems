#include <avr/io.h>
#include <avr/interrupt.h>

int pin2 = 2;
int pin3 = 3;
int pin5 = 5;
int pin7 = 7;

//timer variables
int ledState = 0; //initialize to 0 for the first state

void setup() {
  Serial.begin(9600);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin7, OUTPUT);
  
  cli();
  TCCR1A = 0; // set timer control to 0
  TCCR1B = 0;

  OCR1A = 31250; //1024 compare value

  // OCR1A = 125000; //256 compare value

  //enable timer1 overflow interrupt
  TIMSK1 = (1 << OCIE1A);
  
  TCCR1B |= (1 << WGM12);

  //prescaler 1024 register values
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);

  //prescaler 256 register values
  // TCCR1B |= (1 << CS12);
  
  sei();

  //set up timer 1 with appropriate prescaler for 1 second overflow

}

void loop() {
  // while waiting for an interrupt

  //ask user for a number between 1 and 9
  Serial.println("Enter a number between 1 and 9: ");

  while(Serial.available() == 0);
  int x = Serial.parseInt();

  //calculate the sum of numbers from 1 to x
  int sum = 0;
  for (int i = 1; i <= x; i++){
    sum += i;
  }
  Serial.print("Total sum: ");
  Serial.println(sum);
  

}

ISR(TIMER1_COMPA_vect){
  // handle the interrupt

  //update the led state, for first interupt it always starts with case 0
  switch (ledState){
    case 0:
      //first interrupt turn on LED 2
      //turn off all LEDS
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin5, LOW);
      digitalWrite(pin7, LOW);

      digitalWrite(pin2, HIGH);

      //set state for next interrupt
      ledState = 1;
      break;

    case 1:
      //next interupt turn off LED 2, turn on LED 3
      digitalWrite(pin2, LOW);
      digitalWrite(pin3,HIGH);

      //set state for next interrupt
      ledState = 2;
      break;

    case 2:
      //next interrupt turn off LED 3, turn on LED 5
      digitalWrite(pin3, LOW);
      digitalWrite(pin5, HIGH);

      //set state for next interrupt
      ledState = 3;
      break;

    case 3:
      //next interrupt turn off LED 5, turn on LED 7
      digitalWrite(pin5, LOW);
      digitalWrite(pin7, HIGH);

      //set state for next interrupt, loops backaround to ledpin2 again
      ledState = 0;
      break;

  }

}
