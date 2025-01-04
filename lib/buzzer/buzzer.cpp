#include <buzzer.h>

Buzzer::Buzzer(uint8_t pinNumber) : pin(pinNumber) {}

void Buzzer::begin() {
    pinMode(pin, OUTPUT);
    stop();
    Serial.println("Buzzer initialized!");
}

void Buzzer::playMelody(const NoteInfo melody[], int melodyLength) {
    for (int i = 0; i < melodyLength; i++) {
        playNote(&melody[i]);
    }

    // stop playing
    stop();
    Serial.println("Melody finished!");
}

void Buzzer::playNote(const NoteInfo* noteInfo) {
    int frequency = getFrequency(noteInfo->note);

    if (frequency != 0) {
        // play note
        Serial.print("Playing note: ");
        Serial.println(noteInfo->note);
        tone(pin, frequency);

        // wait for the duration of the note
        delay(noteInfo->duration);
        
        // wait for.delay before the next note
        delay(noteInfo->delay);
    } else {
        Serial.print("Note not found: ");
        Serial.println(noteInfo->note);
        stop();
    }
}

void Buzzer::stop() {
    noTone(pin);
    digitalWrite(pin, HIGH);
    Serial.println("Buzzer OFF!");
}