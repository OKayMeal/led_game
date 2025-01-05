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
extern const int melodyLength;
extern const NoteInfo* melodies[];
extern const int MELODIES_COUNT;
#endif // MELODIES_H
