#define LED 10

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int ADCvalue = analogRead(A0);
  ADCvalue == ADCvalue >> 2;
  analogWrite(LED, ADCvalue);
  delay(10);
}
