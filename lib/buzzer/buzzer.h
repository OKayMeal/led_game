#ifndef _BUZZER_H_
#define _BUZZER_H_

#include <Arduino.h>
#include <melodies.h>

/**
 * @class Buzzer
 * @brief A class to control a piezo buzzer sound output.
 *
 */
class Buzzer {
private:
    uint8_t pin;         /** The Arduino pin number where the Buzzer is connected */

public:
    /**
     * @brief Constructs a new Buzzer object with the specified pin number.
     *
     * Initializes the Buzzer's pin number and sets pin mode to OUTPUT.
     *
     * @param pinNumber The Arduino pin number to which the Buzzer is connected.
     */
    Buzzer(uint8_t pinNumber);

    /**
     * @brief Initializes the Buzzer pin as an OUTPUT.
     *
     * Sets the Arduino pin mode to OUTPUT.
     */
    void begin();

    /**
     * @brief Plays a given melody.
     *
     * @param melody NoteInfo array containing notes, duration and delay after the note info.
     * 
     * @param melodyLength Length of the melody to play.
     */
    void playMelody(const NoteInfo melody[], int melodyLength);

    /**
     * @brief Plays a certain note from the melody.
     *
     * @param melody NoteInfo array containing notes, duration and delay after the note info.
     * 
     * @param noteIndex Index of the note in a melody array.
     */
    void playNote(const NoteInfo melody[], int noteIndex);

    /**
     * @brief Stops the buzzer from making any sound.
     * It is essentially a wrapper that utilizes noTone() and after brings
     * the pin state to HIGH as opposed to LOW which is in noTone() function.
     * The reason for that is the Arduino Piezo module (with 3 pins VCC/IO/GND)
     * is using a PNP transistor which means HIGH will turn it off.
     */
    void stop();
};

#endif