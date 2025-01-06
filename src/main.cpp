#include <Arduino.h>
#include <game_controller.h>

Buzzer buzzer(3);
LED led0(13);
LED led1(12);
LED led2(11);
LED led3(10);
LED failLed(5);
LED successLed(4);
Button btn0(9, 0, led0);
Button btn1(8, 1, led1);
Button btn2(7, 2, led2);
Button btn3(6, 3, led3);
bool initialized = false;
Button* btns[MAX_BTNS] = { &btn0, &btn1, &btn2, &btn3 };
GameController* gameController = nullptr;

void setup()
{
	// Initialize serial com
	Serial.begin(115200);
	Serial.println("Serial communication established!");

	// Initialize Buzzer, LEDs and Buttons
	buzzer.begin();
	led0.begin();
	led1.begin();
	led2.begin();
	led3.begin();
	failLed.begin();
	successLed.begin();

	for (int i = 0; i < MAX_BTNS; i++)
	{
		btns[i]->begin();
	}

	gameController = new GameController(btns, buzzer, successLed, failLed, melodies, MELODIES_COUNT);
}

void loop()
{
	if (gameController) {
		gameController->update();
	}
}