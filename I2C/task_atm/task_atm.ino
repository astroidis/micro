#include <DHT.h>
#include <Wire.h>

DHT dht(2, DHT11);

void setup() {
  Wire.begin(0x23);
  Wire.onRequest(reqEvent);
  dht.begin();
}

union {
  float f;
  char c[4];
} h, t;

char buf[8];

void loop() {
  h.f = dht.readHumidity();
  t.f = dht.readTemperature();

  for (int i = 0; i < 4; i++){
    buf[i] = h.c[i];
  }

  for (int i = 0; i < 4; i++){
    buf[4 + i] = t.c[i];
  }

  delay(100);
}

void reqEvent(){
  Wire.write(buf, 8);
}
