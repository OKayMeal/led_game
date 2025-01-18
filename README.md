This project is a simple electronic circuit game in which the player's goal is to remember and repeat the sequence of blinking leds.
In the beginning of each round the game plays out the sequence of leds and sounds and the player has to repeat the sequence by pressing the buttons accordingly.
One mistake = game over!


The circuit consists of following components:
- 1x Arduino Uno board (or clone)
- 1x Piezo Buzzer (passive)
- 6x LED + 6x 330 Ohm resistor
- 4x Button
- 1x 1k Ohm resistor (optional, this is just to make the buzzer a bit less noisy)

Connections (pinout.txt):
OBJECT:     A_GPIO:                                       CONNECTIONS:
led0:       13,         led0(+) -> 330 Ohm -> A_GPIO13,                             led0(-) -> A_GND
led1:       12,         led1(+) -> 330 Ohm -> A_GPIO12,                             led1(-) -> A_GND
led2:       11,         led2(+) -> 330 Ohm -> A_GPIO11,                             led2(-) -> A_GND
led3:       10,         led3(+) -> 330 Ohm -> A_GPIO10,                             led3(-) -> A_GND
btn0:       9,          btn0 -> A_GPIO9,                                            btn0 -> A_GND
btn1:       8,          btn1 -> A_GPIO8,                                            btn1 -> A_GND
btn2:       7,          btn2 -> A_GPIO7,                                            btn2 -> A_GND
btn3:       6,          btn3 -> A_GPIO6,                                            btn3 -> A_GND
failLed:    5,          failLed(+) -> 330 Ohm -> A_GPIO5,                           failLed(-) -> A_GND
successLed: 4,          successLed(+) -> 330 Ohm -> A_GPIO4,                        successLed(-) -> A_GND
buzzer:     3           buzzer(I/O) -> A_GPIO3,   buzzer(VCC) -> 1kOhm -> A_3.3V,   buzzer(GND) -> A_GND

![project](https://github.com/user-attachments/assets/1b316bc9-fad8-4a75-ad07-c05e304d1e27)
