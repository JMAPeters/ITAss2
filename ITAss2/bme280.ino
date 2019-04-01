void bme280Setup(){
  Wire.begin(D6,D5);
  bme.begin(0x76);
}
void bme280(){
  temperature = bme.readTemperature();
  pressure = bme.readPressure() / 100.0F;
  humidity = bme.readHumidity();
}
