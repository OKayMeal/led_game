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
    long randNumber = random(0, arrSize + 1);
    this->melody = melodiesArr[randNumber];

    Serial.print("Melody number ");
    Serial.print(randNumber + 1);
    Serial.println(" chosen!");
}

void GameController::createSequence() {
    Serial.println("Creating sequence: ");
    Serial.print("[ ");

    for (int i = 0; i < MAX_SEQUENCE; i++)
    {
        long randNumber = random(0, MAX_BUTTONS + 1);
        sequence[i] = randNumber;
        Serial.print(randNumber);
        Serial.print(", ");
    }

    Serial.println(" ]");
}

void GameController::setNotes() {
    int correctBtnIndex = sequence[round];
    const NoteInfo correctNote = melody[round];

    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        if (i == correctBtnIndex) {
            // Set the correct note from melody to a correct btn in a sequence
            buttons[i]->setNote(&correctNote);
        } else {
            // Roll a random note for other buttons
            int randNumber = -1;
            while (randNumber == -1 || randNumber == round)
            {
                randNumber = random(melodyLength + 1);
            }

            buttons[i]->setNote(&melody[randNumber]);
        }
    }
    Serial.println("Notes set for all the buttons!");
}

void GameController::update() {
    if (takeInputs == true) {
        // Player turn!
        Serial.print("Round ");
        Serial.print(round);
        Serial.println(" started!");

        while (playerInputs < round + 1)
        {
            // Scan for player input on the buttons
            for (int i = 0; i < MAX_BUTTONS; i++)
            {
                Button* currentButton = buttons[i];
                if (currentButton->isPressed()) {
                    playerInputs++;
                    currentButton->handleBtnPress(buzzer);

                    // Check if input is correct
                    int correctBtnIndex = sequence[playerInputs];
                    if (currentButton->getIndex() == correctBtnIndex) {
                        Serial.println("Correct input!");
                        successLed.on();
                    } else {
                        Serial.println("Incorrect input!");
                        gameOver();
                    }
                }
            }
        }
        Serial.println("Player played the sequence correctly!");
        successLed.on();
        Serial.print("Current score: ");
        Serial.print(round);
        Serial.println(" ");

        // Increment round
        round++;

        takeInputs = false;
    } else {
        // Prepare next round
        Serial.print("Preparing round ");
        Serial.println(round);

        if (successLed.isOn()) {
            successLed.off();
        }

        playerInputs = 0; // reset playerInputs
        
        // Set notes for all the buttons
        setNotes();

        // Show the sequence to the player
        for (int i = 0; i < round; i++)
        {
            buttons[sequence[i]]->handleBtnPress(buzzer);
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
    Serial.print(round - 1);
    Serial.println(" ");

    // Buzzer plays the Game Over melody TODO...
}
