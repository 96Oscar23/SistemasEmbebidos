#include "estados.h"
#include "inicializar.h"
#include "NRF24L01.h"

void setup() {
  init_serial();
  NRF_Init();
}

void loop() {
  //suma();
  float lectura;
  lectura = 12.4;
  EnviarDato(lectura);
  Serial.println("Cambio a loop(()");
}
