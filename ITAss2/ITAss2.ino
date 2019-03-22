#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//Wifi
const char* ssid = "WifiNaam"; //"OnePlus3"
const char* password = "Unicorn1"; //"chinees1"
WiFiServer server(80);
#define ledPin 13

//BME280
#define SEALEVELPRESSURE_HPA (1013.25)
#define SCL 16
#define SDA 5
Adafruit_BME280 bme;


void setup() {
  //_ServerSetup();
  bme280Setup();
}
 
void loop() {
  //_Server();
  bme280();
 
}
