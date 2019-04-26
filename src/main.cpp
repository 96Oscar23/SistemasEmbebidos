#include <Arduino.h>
#include "estados.h"


void setup() {
  Serial.begin (9600);
}

void loop() {
  Serial.println("Hola mundo desde platformio 1");
  delay(500);
}