#include <Adafruit_Sensor.h>

#include <DHT.h>

DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity %: ");
  Serial.println(h);
  Serial.print("Temperature %: ");
  Serial.println(t);

  delay(1000);
}
