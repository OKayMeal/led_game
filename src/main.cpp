#include <Arduino.h>
#include <buzzer.h>

Buzzer buzzer(3);

void setup()
{
	Serial.begin(115200);
	Serial.println("Serial communication established!");

	buzzer.begin();
}

void loop()
{
	buzzer.playMelody(melody1, melody1Length);
	delay(3000);
}