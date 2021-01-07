void setup() {
  Serial.begin(9600);
}

void loop() {
  int adc = analogRead(A0);
  adc >>= 2;
  Serial.write(adc);
  Serial.flush();
}
