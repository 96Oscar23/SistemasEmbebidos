#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

//Se declara los pines CE y CSN
#define CE_PIN 9
#define CSN_PIN 10

//Variable con la direccion de canal a transmitir
const uint64_t direccion[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL, 0xB3B4B5B6A3LL, 0xB3B4B5B60FLL, 0xB3B4B5B605LL };

//Objeto radio
RF24 radio(CE_PIN, CSN_PIN);

//vector de datos a enviar
float calidadAire[1];

void setup()
{
  Serial.begin(9600);
  //Inicializamos la antena NRF24L01
  radio.begin();
  //Se abre el canal de lectura
  radio.openReadingPipe(0,direccion[0]);
  radio.openReadingPipe(1,direccion[1]);
  //Se comienza a escuchar por el canal
  radio.startListening();
}

void loop()
{
  byte pipe_num = 0;
  byte pipe_num1 = 1;
  //Se verifica si el radio esta disponible
  if ( radio.available(&pipe_num) )
  {
      ReciveLectureNRF(pipe_num);
  }
  else
  {
    Serial.print("\nRadio ");
    Serial.print(pipe_num);
    Serial.print(" no available\n");
  }
  //Se verifica si el radio esta disponible
  if ( radio.available(&pipe_num1) )
  {
      ReciveLectureNRF(pipe_num1); 
  }
  else
  {
    Serial.print("\nRadio ");
    Serial.print(pipe_num1);
    Serial.print(" no available\n");
  }
  delay(500);
}

void ReciveLectureNRF(int pipe)
{
    radio.read( calidadAire, sizeof(calidadAire) );
    if(pipe == 0){
      Serial.print("Concentracion1: ");
    }
    else{
      Serial.print("Concentracion2: ");
    }
    Serial.print(calidadAire[0]);
    Serial.println();
}
