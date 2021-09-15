#include <Servo.h>

Servo servo_motor;

const int SERVO = 9; //Porta utilizada pelo servo motor
const int TRIG = 3; //Porta utilizada pelo emissor de ondas ultrassônicas
const int ECHO = 2; //Porta utilizada pelo receptor de ondas ultrassônicas
const int delaay = 5000; //Tempo entre o fechamento da garra robótica e sua abertura
const int delta = 23; //Distância medida entre o sensor e a bola
const int erro = 3; //Precisão da medição do sensor
const int d1 = 200; //Primeira distância medida em milímetros
const int d2 = 400; //Segunda distância medida em milímetros
const int d3 = 600; //Terceira distância medida em milímetros
const int teta = 140 //Ângulo de fechamento da garra robótica

unsigned int distancia; //Variável que armazena a distância medida pelo sensor
unsigned long tempo; //Variável que armazena o tempo decorrido desde o lançamento

void setup() {
  Serial.begin(9600); //Taxa de transmissão de dados utilizada e recomendada para o modelo de sensor ultrassônico HC-SR04
  
  servo_motor.attach(SERVO); 
  servo_motor.write(teta); 
  delay(delaay);
  servo_motor.write(90);
  
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() {
  distancia = sensor(TRIG,ECHO) - delta;
  tempo = millis()- delaay;

  if (distancia >= (d1 - erro) && distancia <= (d1 + erro)) {  
      Serial.print ("Tempo1: ");
      Serial.println (tempo);
  }
  if (distancia >= (d2 - erro) && distancia <= (d2 + erro)) {  
      Serial.print ("Tempo2: ");
      Serial.println (tempo);
  }
  if (distancia >= (d3 - erro) && distancia <= (d3 + erro)) {  
      Serial.print ("Tempo3: ");
      Serial.println (tempo);
  }
}

int sensor(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);
  return pulseIn(pinoecho,HIGH)/5.8;
}
