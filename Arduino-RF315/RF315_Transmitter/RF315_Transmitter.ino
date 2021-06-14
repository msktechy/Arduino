#include <VirtualWire.h>
#include <SoftwareSerial.h>;


const int US100_TX = 5;
const int US100_RX = 6;
 
// Instancia nuevo canal serie
SoftwareSerial US100(US100_RX, US100_TX);

unsigned int MSByteDist = 0;
unsigned int LSByteDist = 0;


    float mmDist = 0, cmDist;
    char t1[10];
    String sval = "";
 
void setup() {

  //Serial.begin(9600);
  vw_setup(2000); // Bits per sec
  US100.begin(9600);
  
}
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}
void loop() {
 
US100.flush(); // limpia el buffer del puerto serie
    US100.write(0x55); // orden de medición de distancia
 
    delay(500);
 
    if(US100.available() >= 2) // comprueba la recepción de 2 bytes
    {
        MSByteDist = US100.read(); // lectura de ambos bytes
        LSByteDist  = US100.read();
        mmDist  = MSByteDist * 256 + LSByteDist; // distancia
        if((mmDist > 1) && (mmDist < 10000)) // comprobación de la distancia dentro de rango
        {
            cmDist =  mmDist/10; // Reading temperature as Celsius (the default)
         dtostrf(cmDist, 3 , 0, t1);
     //Serial.print("Distance = ");      
   for(int i=0;i<sizeof(t1);i++)
  {
    //Serial.print(t1[i]);
  }
  //Serial.println();
  //convert chararray to string
  for(int i=0;i<sizeof(t1);i++)
  {
    sval+=t1[i];
  }
        }
    }
  
    send(t1);
  //delay(1000);
  
}
