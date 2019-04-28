#include "NRF24L01.h"

//Se declara los pines CE y CSN
#define CE_PIN 9
#define CSN_PIN 10

//Variable con la direccion de canal a transmitir
byte direccion[5] ={'c','a','n','a','l'};

//Variable de vector de datos a enviar
float calidadAire[1];

//Objeto radio
RF24 radio(CE_PIN, CSN_PIN);

void NRF_Init(){
    //Serial.begin(9600);
    //Inicializamos la antena NRF24L01
    radio.begin();
    //Se abre el canal de escritura
    radio.openWritingPipe(direccion);
}

void EnviarDato(float lectura){
  calidadAire[0] = lectura;
  //Se envian los datos
  bool ok = radio.write( calidadAire, sizeof(calidadAire) );
  
  //Mostramos en el puerto serial si se esta enviando
  if(ok)
  {
    Serial.println("Datos enviados: ");
    Serial.println(calidadAire[0]);
  }
  else
  { 
    Serial.println("No se envio");
  }
  //delay(500);
}
