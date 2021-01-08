#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
}

int i = 0;
int st = 90;

void loop() {
  if (Serial.available() > 0){
    if (Serial.read()){
      servo.write(i);
      i += st;
      delay(15);
      if (i == 180 || i == 0)
        st *= -1;
    } // read
  }
}
