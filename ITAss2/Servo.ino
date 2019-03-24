void ServoSetup(){
  servo.attach(servoPin);
}

void Pump(int times){
  for (int i = 0; i < times; i += 1){
    for (pos = 0; pos <= 180; pos += 1) {
      servo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(15);
    }
  }
}
