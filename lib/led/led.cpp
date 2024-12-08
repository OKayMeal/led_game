#include "led.h"

// Constructor: store the pin number and initialize state to off
LED::LED(uint8_t pinNumber) : pin(pinNumber), state(false) {}

// Set the pinMode for the LED pin
void LED::begin() {
    pinMode(pin, OUTPUT);
    off(); // Ensure the LED starts in the off state
}

// Turn the LED on
void LED::on() {
    digitalWrite(pin, HIGH);
    state = true;
}

// Turn the LED off
void LED::off() {
    digitalWrite(pin, LOW);
    state = false;
}

// Toggle the LED state
void LED::toggle() {
    state = !state;
    digitalWrite(pin, state ? HIGH : LOW);
}

// Return the current state of the LED
bool LED::isOn() const {
    return state;
}
