#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#define MAX_BTNS 4

#include <Arduino.h>
#include <button.h>

/**
 * @class GameController
 * @brief Main controller responsible for controlling the gameplay.
 */
class GameController {
private:
    static constexpr int MAX_BUTTONS = MAX_BTNS;       /** Max number of buttons in the game */
    static constexpr int MAX_SEQUENCE = 10;            /** Max sequence length for the game */
    Buzzer& buzzer;                                    /** Buzzer reference */
    Button* buttons[MAX_BUTTONS];                      /** Array of buttons */
    LED& successLed;                                   /** Green LED which lights up when player succeeds */
    LED& failLed;                                      /** Red LED which lights up when player fails */
    const NoteInfo* melody;                            /** Pointer to a melody that is a goal of the game */
    int sequence[MAX_SEQUENCE];                        /** Array holding the sequence of buttons e.g. {btn0, btn2, btn3, ...} */
    int round = 0;                                     /** Round number */
    int playerInputs = 0;                              /** Number of player inputs taken during the round */
    bool takeInputs = false;                           /** Whether game takes in player inputs */

    /**
     * @brief Chooses a random melody for the game from the array of melodies and stores it in this->melody.
     * 
     * @param melodiesArr The melodies array to choose from.
     * 
     * @param arrSize The length of the array.
     */
    void chooseMelody(const NoteInfo* const* melodiesArr, const int arrSize);

    /**
     * @brief Generates a sequence (objective) for the game.
     */
    void createSequence();

    /**
     * @brief Assigns notes for all the buttons.
     */
    void setNotes();
public:
    /**
     * @brief Constructor for the GameController class.
     * 
     * @param buttonsArr The array of game buttons. Default 4, Its size can be altered in game_controller.h
     * 
     * @param buzzerObj The Buzzer object to play notes with.
     * 
     * @param greenLedObj Green LED that is supposed to light up on player's success.
     * 
     * @param redLedObj Red LED that is supposed to light up on player's failure.
     * 
     * @param melodiesArr The melodies array to choose from.
     * 
     * @param arrSize The length of the array.
     */
    GameController(
        Button* buttonsArr[MAX_BUTTONS], Buzzer& buzzerObj,
        LED& greenLedObj, LED& redLedObj,
        const NoteInfo* const* melodiesArr, const int arrSize
    );

    /**
     * @brief Updates the game state.
     * 
     * This method should be called in the main loop to handle game input and the gameplay.
     */
    void update();

    /**
     * @brief Game Over! Finishes the game dramatically.
     */
    void gameOver();
};

#endif // GAME_CONTROLLER_H
