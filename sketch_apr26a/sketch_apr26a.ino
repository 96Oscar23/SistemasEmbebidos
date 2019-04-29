#include "estados.h"
#include "inicializar.h"
#include "NRF24L01.h"
#include "mq9.h"

void setup() {
  init_serial();
  NRF_Init();//Se inicializa la antena de radio
}

enum estados estadoGeneral = Config;
enum acciones accionesGeneral = Nill;

boolean comando = false;

void loop() {
  float lectura; //Guarda el dato del sensor MQ9
  lectura = ConcentracionMQ9(); //Lee el dato del sensor MQ9
  EnviarDato(lectura);//Envia el dato del sensor MQ9 por la antena de radio NRF24
  //delay(500);//delay
  
  switch (estadoGeneral) {
    case Config:
      Serial.println("Estado configurado");
      float lectura; //Guarda el dato del sensor MQ9
      lectura = ConcentracionMQ9(); //Lee el dato del sensor MQ9
      EnviarDato(lectura);//Envia el dato del sensor MQ9 por la antena de radio NRF24
      delay(500);//delay
      break;
    case Espera:
      break;
    case No_Conf:
      break;
  }

   boolean comman = serialEven( comando); 

   if (comman){
    
   }
}
