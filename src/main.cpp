#include <Arduino.h>
#include <buzzer.h>
#include <led.h>
#include <button.h>

Buzzer buzzer(3);
LED led0(5);
Button btn0(2, 0, led0);

void setup()
{
	Serial.begin(115200);
	Serial.println("Serial communication established!");

	buzzer.begin();
	led0.begin();
	btn0.begin();
	btn0.setNote(&melody1[0]);
}

void loop()
{
	// buzzer.playMelody(melody1, melody1Length);
	// delay(3000);

	if (btn0.isPressed()) {
		btn0.handleBtnPress(buzzer);
	}
}