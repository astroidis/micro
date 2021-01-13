#include <DHT.h>
#include <Wire.h>

DHT dht(2, DHT11);

void setup() {
  Wire.begin(0x23);
  //Wire.onReceive(recCode);
  Wire.onRequest(recCode);
  dht.begin();
}

union {
  float f;
  char c[4];
} h, t;

void loop() {
  h.f = dht.readHumidity();
  t.f = dht.readTemperature();

//  delay(100);
}

void readData(){
  h.f = dht.readHumidity();
  t.f = dht.readTemperature();
}

void sendData(){
  Wire.write(h.c[0]);
  Wire.write(h.c[1]);
  Wire.write(h.c[2]);
  Wire.write(h.c[3]);
  
//  Wire.write(t.c, 4);
}

//void recCode(int code){
//  while(Wire.available() > 0){
//    int c = Wire.read();
//    if (c == 0)
//      readData();
//    else if (c == 1)
//      sendData();
//  }
//}

void recCode(){
  sendData();
}
