void setup() {
  Serial.begin(9600);
}

int i = 0;
void loop() {
//  Serial.write(i);
//  Serial.flush();

//  Serial.print(i);
//  Serial.flush();
//  
  Serial.println(i);
  Serial.flush();

  i++;
}
