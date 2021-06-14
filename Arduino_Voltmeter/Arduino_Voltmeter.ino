
int analogInput = A0;
float vout = 0.0;
float vin = 0.0;
float R1 = 98600.0; // resistance of R1 (100K)
float R2 = 9600.0; // resistance of R2 (10K)
int value = 0;
int a[5] = {};
void setup() {
  Serial.begin(115200);
  pinMode(analogInput, INPUT);


Serial.print("DC Voltmeter");
}
void loop() {
 
  // read the value at analog input
  value = analogRead(analogInput);
  vout = (value * 5) / 1024.0;
  vin = vout / (R2 / (R1 + R2));
  Serial.println(vin);
 /* if (vin < 0.09)
  {
    vin = 0.0;
  }*/
  
  Serial.print("Voltage V :");
  Serial.print(vin);
  delay(100);
}
