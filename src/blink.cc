#include "Arduino.h"

constexpr int led{13};

void setup() { pinMode(led, OUTPUT); }

void loop() {
    digitalWrite(led, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    delay(1000);
}