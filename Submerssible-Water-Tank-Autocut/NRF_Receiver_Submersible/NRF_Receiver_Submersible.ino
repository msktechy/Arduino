#include <SPI.h>
#include <RH_NRF24.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(7,8); // RX | TX
// Singleton instance of the radio driver
RH_NRF24 nrf24(9,10);
int R = 4;
char buf[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
String d;
int l=90,h=30,ml=50,mh=60,cm;
int i = 180, r = 3, g = 5, b = 6, del = 50;
int ON = 0, OFF = 1,C,cd = 500;
float mmDist,cmDist,rad=51.5,vol,ht=120;
void setup() 
{

  pinMode(R,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  digitalWrite(R,OFF);
  digitalWrite(r,LOW);
  digitalWrite(g,LOW);
  digitalWrite(b,LOW);
  C = 'F';
  Serial.begin(9600);
  BT.begin(9600); 
   while (!Serial)  
    ; // wait for serial port to connect. Needed for Leonardo only
  if (!nrf24.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");    

}
void loop()
{
  if (nrf24.available())
  {
    // Should be a message for us now   

    if (nrf24.recv(buf, &len))
    {
    //  Serial.print("got request: ");
     // Serial.print("buf = ");
     // Serial.println(buf);
     // Serial.println((typeof)buf);
      d =  buf;
      mmDist = d.toInt();
      cmDist = mmDist/10;
      cmDist = constrain(cmDist,10,150);
   //   if(cmDist>120)
    //  {
    //  cmDist = 120;
    //  }
      Serial.print("cmDist = ");    
      Serial.println(cmDist); 
     // vol = 0.001*rad*rad*PI*(ht-cmDist);
     // if(vol<=0)
    //  {
    //    vol = 0;
      //}
      BT.print(cmDist);
      BT.print("   ");
     // BT.println(vol); 
      
      if((cmDist>=l))
      {
        analogWrite(r,i);
        analogWrite(b,0);
        analogWrite(g,0);
        C = 'N';
        Serial.println("Submersible ON");
        Serial.println("RED");
        //digitalWrite(R,ON);
      }
      if((cmDist>mh)&&(cmDist<l))
      {
        analogWrite(b,i);
        analogWrite(r,0);
        analogWrite(g,0);
        C = 'N';
        Serial.println("Submersible ON");
        Serial.println("BLUE ON");
        delay(del);
        //digitalWrite(R,ON);
        analogWrite(b,0);
        analogWrite(r,0);
        analogWrite(g,0);
        C = 'N';
        Serial.println("Submersible ON");
        Serial.println("BLUE OFF");
      }
      if((cmDist>=ml)&&(cmDist<=mh))
      {
        Serial.println("BLUE");
        Serial.println("Start Submersible");
        Serial.println("Mid-point Achieved");
        analogWrite(g,0);
        analogWrite(b,i);
        analogWrite(r,0);
      }
      if((cmDist>h)&&(cmDist<ml))
      {
        //digitalWrite(R,ON);
        analogWrite(b,i);
        analogWrite(r,0);
        analogWrite(g,0);
        Serial.println("Submersible ON");
        Serial.println("BLUE ON");
        delay(del);
        //digitalWrite(R,ON);
        analogWrite(b,0);
        analogWrite(r,0);
        analogWrite(g,0);
        Serial.println("Submersible ON");
        Serial.println("BLUE OFF");
      }      
      if(cmDist<=h)
      {
        //digitalWrite(R,OFF);
        analogWrite(r,0);
        analogWrite(b,0);
        analogWrite(g,i);
        C = 'F';
        Serial.println("Submersible OFF");
        Serial.println("GREEN");
      }
      if(C == 'N')
      {
        digitalWrite(R,ON);
        Serial.println("C = 'A' and Submersible is ON");
      }
      if(C == 'F')
      {
        digitalWrite(R,OFF);
        Serial.println("C = 'B' and Submersible is OFF");
      }
    }
    else
    {
          digitalWrite(R,OFF);
        for(int j=0;j<=255;j++)
        {
          analogWrite(r,j);
          analogWrite(g,0);
          analogWrite(b,0);
          delay(del);
        }
        for(int j=255;j>=0;j--)
        {
          analogWrite(r,j);
          analogWrite(g,0);
          analogWrite(b,0);
          delay(del);
        }
      Serial.println("recv failed");
    }
  }
  delay(cd);
}
