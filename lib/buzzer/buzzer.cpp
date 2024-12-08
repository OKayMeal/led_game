#include <buzzer.h>

Buzzer::Buzzer(uint8_t pinNumber) : pin(pinNumber) {}

void Buzzer::begin() {
    pinMode(pin, OUTPUT);
    Serial.println("Buzzer initialized!");
}

void Buzzer::playMelody(const NoteInfo melody[], int melodyLength) {
    for (int i = 0; i < melodyLength; i++) {
        playNote(melody, i);
    }

    // stop playing
    Serial.println("Melody finished!");
    stop();
}

void Buzzer::playNote(const NoteInfo melody[], int noteIndex) {
    int frequency = getFrequency(melody[noteIndex].note);

    if (frequency != 0) {
        // play note
        Serial.print("Playing note: ");
        Serial.println(melody[noteIndex].note);
        tone(pin, frequency);

        // wait for the duration of the note
        delay(melody[noteIndex].duration);
        
        // wait for.delay before the next note
        delay(melody[noteIndex].delay);
    } else {
        Serial.print("Note not found: ");
        Serial.println(melody[noteIndex].note);
        stop();
    }
}

void Buzzer::stop() {
    Serial.println("Buzzer OFF!");
    noTone(pin);
    digitalWrite(pin, HIGH);
}