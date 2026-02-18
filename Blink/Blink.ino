/*
  Blink
By: Cole Rowe
Date: 2.16.26
  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// ----- Pin assignments -----
const int LED_LEFT = 10;     // Left LED
const int LED_RIGHT = 11;    // Right LED
const int SPEAKER = 9;       // Piezo speaker

// ----- Siren settings (slower + deeper) -----
const int LOW_FREQ = 500;    // Deeper low pitch
const int HIGH_FREQ = 1000;  // Higher peak pitch
const int STEP_DELAY = 8;    // Slower siren sweep
const int FREQ_STEP = 10;    // Smooth pitch change

// Runs once when the Arduino starts
void setup() {
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
}

// Runs forever
void loop() {

  // 🔵 Left light ON, right OFF
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_RIGHT, LOW);

  // Siren pitch goes UP (WEE)
  for (int freq = LOW_FREQ; freq <= HIGH_FREQ; freq += FREQ_STEP) {
    tone(SPEAKER, freq);
    delay(STEP_DELAY);
  }

  delay(300);  // Pause for realism

  // 🔴 Right light ON, left OFF
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, HIGH);

  // Siren pitch goes DOWN (WOO)
  for (int freq = HIGH_FREQ; freq >= LOW_FREQ; freq -= FREQ_STEP) {
    tone(SPEAKER, freq);
    delay(STEP_DELAY);
  }

  delay(300);  // Pause before repeating
}
