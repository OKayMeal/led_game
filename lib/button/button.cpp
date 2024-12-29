#include "button.h"
#include "Arduino.h"
#include "led.h"

// Constructor
Button::Button(uint8_t pinNumber, int buttonIndex, LED& ledObject) 
                : 
                pin(pinNumber), index(buttonIndex), led(&ledObject),
                lastState(HIGH), lastDebounceTime(0), note(nullptr) {}

// Set the pinMode for the button pin
void Button::begin() {
    pinMode(pin, INPUT_PULLUP); // Configure button pin as input with pull-up resistor
}

// Check if the button is pressed (with debouncing)
bool Button::isPressed() {
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

void Button::setNote(const NoteInfo* note) {
    this->note = note;

    Serial.print("Note ");
    Serial.print(this->note->note);
    Serial.print("set for Button ");
    Serial.println(this->index);
}