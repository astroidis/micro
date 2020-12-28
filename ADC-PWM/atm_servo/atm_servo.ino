#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(10);
}

void loop() {
  unsigned int angle = analogRead(A0);
  angle = angle * 0.175;
  servo.write(angle);
  delay(15);
}
