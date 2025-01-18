#include <Arduino.h>
#include <game_controller.h>

GameController::GameController(
            Button* buttonsArr[MAX_BUTTONS], Buzzer& buzzerObj,
            LED& greenLedObj, LED& redLedObj,
            const NoteInfo* const* melodiesArr, const int arrSize)
            :
            buzzer(buzzerObj), successLed(greenLedObj), failLed(redLedObj), melody(nullptr) {
                for (size_t i = 0; i < MAX_BUTTONS; i++)
                {
                    this->buttons[i] = buttonsArr[i];
                }

                // Choose a melody
                this->chooseMelody(melodiesArr, arrSize);

                // Create sequence
                this->createSequence();
            }

void GameController::chooseMelody(const NoteInfo* const* melodiesArr, const int arrSize) {
    long randNumber = random(0, arrSize);
    this->melody = melodiesArr[randNumber];

    Serial.print("Melody number ");
    Serial.print(randNumber + 1);
    Serial.println(" chosen!");
}

void GameController::createSequence() {
    // The number of permutations as factorial of MAX_BUTTONS
    int permutations = 1;
    for (int i = 1; i <= MAX_BUTTONS; i++)
    {
        permutations *= i;
    }
    
    // All possible sequences with numbers 0, 1, 2, 3
    int sequences[permutations][MAX_BUTTONS] = {
        // Those are hard coded permutations because generating them dynamically is hell on arduino
        // NEEDS TO BE MANUALLY ADJUSTED IF THE MAX_BUTTONS IS NOT 4
        {0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1},
        {0, 3, 1, 2}, {0, 3, 2, 1}, {1, 0, 2, 3}, {1, 0, 3, 2},
        {1, 2, 0, 3}, {1, 2, 3, 0}, {1, 3, 0, 2}, {1, 3, 2, 0},
        {2, 0, 1, 3}, {2, 0, 3, 1}, {2, 1, 0, 3}, {2, 1, 3, 0},
        {2, 3, 0, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 0, 2, 1},
        {3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0}
    };

    long randNumber = random(0, permutations + 1);
    Serial.println("Creating sequence: ");
    Serial.print("[ ");
    for (int i = 0; i < MAX_SEQUENCE; i++)
    {
        sequence[i] = sequences[randNumber][i];
        Serial.print(sequence[i]);
        Serial.print(", ");
    }
    Serial.println(" ]");
}

void GameController::setNotes() {
    for (int i = 0; i < MAX_SEQUENCE; i++)
    {
        int correctBtnIndex = sequence[i];
        Serial.print("Setting note ");
        Serial.print(melody[i].note);
        Serial.print(" for button ");
        Serial.println(correctBtnIndex);
        

        buttons[correctBtnIndex]->setNote(&melody[i]);
    }
    
}

void GameController::update() {
    if (takeInputs == true) {
        // Player turn!
        Serial.print("Round ");
        Serial.print(round + 1);
        Serial.println(" started!");

        while (playerInputs < round + 1)
        {
            // Scan for player input on the buttons
            for (int i = 0; i < MAX_BUTTONS; i++)
            {
                Button* currentButton = buttons[i];
                if (currentButton->isPressed()) {
                    // playerInputs++;
                    currentButton->handleBtnPress(buzzer);

                    // Check if input is correct
                    int correctBtnIndex = sequence[playerInputs];
                    Serial.print("Correct btn index: ");
                    Serial.println(correctBtnIndex);
                    if (currentButton->getIndex() == correctBtnIndex) {
                        Serial.println("Correct input!");
                        playerInputs++;

                        if (playerInputs == round + 1) {
                            successLed.on();
                        }
                        
                    } else {
                        Serial.println("Incorrect input!");
                        gameOver();
                    }
                }
            }
        }

        Serial.println("Player played the sequence correctly!");
        successLed.on();

        // Increment round
        round++;
        Serial.print("Current score: ");
        Serial.print(round);
        Serial.println(" ");

        if (round == MAX_SEQUENCE) {
            // player won!
            victory();
        }

        takeInputs = false;
        delay(1000);

    } else {
        // Prepare next round
        Serial.print("Preparing round ");
        Serial.println(round + 1);

        if (successLed.isOn()) {
            successLed.off();
        }

        playerInputs = 0; // reset playerInputs

        Serial.println("Showing sequence to player!");
        // Show the sequence to the player
        for (int i = 0; i < round + 1; i++)
        {
            buttons[sequence[i]]->handleBtnPress(buzzer);
            delay(500);
        }

        takeInputs = true;
    }
}

void GameController::gameOver() {
    Serial.println("GAME OVER!");
    if (successLed.isOn()) {
        successLed.off();
    }

    failLed.on();
    Serial.print("SCORE: ");
    Serial.print(round);
    Serial.println(" ");

    while (true) { }
}

void GameController::victory() {
    Serial.println("VICTORY!");
    
    while (true) {
        successLed.toggle();
        delay(1000);
    }
}
