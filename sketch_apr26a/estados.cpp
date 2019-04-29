#include "estados.h"

void estado_config() {
  Serial.println("Configurado");
}


void estado_espera() {
  Serial.println("ESperando");

}

void cleanRxBuffer (){ 
  while (Serial.available()){
    Serial.read();
  }
  
}

char rxDataCMD[8];
char rxDataPAR[64];
byte reqType = 0; // 0 = AT o AT+XXXX  1 = AT+XXX=PAR

int cmdSize = 0;
int dataSize = 0;

boolean serialEven(boolean comando) {
  char inChar;
  while (Serial.available() ) {
    inChar = (char) Serial.read();
    if (inChar == '\r') {
      if (reqType == 1) {
        rxDataPAR[dataSize] = '\0';
      } else {
        rxDataCMD[cmdSize] = '\0';
      }
      comando = true;
      cleanRxBuffer();
      return comando;
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
  
  return comando;
}

void executeCMD(){
  switch (estado)
}
