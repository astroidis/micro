void setup() {
//  from opi
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
//  leds
  pinMode(8, OUTPUT);  // at1
  pinMode(9, OUTPUT);  // at2
  pinMode(10, OUTPUT);  // at3
}

void loop() {
  if (digitalRead(2))
    digitalWrite(10, HIGH);
  else
    digitalWrite(10, LOW);

  if (digitalRead(3))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);

  if (digitalRead(5))
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);
}
