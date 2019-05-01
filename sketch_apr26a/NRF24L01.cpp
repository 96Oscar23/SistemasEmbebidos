#include "NRF24L01.h"

//Se declara los pines CE y CSN
#define CE_PIN 9
#define CSN_PIN 10

#define WHICH_NODE 2
//Variable con la direccion de canal a transmitir
const uint64_t wAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL, 0xB3B4B5B6A3LL, 0xB3B4B5B60FLL, 0xB3B4B5B605LL};
const uint64_t direccion = wAddress[ WHICH_NODE - 1 ];   // Pulls the address from the above array for this node's pipe

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
