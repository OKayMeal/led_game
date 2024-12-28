#ifndef MELODIES_H
#define MELODIES_H

#include <notes.h>

// Fixed-size array to hold a melody
struct NoteInfo {
    String note;
    int duration;       /** Duration for the note to play */
    int delay;          /** Delay before the next note  */
};

// Declare melody1, getFrequency, and noteNames as extern to avoid multiple definitions
extern const NoteInfo melody1[];
extern const int melody1Length;

#endif // MELODIES_H
