#include <Wire.h>

void setup() {
  Wire.begin(0x23);
  Wire.onRequest(reqInt);
}

byte data;

void loop() {
  data = analogRead(A0) >> 2;
  delay(100);
}

void reqInt(){
  Wire.write(data);
}
