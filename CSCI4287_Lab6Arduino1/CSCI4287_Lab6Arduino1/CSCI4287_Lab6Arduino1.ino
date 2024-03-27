#include <avr/io.h>

int button1pin = 2;
int button2pin = 3;

void setup() {
  //set the baud rate
  Serial.begin(9600);

  //enable pull-up resistors for buttons
  //digitalWrite (button1pin, HIGH);
  //digitalWrite (button2pin, HIGH);
  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1pin) == LOW){
    //if button 1 is pushed send a 1 to arduino 2
    Serial.println('1');
  }
  else if (digitalRead(button2pin) == LOW){
    Serial.println('0');
  }
}

