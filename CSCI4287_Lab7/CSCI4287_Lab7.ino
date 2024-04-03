
#include "pitches.h"
int speakerPinNumber = 8;

int melody[] = {
NOTE_D4, 0, NOTE_F4, NOTE_D4, 0, NOTE_D4,
NOTE_G4, NOTE_D4, NOTE_C4, NOTE_D4, 0, NOTE_A4,
NOTE_D4, 0, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_F4,
NOTE_D4, NOTE_A4, NOTE_D5, NOTE_D4, NOTE_C4, 0,
NOTE_C4, NOTE_A3, NOTE_E4, NOTE_D4, 0
};
// note type: 4 = quarter note, 8 = eighth note, etc.:
int noteType[] = {
8, 8, 6, 16, 16, 16,
8, 8, 8, 8, 8, 6,
16, 16, 16, 8, 8, 8,
8, 8, 8, 16, 16, 16,
16, 8, 8, 2, 2
};
int pitch;
int toneNoteType;
int toneDuration;
int pauseTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(speakerPinNumber, OUTPUT);
  //Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //size of array = 29
  for (int i = 0; i <= 29; i++){
    pitch = melody[i];
    toneNoteType = noteType[i];
    toneDuration = 1000/toneNoteType;
    tone(speakerPinNumber, pitch, toneDuration);
    pauseTime = toneDuration * 1.3;
    delay(pauseTime);
  }
  //Serial.println("finished");

}
