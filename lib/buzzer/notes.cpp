#include <notes.h>

const char* noteNames[] = {
    "NOTE_C4", "NOTE_Cs4", "NOTE_D4", "NOTE_Ds4", "NOTE_E4", "NOTE_F4", 
    "NOTE_Fs4", "NOTE_G4", "NOTE_Gs4", "NOTE_A4", "NOTE_As4", "NOTE_B4", 
    "NOTE_C5", "NOTE_Cs5", "NOTE_D5", "NOTE_Ds5", "NOTE_E5", "NOTE_F5", 
    "NOTE_Fs5", "NOTE_G5", "NOTE_Gs5", "NOTE_A5", "NOTE_As5", "NOTE_B5", 
    "NOTE_C6"
};

const int noteFrequencies[] = {
    262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
    523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 
    1047
};

// Function to get the frequency based on the note name
int getFrequency(const String& note) {
    for (int i = 0; i < 25; i++) {
        if (note.equals(noteNames[i])) {
            return noteFrequencies[i];
        }
    }
    return 0;
}