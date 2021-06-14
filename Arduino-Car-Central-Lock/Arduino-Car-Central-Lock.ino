#include <SoftwareSerial.h>
  
  int door_unlock = 3;
  int door_lock = 5;
  int dicky_unlock = 6;
  int high = 7;
  int low = 8;
  int Rx = 10;
  int Tx = 11;
  int cmd;
  int BTState = 2;
  SoftwareSerial BT(Rx,Tx);
  
void setup() {
  
  BT.begin(115200);
  Serial.begin(115200);
  Serial.println("ASSALAMOALAIKUM! This is Carduino by MSK");
  BT.println("ASSALAMOALAIKUM! This is Carduino by MSK");
  pinMode(door_unlock, OUTPUT);
  pinMode(door_lock, OUTPUT);
  pinMode(dicky_unlock, OUTPUT);
  pinMode(high,OUTPUT);
  pinMode(low,OUTPUT);
  digitalWrite(low,LOW);
  
}

void loop() {
  if(digitalRead(BTState) == LOW)
  { 
    digitalWrite(high,LOW);
    cmd='S';
    Serial.println("Disconnected");
  }
  if(digitalRead(BTState) != LOW)
  { 
    digitalWrite(high,HIGH);
    Serial.println("Connected");
  }
  if (Serial.available()>0)
  {
    cmd = Serial.read();
  }
  
  if (BT.available()>0)
  {
    cmd = BT.read();
  }
  if (cmd == 'F')
  {
    digitalWrite(3,HIGH);
    Serial.println("Door Unlocked");
  }
  else if (cmd == 'B')
  {
    digitalWrite(5,HIGH);
    Serial.println("Door locked");
  }
  else if (cmd == 'R')
  {
    digitalWrite(6,HIGH);
    Serial.println("Dicky Unlocked");
  }
  else if (cmd == 'L')
  {
    digitalWrite(5,HIGH);
    Serial.println("Door locked");
  }
  else if (cmd == 'S')
  {
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("release");
  }
}
