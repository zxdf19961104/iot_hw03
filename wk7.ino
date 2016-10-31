
#include "pitches.h"
#define MIC_PIN A0
#define BUZ_PIN 8
#define LED_PIN 13
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
  pinMode(MIC_PIN,INPUT);
  pinMode(BUZ_PIN,OUTPUT);
  pinMode(LED_PIN,OUTPUT);
  }
void loop() {
  int mic = analogRead(MIC_PIN);
  if(mic >= 350){
    digitalWrite(LED_PIN,HIGH);
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZ_PIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZ_PIN);}
  }
  else{digitalWrite(LED_PIN,LOW);}
}
