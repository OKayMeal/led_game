#ifndef _LED_H_
#define _LED_H_

#include <Arduino.h>

/**
 * @class LED
 * @brief A class to control an LED connected to a specific Arduino pin.
 *
 * The LED class provides methods to turn an LED on, off, and toggle its state.
 * It encapsulates the pin number and current state of the LED.
 */
class LED {
private:
    uint8_t pin;         /** The Arduino pin number where the LED is connected */
    bool state;          /** The current state of the LED (true = ON, false = OFF) */

public:
    /**
     * @brief Constructs a new LED object with the specified pin number.
     *
     * Initializes the LED's pin number and sets its initial state to OFF.
     *
     * @param pinNumber The Arduino pin number to which the LED is connected.
     */
    LED(uint8_t pinNumber);

    /**
     * @brief Initializes the LED pin as an OUTPUT.
     *
     * Sets the Arduino pin mode to OUTPUT and ensures the LED starts in the OFF state.
     */
    void begin();

    /**
     * @brief Turns the LED on.
     *
     * Sets the LED pin to HIGH and updates the internal state to true.
     */
    void on();

    /**
     * @brief Turns the LED off.
     *
     * Sets the LED pin to LOW and updates the internal state to false.
     */
    void off();

    /**
     * @brief Toggles the LED's state.
     *
     * If the LED is currently ON, it turns it OFF, and vice versa.
     */
    void toggle();

    /**
     * @brief Checks if the LED is currently on.
     *
     * @return true if the LED is on, false otherwise.
     */
    bool isOn() const;
};

#endif // _LED_H_
