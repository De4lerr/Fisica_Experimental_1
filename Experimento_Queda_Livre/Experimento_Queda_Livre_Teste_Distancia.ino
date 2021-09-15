#include <Servo.h>

Servo servo_motor;

const int SERVO = 9; //Porta utilizada pelo servo motor
const int TRIG = 3; //Porta utilizada pelo emissor de ondas ultrassônicas
const int ECHO = 2; //Porta utilizada pelo receptor de ondas ultrassônicas
const int teta = 140 //Ângulo de fechamento da garra robótica

unsigned int distancia; //Variável que armazena a distância medida pelo sensor

void setup() {
  Serial.begin(9600); //Taxa de transmissão de dados utilizada e recomendada para o modelo de sensor ultrassônico HC-SR04
  
  servo_motor.attach(SERVO);
  servo_motor.write(teta);

  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() {
  distancia = sensor(TRIG,ECHO);
  Serial.println(distancia);

}

int sensor(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);
  return pulseIn(pinoecho,HIGH)/5.8;
}
