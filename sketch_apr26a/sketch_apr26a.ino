#include "estados.h"
#include "inicializar.h"
void setup() {
  init_serial();
}

void loop() {
  suma();
  Serial.println("Cambio a loop(()");
}
