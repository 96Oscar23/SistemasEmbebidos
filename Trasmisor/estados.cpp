#include "estados.h"

//variables externas
extern enum estados estadoGeneral;
extern boolean comando;

// variables globales
char rxDataCMD[8];
char rxDataPAR[64];
byte reqType = 0; // 0 = AT o AT+XXXX  1 = AT+XXX=PAR

int cmdSize = 0;
int dataSize = 0;

//Funciones
void estado_config() {
  Serial.println("Configurado");
}


void estado_espera() {
  Serial.println("ESperando");

}

void cleanRxBuffer () {
  while (Serial.available()) {
    Serial.read();
  }

}
void bufferInitState() {
  comando = false;
  cmdSize = 0;
  dataSize = 0;
  reqType = 0;
  cleanRxBuffer();
}

boolean serialEven() {
  char inChar;
  while (Serial.available() ) {
    inChar = (char) Serial.read();
    if (inChar == '\n') {
      if (reqType == 1) {
        rxDataPAR[dataSize] = '\0';
      } else {
        rxDataCMD[cmdSize] = '\0';
      }
      comando = true;
      cleanRxBuffer();
    } else if (inChar == '=') {
      rxDataCMD[cmdSize] = '\0';
      reqType = 1;
      break;
    } else {
      if ( reqType == 1) {
        rxDataPAR[dataSize] = inChar;
        dataSize++;
      } else {
        rxDataCMD[cmdSize] = inChar;
        cmdSize++;
      }

    }
  }
}


void executeCMD() {
  switch (estadoGeneral) {
    case Config:
      //Serial.println("configurado");
      if (strcmp(rxDataCMD, "AT") == 0) {
        Serial.println(F("OK"));
        estadoGeneral = Espera;
      }
      break;
    case Espera:
      if (strcmp(rxDataCMD, "AT+CONF") == 0) {
        Serial.println(F("Estado Configurado"));
        estadoGeneral = Config;
      }
      break;
    case No_Conf:
      break;
  }
  bufferInitState();
}
