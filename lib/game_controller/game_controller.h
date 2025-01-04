#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <Arduino.h>
#include <button.h>

/**
 * @class GameController
 * @brief Main controller responsible for controlling the gameplay.
 */
class GameController {
private:
    static const int MAX_BUTTONS = 4;       /** Max number of buttons in the game */
    Button buttons[MAX_BUTTONS];            /** Array of buttons */
public:
    /**
     * @brief Constructor for the GameController class.
     * 
     * @param buttonsArr The array of game buttons.
     */
    GameController(Button buttonsArr[MAX_BUTTONS]);

    /**
     * @brief Initializes the game controller. Sets up the game.
     */
    void begin();

    /**
     * @brief Updates the game controller state.
     * 
     * This method should be called in the main loop to handle game input and the gameplay.
     */
    void update();
};

#endif // GAME_CONTROLLER_H
