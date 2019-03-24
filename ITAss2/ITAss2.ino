#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Servo.h>

//Wifi
const char* ssid = "WifiNaam"; //"OnePlus3"
const char* password = "Unicorn1"; //"chinees1"
WiFiServer server(80);
#define ledPin 13

//BME280
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;

//Light sensor & Soil moisture sensor
#define selectPin 0
#define analogPin A0
int lightValue = LOW;
int soilValue = HIGH;

//display
#define OLED_RESET -1
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

//Servo
Servo servo;
int pos = 0;
#define servoPin 100000

void setup() {
  Serial.begin(115200);
  //_ServerSetup();
  //bme280Setup();
  displaySetup();
  pinMode(selectPin, OUTPUT);
}
 
void loop() {
  //_Server();
  //bme280();
  printDisplay("hoi");
}
