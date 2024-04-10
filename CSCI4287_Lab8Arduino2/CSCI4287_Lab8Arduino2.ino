
#include <Wire.h>

int ledpin = 8;
int incoming;
char value;

//SLAVE CODE

void setup() {
  //join i2c bus (address optional for master)
  Wire.begin(4);
  Wire.onReceive(receiveEvent); // register event

  //set the baud rate
  Serial.begin(9600);

  pinMode(ledpin, OUTPUT);
}

void loop() {
  delay(1000);
}

void receiveEvent(){

  
  
  // while (Wire.available() == 1){
  //   value = Wire.read();
  // }
  value = Wire.read();
  Serial.println(value);
  
  if (value == '1'){
    digitalWrite(ledpin, HIGH);
  } 
  else if (value == '0') {
    digitalWrite(ledpin, LOW);
  }

}
