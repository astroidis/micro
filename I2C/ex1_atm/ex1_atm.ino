#include <Wire.h>

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Wire.begin(0x23);
  Wire.onReceive(recInt);  // set interrupt handler
  Serial.begin(9600);
}

bool k = false;

void loop() {
  int pin = 9;
  int d;

  if (k)
    d = 1;
  else
    d = 0;

  digitalWrite(pin+d, HIGH);
  delay(100);
  digitalWrite(pin+d, LOW);
  delay(100);
}

// define handler function
void recInt(int bytescount){
  while (Wire.available() > 0){
    int c = Wire.read();
    if (c == 5)
      k = !k;
    Serial.println(c);
  }  
}
