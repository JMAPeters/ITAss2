int getSoilValue(){
  digitalWrite(selectPin, soilValue);
  return analogRead(analogPin);
}
