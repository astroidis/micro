void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);
}

char i;
void loop() {
  if (Serial.available() > 0){
    i = Serial.read();
    Serial.write(i);
    Serial.flush();
    
    if (i != '0'){
      digitalWrite(8, HIGH);
    }
    else{
      digitalWrite(8, LOW);
    }
  }
}
