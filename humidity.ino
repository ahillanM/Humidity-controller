#include <dht11.h>

#define DHT11PIN 4
const int HPin =  5;      // the number of the LED pin
const int RECV_PIN = 6;

dht11 DHT11;
bool ledState = false;

void setup()
{
  Serial.begin(9600);
  pinMode(HPin, OUTPUT);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);

  if ((float)DHT11.humidity <= 48.00) {
    digitalWrite(HPin, LOW);
  }
    if ((float)DHT11.humidity > 48.00) {
    digitalWrite(HPin, HIGH);
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);
}
