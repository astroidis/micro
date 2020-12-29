void setup() {
  Serial.begin(9600);
}

int old, nw;
void serialEvent(){
  if (Serial.read()){
    nw = analogRead(A0);
    Serial.println(nw);
  }
}

void loop() {
}
