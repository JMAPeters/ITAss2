int getLightValue(){
  digitalWrite(selectPin, lightValue);
  return analogRead(analogPin);
}
