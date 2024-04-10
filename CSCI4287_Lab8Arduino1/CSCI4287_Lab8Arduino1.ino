
#include <Wire.h>

int button1pin = 2;
int button2pin = 3;

//MASTER CODE

void setup() {
  //join i2c bus (address optional for master)
  Wire.begin();

  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  Wire.beginTransmission(4); //transmit to device 8
  

  if (digitalRead(button1pin) == LOW){
    //if button 1 is pushed send a 1 to arduino 2
    Wire.write('1');
  }
  else if (digitalRead(button2pin) == LOW){
    Wire.write('0');
  }
  Wire.endTransmission();
}

