#include "button.h"
#include "Arduino.h"
#include "led.h"


class Button {
private:
    uint8_t pin;
    int index;      
    bool lastState;           
    unsigned long lastDebounceTime;
    const unsigned long debounceDelay = 50;
    LED* led;
    const NoteInfo* note;

public:
    Button(uint8_t pinNumber, int index, LED& ledObject) : pin(pinNumber), index(index), lastState(HIGH), lastDebounceTime(0), led(&ledObject), note(nullptr) {}

    // Set the pinMode for the button pin
    void begin() {
        pinMode(pin, INPUT_PULLUP); // Configure button pin as input with pull-up resistor
    }

    // Check if the button is pressed (with debouncing)
    bool isPressed() {
        bool currentState = digitalRead(pin);
        
        // Check if the button state has changed
        if (currentState != lastState) {
            lastDebounceTime = millis();
        }

        // If the state has been stable for long enough, consider it a valid press
        if ((millis() - lastDebounceTime) > debounceDelay) {
            if (currentState == LOW && lastState == HIGH) { // Button was just pressed
                lastState = currentState;
                return true;
            }
        }

        lastState = currentState; // Update the last state
        return false;
    }

    void setNote(const NoteInfo* note) {
        this->note = note;

        Serial.print("Note ");
        Serial.print(this->note->note);
        Serial.print("set for Button ");
        Serial.println(this->index);
    }
};