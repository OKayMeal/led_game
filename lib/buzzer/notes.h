#ifndef NOTES_H
#define NOTES_h

#include <Arduino.h>

extern const char* noteNames[];
extern const int noteFrequencies[];
extern int getFrequency(const String& note);

#endif // NOTES_H


