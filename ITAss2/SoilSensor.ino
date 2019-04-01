int soilSensor(){
  Serial.print("soil: "); Serial.println(soilValue);
  digitalWrite(selectPin, soilSelectValue);
  delay(50);
  soilValue = analogRead(analogPin);
}
