#include "pitches.h"

#define NOTE_REST 0
#define NOTE_END -1
#define NOTE_REPEAT -2

// notes in the melody:
// note durations: 4 = quarter note, 8 = eighth note, etc.:
 int score[][2] = {
  { 16, NOTE_C2 },
  { 16, NOTE_C3 },
  { 16, NOTE_A2 },
  { 16, NOTE_A3 },
  { 16, NOTE_AS2 },
  { 16, NOTE_AS3 },
  { 8, NOTE_REST },
  { 4, NOTE_REST },
// bar
  { 16, NOTE_C2 },
  { 16, NOTE_C3 },
  { 16, NOTE_A2 },
  { 16, NOTE_A3 },
  { 16, NOTE_AS2 },
  { 16, NOTE_AS3 },
  { 8, NOTE_REST },
  { 4, NOTE_REST },
// bar
  { 16, NOTE_F2 },
  { 16, NOTE_F3 },
  { 16, NOTE_D2 },
  { 16, NOTE_D3 },
  { 16, NOTE_DS2 },
  { 16, NOTE_DS3 },
  { 8, NOTE_REST },
  { 4, NOTE_REST },
// bar
  { 16, NOTE_F2 },
  { 16, NOTE_F3 },
  { 16, NOTE_D2 },
  { 16, NOTE_D3 },
  { 16, NOTE_DS2 },
  { 16, NOTE_DS3 },
  { 4, NOTE_REST },
  { 16, NOTE_DS3 },
  { 16, NOTE_D3 },
  { 16, NOTE_CS3 },
// bar
  { 8, NOTE_C3 },
  { 8, NOTE_DS3 },
  { 8, NOTE_D3 },
  { 8, NOTE_GS3 },
  { 8, NOTE_G3 },
  { 8, NOTE_CS3 },
// bar
  { 24, NOTE_C3 },
  { 24, NOTE_FS3 },
  { 24, NOTE_F3 },
  { 24, NOTE_E3 },
  { 24, NOTE_AS3 },
  { 24, NOTE_A3 },
  { 12, NOTE_GS3 },
  { 12, NOTE_DS3 },
  { 12, NOTE_B3 },
  { 12, NOTE_AS3 },
  { 12, NOTE_A3 },
  { 12, NOTE_GS3 },
// bar
  { 4, NOTE_REST },
  { 4, NOTE_REST },
  { 4, NOTE_REST },
// bar
  { 16, NOTE_C2 },
  { 16, NOTE_C3 },
  { 16, NOTE_A2 },
  { 16, NOTE_A3 },
  { 16, NOTE_AS2 },
  { 16, NOTE_AS3 },
  { 4, NOTE_REST },
// C'est fini! 
  { 1, NOTE_END }
};

void setup() {
  playTune();
}

void playTune()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0;; thisNote++) {

    int noteTone = score[thisNote][1];

    switch(noteTone) {
      case NOTE_END:
 	  return;
      case NOTE_REPEAT:
          thisNote = -1;  // for will iterate to 0
          continue;
      default:
         float noteDuration = 1900/score[thisNote][0];

         tone(8, noteTone, noteDuration);
         int pauseBetweenNotes = noteDuration * 1.2;
         delay(pauseBetweenNotes);
         noTone(8);  
       }
  }
}

void loop() {
}
