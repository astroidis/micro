void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(2)){
    for (int i = 0; i<=7; i++){
      if (i & 0x01){
        digitalWrite(8, LOW);
      }
      else{
        digitalWrite(8, HIGH);
      }
  
      if (i & 0x02){
        digitalWrite(9, LOW);
      }
      else{
        digitalWrite(9, HIGH);
      }
  
      if (i & 0x04){
        digitalWrite(10, LOW);
      }
      else{
        digitalWrite(10, HIGH);
      }
  
      delay(250);
    }  // for 
  }
  else {
    for (int i = 0; i<=7; i++){
      if (i & 0x01){
        digitalWrite(10, LOW);
      }
      else{
        digitalWrite(10, HIGH);
      }
  
      if (i & 0x02){
        digitalWrite(9, LOW);
      }
      else{
        digitalWrite(9, HIGH);
      }
  
      if (i & 0x04){
        digitalWrite(8, LOW);
      }
      else{
        digitalWrite(8, HIGH);
      }
  
      delay(250);
    }
  }  // for
}  // loop
