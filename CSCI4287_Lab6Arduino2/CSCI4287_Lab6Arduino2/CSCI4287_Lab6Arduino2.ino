#include <avr/io.h>

int ledpin = 8;
int incoming;
char value;

void setup() {
  //set the baud rate
  Serial.begin(9600);

  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  incoming = Serial.available();
  while(incoming == 0){
    incoming = Serial.available();
  }
  value = Serial.read(); //reads the data

  if (value == '1'){
    digitalWrite(ledpin, HIGH);
  } 
  else if (value == "0") {
    digitalWrite(ledpin, LOW);
  }

}
