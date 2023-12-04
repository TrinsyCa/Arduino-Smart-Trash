#include <Servo.h>

#define echo 6
#define trig 7

Servo motor;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  motor.attach(9);
  Serial.begin(9600);
}

void loop() {
  motor.write(45);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  float zaman = pulseIn(echo, HIGH);
  float cm = zaman / 58.2;
  Serial.println(cm);

  if(cm <= 10)
  {
    delay(500);
    motor.write(125);
    delay(5000);
    motor.write(0);
  }
}