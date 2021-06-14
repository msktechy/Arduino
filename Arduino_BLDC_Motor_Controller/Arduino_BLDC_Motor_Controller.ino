#include <Servo.h>
Servo esc_signal;
int val;
void setup()
{
  Serial.begin(250000);
  esc_signal.attach(9);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);            //ESC initialization delay.

}

void loop()
{
    val= analogRead(A0);
val = map(val,0,1023,72,180);
esc_signal.write(val);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
Serial.println(val);
//delay(15);
}
