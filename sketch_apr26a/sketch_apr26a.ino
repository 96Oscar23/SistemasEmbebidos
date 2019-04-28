#include "estados.h"
#include "inicializar.h"
#include "NRF24L01.h"
#include "mq9.h"

void setup() {
  init_serial();
  NRF_Init();
}

void loop() {
  //suma();
  float lectura;
  lectura = ConcentracionMQ9();
  EnviarDato(lectura);
  delay(500);
}
