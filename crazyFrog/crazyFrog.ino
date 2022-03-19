/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

int PACE = 7;

// notes in the melody:
int part1[] = { 
  NOTE_D5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_C5
};

// notes in the melody:
int part2[] = {
  NOTE_D5, NOTE_A5, NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_F5
};

// notes in the melody:
int ending[] = {
  NOTE_D5, NOTE_A5, NOTE_D6, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_D5, 0,NOTE_C4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int basePartDurations[] = {
 50, 35, 25, 15, 25, 30, 30 
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int endingDurations[] = {
 30, 30, 30, 15, 30, 15, 30, 30, 100, 30, 50, 50 
};

void setup() {
}

void playPart(int melodyPart[], int durations[], int partLength) {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < partLength; thisNote++) {

    int noteDuration = durations[thisNote] * PACE;
    tone(8, melodyPart[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  playPart(part1, basePartDurations, 7);
  playPart(part2, basePartDurations, 7);
  playPart(ending, endingDurations, 12);
  delay(100);
}
