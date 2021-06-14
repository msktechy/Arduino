float Kp = 10, Ki = 0, Kd = 0;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor[5] = {0, 0, 0, 0, 0};
int initial_motor_speed = 150;

const int motorA1 = 5; //Motor Direita
const int motorA2 = 6; //Motor Direita
const int motorB1 = 9; //Motor Esquerda
const int motorB2 = 10; //Motor Esquerda
const int motorA1_PWM = 3;
const int motorA2_PWM = 7;
const int motorB1_PWM = 11;
const int motorB2_PWM = 8;
int line;
int outline;

const int ss1 = A0;  // sensor 1
const int ss2 = A1;  // sensor 2
const int ss3 = A2; // sensor 3
const int ss4 = A3; // sensor 4
const int ss5 = A4; // sensor 5
//const int ss6 = 13; // sensor Near

//Declaração das funções
void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);
void right(void);
void left(void);

//Função de Setup do Arduino
void setup()
{
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorA1_PWM, OUTPUT);
  pinMode(motorB1_PWM, OUTPUT);
  pinMode(motorA2_PWM, OUTPUT);
  pinMode(motorB2_PWM, OUTPUT);

  pinMode(ss1, INPUT);
  pinMode(ss2, INPUT);
  pinMode(ss3, INPUT);
  pinMode(ss4, INPUT);
  pinMode(ss5, INPUT);
  //pinMode(ss6, INPUT);

  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB2, HIGH);

  delay(500);
}

//Função de execução continua do Arduino
void loop()
{
  read_sensor_values();
  calculate_pid();
  motor_control();
}

//Função responsável por fazer a leitura dos sensores do Robô
void read_sensor_values()
{
  line = 0;
  outline = 1;

  sensor[0] = digitalRead(ss1);
  sensor[1] = digitalRead(ss2);
  sensor[2] = digitalRead(ss3);
  sensor[3] = digitalRead(ss4);
  sensor[4] = digitalRead(ss5);

  if ((sensor[0] == outline) && (sensor[1] == outline) && (sensor[2] == line) && (sensor[3] == line) && (sensor[4] == line))
  { right();
  }
  else if ((sensor[0] == line) && (sensor[1] == line) && (sensor[2] == line) && (sensor[4] == outline) && (sensor[4] == outline))
  {
    left();
  }
  else if ((sensor[0] == outline) && (sensor[1] == outline) && (sensor[2] == outline) && (sensor[3] == outline) && (sensor[4] == line))
    error = 5;
  else if ((sensor[0] == line) && (sensor[1] == outline) && (sensor[2] == outline) && (sensor[4] == outline) && (sensor[4] == outline))
    error = -5;
  else if ((sensor[0] == outline) && (sensor[1] == outline) && (sensor[2] == outline) && (sensor[3] == line) && (sensor[4] == line))
    right();
  else if ((sensor[0] == line) && (sensor[1] == line) && (sensor[2] == outline) && (sensor[3] == outline) && (sensor[4] == outline))
    left();
  /*if((sensor[0]==outline)&&(sensor[1]==line)&&(sensor[2]==line)&&(sensor[3]==line)&&(sensor[4]==line))
      error=5;
    if((sensor[0]==line)&&(sensor[1]==line)&&(sensor[2]==line)&&(sensor[3]==line)&&(sensor[4]==outline))
      error=-5;*/
  else if ((sensor[0] == outline) && (sensor[1] == outline) && (sensor[2] == line) && (sensor[3] == line) && (sensor[4] == outline))
    error = 2;
  else if ((sensor[0] == outline) && (sensor[1] == line) && (sensor[2] == line) && (sensor[3] == outline) && (sensor[4] == outline))
    error = -2;
  /*  if((sensor[0]==outline)&&(sensor[1]==outline)&&(sensor[2]==outline)&&(sensor[3]==outline)&&(sensor[4]==outline))
      error=0;
    if((sensor[0]==line)&&(sensor[1]==line)&&(sensor[2]==line)&&(sensor[3]==line)&&(sensor[4]==line))
      error=0;
    if((sensor[1]==outline)&&(sensor[2]==line)&&(sensor[3]==outline))
      error=0;*/
  else if ((sensor[0] == outline) && (sensor[1] == outline) && (sensor[2] == line) && (sensor[3] == outline) && (sensor[4] == outline))
    error = 0;
}

void calculate_pid()
{

  P = error;
  I = error + previous_I;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_I = I;
  previous_error = error;
}


void motor_control()
{
  int left_motor_speed;
  int right_motor_speed;

  left_motor_speed = initial_motor_speed + PID_value;
  right_motor_speed = initial_motor_speed - PID_value;

  if (left_motor_speed < 0)
    left_motor_speed = 0;
  if (right_motor_speed < 0)
    right_motor_speed = 0;

  if (left_motor_speed > 255)
    left_motor_speed = 255;
  if (right_motor_speed > 255 )
    right_motor_speed = 255;

  analogWrite(motorB1_PWM, left_motor_speed);
  analogWrite(motorB2_PWM, left_motor_speed);
  analogWrite(motorA1_PWM, right_motor_speed);
  analogWrite(motorA2_PWM, right_motor_speed);

  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);

}


void right()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorB1_PWM, 250);
  analogWrite(motorB2_PWM, 250);
  analogWrite(motorA1_PWM, 250);
  analogWrite(motorA2_PWM, 250);
}
void left()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorB1_PWM, 250);
  analogWrite(motorB2_PWM, 250);
  analogWrite(motorA1_PWM, 250);
  analogWrite(motorA2_PWM, 250);
}
