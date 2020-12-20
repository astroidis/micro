void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  
  if (digitalRead(2)){
    digitalWrite(8, LOW);
  }
  else{
    digitalWrite(8, HIGH);
  }

  if (digitalRead(3)){
    digitalWrite(9, LOW);
  }
  else{
    digitalWrite(9, HIGH);
  }

  if (digitalRead(5)){
    digitalWrite(10, LOW);
  }
  else{
    digitalWrite(10, HIGH);
  }
}
