#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
}

int i = 0;

void loop() {
  if (Serial.available() > 0){
    if (Serial.read()){
      servo.write(i);
      i += 30;
      delay(15);
    }
  }
  i %= 180;
}
