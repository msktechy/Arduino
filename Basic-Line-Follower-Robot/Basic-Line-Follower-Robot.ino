int irl=A0,irml=A1,irm=A2,irmr=A3,irr=A4,ena=3,in1=5,in2=6,in3=9,in4=10,enb=11,s=130,d=35;

void setup() {
    pinMode(irl,INPUT);
    pinMode(irml,INPUT);
    pinMode(irm,INPUT);
    pinMode(irmr,INPUT);
    pinMode(irr,INPUT);
    pinMode(ena,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    pinMode(enb,OUTPUT);
    digitalWrite(ena,HIGH);
    digitalWrite(enb,HIGH);
}
void loop() {
 /* //forward, all black
    if((digitalRead(irl)==LOW)&&(digitalRead(irml)==LOW)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==LOW)&&(digitalRead(irr)==LOW))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }*/
  //forward, all white except irm(BLACK)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }
 /* //forward, all white except irm,irr(BLACK)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==LOW))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }  */
  /*  //forward, all white except irl,irm(BLACK)
    else if((digitalRead(irl)==LOW)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }  */
 /* //forward, all white
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==HIGH)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }  */
 /*  //forward, all white except irl,irr(BLACK)
    else if((digitalRead(irl)==LOW)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==HIGH)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==LOW))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }  */
   //forward, all black except irl,irr(WHITE)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==LOW)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==LOW)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
    }  
  //extreme right, all black except irl,irml(WHITE)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==LOW)&&(digitalRead(irr)==LOW))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,s);
      delay(d);
    }
   //extreme right, only irr is black
    else if(digitalRead(irr)==LOW)
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,s);
      delay(d);
    }
 
 /* //extreme right, all black except irl(WHITE)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==LOW)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==LOW)&&(digitalRead(irr)==LOW))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,s);
      delay(d);
    }  */
  // half right, all white except irm,irmr(BLACK)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==LOW)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,0);
      delay(d);
    }
  //extreme left, all black except irmr,irr(WHITE)
    else if((digitalRead(irl)==LOW)&&(digitalRead(irml)==LOW)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,0);
      analogWrite(in2,s);
      analogWrite(in3,s);
      analogWrite(in4,0);
      delay(d);
    }
    //extreme left, only irl is black
    else if(digitalRead(irl)==LOW)
    {
      analogWrite(in1,0);
      analogWrite(in2,s);
      analogWrite(in3,s);
      analogWrite(in4,0);
      delay(d);
    }
 /* //extreme left, all black except irr(WHITE)
    else if((digitalRead(irl)==LOW)&&(digitalRead(irml)==LOW)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==LOW)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,0);
      analogWrite(in2,s);
      analogWrite(in3,s);
      analogWrite(in4,0);
      delay(d);
    }  */
  //half left, all white except irml,irm(BLACK)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==LOW)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,0);
      analogWrite(in2,0);
      analogWrite(in3,s);
      analogWrite(in4,0);
      delay(d);
    }
//for M shape
    //right back , all white, except irm,irr(BLACK)
    else if((digitalRead(irl)==HIGH)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==LOW))
    {
      analogWrite(in1,s);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,s);
      delay(d);
    }
    //left back , all white, except irm,irl(BLACK)
    else if((digitalRead(irl)==LOW)&&(digitalRead(irml)==HIGH)&&(digitalRead(irm)==LOW)&&(digitalRead(irmr)==HIGH)&&(digitalRead(irr)==HIGH))
    {
      analogWrite(in1,0);
      analogWrite(in2,s);
      analogWrite(in3,s);
      analogWrite(in4,0);
      delay(d);
    }
}
