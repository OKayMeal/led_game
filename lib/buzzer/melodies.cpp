#include <melodies.h>

// Add more melodies here to make the game more interesting

// Melody 1
const NoteInfo melody1[] = {
    {"NOTE_A4", 500, 500},
    {"NOTE_B4", 500, 500},
    {"NOTE_C5", 500, 500},
    {"NOTE_D5", 500, 500},
    {"NOTE_E5", 500, 1000}
};

// Length of the melody (number of notes)
const int melodyLength = sizeof(melody1) / sizeof(melody1[0]);

// Aggregated melodies pointers in one arr
const NoteInfo* melodies[] = { melody1 };
const int MELODIES_COUNT = sizeof(melodies) / sizeof(melodies[0]);