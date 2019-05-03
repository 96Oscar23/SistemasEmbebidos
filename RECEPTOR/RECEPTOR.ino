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
  String cadena_Datos = "";
  String Sensor1 = "";
  String Sensor2 = "";
  //Se verifica si el radio esta disponible
  
  cadena_Datos += "Sensor1:";
  if ( radio.available(&pipe_num) )
  {
      Sensor1 = ReciveLectureNRF(pipe_num);
      cadena_Datos += Sensor1;
  }
  else
  {
    cadena_Datos += "-1"; //Si la radio no esta disponible se envia un -1
  }
  //Se verifica si el radio esta disponible
  cadena_Datos += ",";
  cadena_Datos += "Sensor2:";
  if ( radio.available(&pipe_num1) )
  {
      Sensor2 = ReciveLectureNRF(pipe_num1);
      cadena_Datos += Sensor2;
  }
  else
  {
    cadena_Datos += "-1";//Si la radio no esta disponible se envia un -1
  }
  cadena_Datos += "\n";
  Serial.print(cadena_Datos);
  delay(500);
}

String ReciveLectureNRF(int pipe)
{
    radio.read( calidadAire, sizeof(calidadAire) );
    return String(calidadAire[0]);
}
