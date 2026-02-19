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
const int LED_LEFT   = 10;   // Left LED
const int LED_RIGHT  = 11;   // Right LED
const int LED_CENTER = 3;    // Center LED
const int SPEAKER    = 9;    // Piezo speaker

// Alien sound ranges
const int ALIEN_LOW  = 300;   // Deep alien tone
const int ALIEN_HIGH = 1800;  // Sharp alien chirp

void setup() {
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_CENTER, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
}

// Runs forever — alien transmission loop
void loop() {

  // 👽 Phase 1: Alien heartbeat pulse
  for (int i = 0; i < 4; i++) {
    digitalWrite(LED_CENTER, HIGH);
    tone(SPEAKER, 450);
    delay(120);

    digitalWrite(LED_CENTER, LOW);
    noTone(SPEAKER);
    delay(80);
  }

  // 👾 Phase 2: Random alien chatter
  for (int i = 0; i < 12; i++) {
    int alienTone = random(ALIEN_LOW, ALIEN_HIGH);

    digitalWrite(LED_LEFT, random(0, 2));
    digitalWrite(LED_RIGHT, random(0, 2));
    digitalWrite(LED_CENTER, random(0, 2));

    tone(SPEAKER, alienTone);
    delay(random(30, 90));
  }

  noTone(SPEAKER);

  // 🛸 Phase 3: UFO power-up sweep
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_CENTER, HIGH);
  digitalWrite(LED_RIGHT, HIGH);

  for (int freq = 600; freq <= 1600; freq += 25) {
    tone(SPEAKER, freq);
    delay(12);
  }

  // ✨ Transmission pause
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_CENTER, LOW);
  digitalWrite(LED_RIGHT, LOW);
  noTone(SPEAKER);
  delay(300);
}
