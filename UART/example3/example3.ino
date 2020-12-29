void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

char i;
void serialEvent(){
  i = Serial.read();
  if (i != '0'){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }
}

void loop() {
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(500);
}
