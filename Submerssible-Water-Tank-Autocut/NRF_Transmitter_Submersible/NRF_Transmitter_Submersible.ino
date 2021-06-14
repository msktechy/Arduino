#include <SPI.h>
#include <RH_NRF24.h>
#include <SoftwareSerial.h>
// Singleton instance of the radio driver
RH_NRF24 nrf24(9,10);

const int US100_TX = 7;
const int US100_RX = 8;

SoftwareSerial US100(US100_RX, US100_TX);
unsigned int MSByteDist = 0;
unsigned int LSByteDist = 0;

float mmDist = 0;
int l=900,h=300,ml=500,mh=600, dc = 100;
int i = 180,r = 3, g = 5, b = 6, del = 50;

char data[4];

void setup() 
{
  
  Serial.begin(9600);
  while (!Serial) 
  nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPowerm18dBm);    
  if (!nrf24.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");    
    
     US100.begin(9600);
     
     pinMode(r,OUTPUT);
     pinMode(g,OUTPUT);
     pinMode(b,OUTPUT);

     digitalWrite(r,LOW);
     digitalWrite(g,LOW);
     digitalWrite(b,LOW);
}


void loop()
{
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
          mmDist = constrain(mmDist,100,3000);
      Serial.print("Distance = "); 
     Serial.print(mmDist);
     Serial.println();
 /*    if((mmDist>=med))
  { 
    Serial.println("RED");
    analogWrite(r,255);
    analogWrite(b,0);
    analogWrite(g,0);
  }*/
  if((mmDist>h)&&(mmDist<ml))
  {
      analogWrite(b,i);
      analogWrite(r,0);
      analogWrite(g,0);
      delay(del);
      analogWrite(b,0);
      analogWrite(r,0);
      analogWrite(g,0);
      Serial.println("Submersible ON");
  }
  if((mmDist>mh)&&(mmDist<l))
  {
      analogWrite(b,i);
      analogWrite(r,0);
      analogWrite(g,0);
      delay(del);
      analogWrite(b,0);
      analogWrite(r,0);
      analogWrite(g,0);
      Serial.println("Submersible ON");
  }
    if((mmDist>=ml)&&(mmDist<=mh))
  {
      Serial.println("BLUE");
      Serial.println("Start Submersible");
      Serial.println("Mid-point Achieved");
      analogWrite(g,0);
      analogWrite(b,i);
      analogWrite(r,0);
  }
  if(mmDist<=h)
  {
      Serial.println("GREEN");
      Serial.println("Stop Submersible");
      analogWrite(g,i);
      analogWrite(b,0);
      analogWrite(r,0);
  }
       if(mmDist>=l)
     {
     Serial.println("RED");
     analogWrite(r,i);
     analogWrite(b,0);
     analogWrite(g,0);
     Serial.print("Distance > "); 
     Serial.print("800");
     Serial.println();
     Serial.print("mmDist = ");
     Serial.println(mmDist);
     Serial.println("Start Submersible");
     Serial.println("Sending to nrf24_server");
  // Send a message to nrf24_server
  //mmDist = 2000;
  // dtostrf(mmDist, 4 , 0, data);
 // nrf24.send(data, sizeof(data));
 // nrf24.waitPacketSent();
     }
     Serial.println("Sending to nrf24_server");
  // Send a message to nrf24_server
   dtostrf(mmDist, 4 , 0, data);
  nrf24.send(data, sizeof(data)); 
  nrf24.waitPacketSent();
     }
}
}
