int lightSensor(){
  digitalWrite(selectPin, lightSelectValue);
  delay(50);
  lightValue = analogRead(analogPin);
  int lighthfhf = (lightValue * 100) / 1024;
  Serial.print(lighthfhf); Serial.println("%");
}
