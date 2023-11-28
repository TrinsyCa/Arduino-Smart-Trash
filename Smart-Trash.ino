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
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  float zaman = pulseIn(echo, HIGH);
  float cm = zaman / 58.2;
  Serial.println(cm);

  if(cm < 10)
  {
    motor.write(90);
    delay(4000);
    motor.write(0);
  }
}
