#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <led.h>
#include <melodies.h>
#include <Arduino.h>


/**
 * @class Button
 * @brief A class to handle button presses with debounce functionality.
 *
 * The Button class encapsulates the pin number and implements methods to detect
 * button presses, accounting for debounce.
 */
class Button {
private:
    uint8_t pin;               /** The Arduino pin number where the button is connected */
    int index;                 /** Button's physical index as placed on the gameboard */
    bool lastState;            /** The last read state of the button */
    unsigned long lastDebounceTime; /** The last time the button state changed */
    const unsigned long debounceDelay = 50; /** Debounce delay in milliseconds */
    LED* led;                        /** LED which this button controls */
    const NoteInfo* note;             /** Current note that this button can play */

public:
    /**
     * @brief Constructs a new Button object with the specified pin number.
     *
     * Initializes the button's pin number and prepares it for input with a pull-up resistor.
     *
     * @param pinNumber The Arduino pin number to which the button is connected.
     * 
     * @param buttonIndex The physical index as placed on the gameboard
     * 
     * @param ledObject The LED object this button should control.
     */
    Button(uint8_t pinNumber, int index, LED& ledObject);

    /**
     * @brief Initializes the button pin as an INPUT_PULLUP.
     *
     * Sets the Arduino pin mode to INPUT_PULLUP to use the internal pull-up resistor.
     */
    void begin();

    /**
     * @brief Checks if the button is pressed, accounting for debounce.
     *
     * Detects a valid button press (transition from HIGH to LOW) after ensuring
     * that the state is stable for the debounce delay period.
     *
     * @return true if the button is pressed, false otherwise.
     */
    bool isPressed();

    /**
     * @brief Sets the Button's note.
     *
     * @param note Note to set.
     */
    void setNote(const NoteInfo* note);
};

#endif // _BUTTON_H_
