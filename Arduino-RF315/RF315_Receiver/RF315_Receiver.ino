#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
String msg ;
int d,m=20;
void setup()
{
  pinMode(13,OUTPUT);
  //Serial.begin(9600);
  //Serial.println("Device is ready");
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver
}
void loop()
{
  if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    //Serial.print("Received: ");
      for (int i = 0; i < messageLength; i++)
      {
        //Serial.write(message[i]);
        message[i];
      }
      msg = message;
      d =  msg.toInt();
    if(d>m)
      {
        //Serial.println("ON");
        digitalWrite(13,HIGH);
      }
      if(d<=m)
      {
        //Serial.println("OFF");
        digitalWrite(13,LOW);
      }
      //Serial.println(msg);
    //Serial.println();
    }
}
