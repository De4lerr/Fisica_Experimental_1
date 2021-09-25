#include <Servo.h>

Servo servo_motor;

const int SERVO = 9; //Porta utilizada pelo servo motor
const int teta = 140; //Ângulo de fechamento da garra robótica

const int BOT = 5; //Porta utilizada pelo botão

void setup() {
  pinMode(BOT, INPUT);
  servo_motor.attach(SERVO); 
  servo_motor.write(teta); 
}

void loop() {
  if (digitalRead(BOT)==HIGH){
    servo_motor.write(90); 
  } else {
    servo_motor.write(teta); 
  }
}
