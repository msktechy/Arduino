#include<Ultrasonic.h>
Ultrasonic ultrasonic(30,31); //in brackets 1st is TRIGGER PIN and 2nd is ECHO PIN
  int enA = 3;       // Pin  ENA of L298
  int motorA1  = 5;  // Pin  IN1 of L298
  int motorA2  = 6;  // Pin  IN2 of L298
  int enB = 11;      // Pin  ENB of L298
  int motorB1  = 9;  // Pin IN3 of L298
  int motorB2  = 10;  // Pin IN4 of L298
  int turn = 255;    // Speed of wheel turning
//Leds connected to Arduino UNO Pin 12
  int headlights  = 53;
  int taillights = 52;
  int indicatorbuzzer=13;
//Buzzer / Speaker to Arduino UNO Pin 6
  int buzzer = 8 ;
  int parking = 7; //ultrasonic buzzer
  int leftindicator = 22;
  int rightindicator = 51;
 
//Bluetooth (HC-05) State pin on pin 2 of Arduino
  int BTState = 2; //it will tell u that is the device is connected or not
//Useful Variables
  int state; //this is for the characters A,B,C etc...
  int vSpeed=255;    // Default speed, from 0 to 255 for analogwrite
void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(headlights, OUTPUT); 
    pinMode(taillights, OUTPUT);
    pinMode(rightindicator, OUTPUT);
    pinMode(leftindicator, OUTPUT);
    pinMode(indicatorbuzzer,OUTPUT);
    pinMode(BTState, INPUT);  //this pin is input bcoz its telling the bluetooth is connected or not
    
//GIVE THE ANALOG WRITE to both ENABLE->
    digitalWrite(enA, HIGH);
    digitalWrite(enB, HIGH);
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600); // here 9600 is baudrate
    
}
 
void loop() { 
  //Stop car when connectiont or bluetooth disconnected
     if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   //here the Serial.read() are the commands given by the mobile or any device.
    }
  
  //Change speed if state is equal from 0 to 9. Values must be from 0 to 255 (PWM)
     if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=40;}
    else if (state == '2'){
      vSpeed=60;}
    else if (state == '3'){
      vSpeed=80;}
    else if (state == '4'){
      vSpeed=100;}
    else if (state == '5'){
      vSpeed=125;}
    else if (state == '6'){
      vSpeed=150;}
    else if (state == '7'){
      vSpeed=175;}
    else if (state == '8'){
      vSpeed=200;}
    else if (state == '9'){
      vSpeed=255;}

  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
      analogWrite(motorA1, 0); analogWrite(motorB2, 0);
        analogWrite(motorB1, vSpeed);  analogWrite(motorA2, 0);
        analogWrite(leftindicator,0);
       analogWrite(rightindicator,0);
         }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
      analogWrite(motorA1, turn); analogWrite(motorA2, 0);  
        analogWrite(motorB1, vSpeed);    analogWrite(motorB2, 0); 
       analogWrite(leftindicator,255);
       analogWrite(rightindicator,0);
 }  
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
        analogWrite(motorA1, 0); analogWrite(motorA2, turn); 
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2,0 ); 
     analogWrite(rightindicator,255);
     analogWrite(leftindicator,0);
    
      }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
      analogWrite(leftindicator,0);
       analogWrite(rightindicator,0);
      
      if (ultrasonic.Ranging(CM)<30&&ultrasonic.Ranging(CM)>0)
  {  
        analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 0); 
        
    tone(parking, 1000);
   analogWrite(taillights,255);
    
    
}
else if (ultrasonic.Ranging(CM)<40&&ultrasonic.Ranging(CM)>30)
{   analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);
  tone(parking, 1000);
  analogWrite(taillights,0);
    delay(30);
    noTone(parking);
    analogWrite(taillights,0);
    delay(30);
    
}
else if (ultrasonic.Ranging(CM)<51&&ultrasonic.Ranging(CM)>40)
{  analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);   analogWrite(motorB2,vSpeed);
  tone(parking, 1000);
  analogWrite(taillights,0);
    delay(70);
    noTone(parking);
    analogWrite(taillights,0);
    delay(70);
}
else 
  {   analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);
    noTone(parking);
}
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'H', car will go backward right
    else if (state == 'J') {  
       analogWrite(leftindicator,0);
      analogWrite(rightindicator,255); 
   if (ultrasonic.Ranging(CM)<30&&ultrasonic.Ranging(CM)>0)
  {   analogWrite(motorA1, 0);   analogWrite(motorA2, turn); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 0); 
    tone(parking, 1000);
    analogWrite(taillights,255);
    
}
else if (ultrasonic.Ranging(CM)<40&&ultrasonic.Ranging(CM)>30)
{  analogWrite(motorA1, 0);   analogWrite(motorA2, turn); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed); 
  tone(parking, 1000);
  analogWrite(taillights,0);
    delay(30);
    noTone(parking);
    analogWrite(taillights,0);
    delay(30);
}
else if (ultrasonic.Ranging(CM)<51&&ultrasonic.Ranging(CM)>40)
{  analogWrite(motorA1, 0);   analogWrite(motorA2, turn); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed); 
  tone(parking, 1000);
  analogWrite(taillights,0);
    delay(70);
    noTone(parking);
    analogWrite(taillights,0);
    delay(70);
}
else 
  {   analogWrite(motorA1, 0);   analogWrite(motorA2, turn); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed); 
    noTone(parking);
}}
  /**********************Backward Left************************/
  //If state is equal with letter 'J', car will go backward left
    else if (state == 'H') { 
        analogWrite(leftindicator,255);
        analogWrite(rightindicator,0);
  if (ultrasonic.Ranging(CM)<30&&ultrasonic.Ranging(CM)>0)
  {  analogWrite(motorA1, turn);   analogWrite(motorA2,0); 
        analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0); 
    tone(parking, 1000);
    analogWrite(taillights,255);
    
}
else if (ultrasonic.Ranging(CM)<40&&ultrasonic.Ranging(CM)>30)
{ analogWrite(motorA1, turn);   analogWrite(motorA2,0); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
  tone(parking, 1000);
  analogWrite(taillights,0);
    delay(30);
    analogWrite(taillights,0);
    noTone(parking);
    delay(30);
}
else if (ultrasonic.Ranging(CM)<51&&ultrasonic.Ranging(CM)>40)
{ analogWrite(motorA1, turn);   analogWrite(motorA2,0); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
  tone(parking, 1000);
  analogWrite(taillights,0);
    delay(70);
    noTone(parking);
    analogWrite(taillights,0);
    delay(70);
}
else 
  {  analogWrite(motorA1, turn);   analogWrite(motorA2,0); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
    noTone(parking);
}
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, turn); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
        analogWrite(rightindicator,255);
 }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
      analogWrite(motorA1, turn);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 0);     
      analogWrite(leftindicator,255);
 }
  /************************Lights*****************************/
  //If state is equal with letter 'W', turn leds on or of off
    else if (state == 'W') {
      analogWrite(headlights,255);
    }
    else if(state=='w') //headlights off
      { analogWrite(headlights,0); }
    else if (state == 'U') {
      analogWrite(taillights,255); //taillights on
    }
    else if(state=='u')  //taillights off
      { analogWrite(taillights,0); }  

      //now for parking light ->
      else if (state == 'X') { //parking light on with delays
   analogWrite(headlights,255);
   analogWrite(taillights,255);  
   analogWrite(leftindicator,255);
   analogWrite(rightindicator,255);
   analogWrite(indicatorbuzzer,255);
   analogWrite(buzzer,0);
   delay(500);
   analogWrite(headlights,0); 
   analogWrite(taillights,0); 
   analogWrite(indicatorbuzzer,0);
   analogWrite(leftindicator,0);
   analogWrite(rightindicator,0);
   analogWrite(buzzer,0);
   delay(500);} // from here the loop will go on top.
   
    else if(state=='x') //parking lights of
      { analogWrite(headlights,0); 
      analogWrite(taillights,0);
     analogWrite(leftindicator,0);
   analogWrite(rightindicator,0);
   analogWrite(indicatorbuzzer,0);
    }
   
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
    else if (state == 'V'){    
        tone(buzzer, 1500); //Speaker on
    }
      else if (state=='v'){
       noTone(buzzer);    //Speaker off 
      }
     else if (state=='Q') //this is for left indicator buzzer
     { tone(indicatorbuzzer, 1000);
      analogWrite(leftindicator,255);
       delay(600);
     analogWrite(leftindicator,0);
       noTone(indicatorbuzzer);
       delay(400); // from here the loop will go on top and repeats
     }
     else if(state=='q') // left indicator off
     {
      analogWrite(leftindicator,0);
      noTone(indicatorbuzzer);
     }
      else if (state=='E') //right indicator blinking
     {
      analogWrite(rightindicator,255);
       tone(indicatorbuzzer, 1000);
       delay(600);
       analogWrite(rightindicator,0);
       noTone(indicatorbuzzer);
       delay(400);
     }
     else if(state=='e') // right indicator off
     {
      analogWrite(rightindicator,0);
      noTone(indicatorbuzzer);
     }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car ,it will stop the ultrasonic buzzer with disabling indicators.
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
        noTone (parking);
        analogWrite(leftindicator,0);
        analogWrite(rightindicator,0);
        analogWrite(indicatorbuzzer,0);
        analogWrite(taillights,0);
    }    
}
