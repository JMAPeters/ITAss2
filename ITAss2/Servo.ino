void ServoSetup(){
  servo.attach(servoPin);
}

void Pump(){
  printPump();
  waterTime = "";
  waterTime += _time->tm_hour;
  waterTime += ":";
  if (_time->tm_min < 10) {waterTime += "0";}
  waterTime += _time->tm_min;
  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(15);
  }
  maxML = maxML - milPerPump;
  soilSensor();
}
