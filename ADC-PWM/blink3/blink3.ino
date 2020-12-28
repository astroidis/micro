void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

unsigned int tm = 1;
short int k = 1;
unsigned short int led = 8;

void loop() {
  digitalWrite(led, HIGH);
  delayMicroseconds(tm);
  digitalWrite(led, LOW);
  delayMicroseconds(999 - tm);

  tm = tm + k*1;
  if ( (tm == 999)||(tm == 1) ){
    k = k * (-1);
    if (tm == 1)
      led++;
  }

  if (led == 11)
    led = 8;
}
