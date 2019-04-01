void System(){
  bme280();
  lightSensor();
  if (_time->tm_min >= soilTimer){
    soilTimer = (_time->tm_min + soilWaitTime + 60) % 60;
    soilSensor();
  }

  digitalWrite(ledPin, systemMode);
  if (systemMode = 1){
    autoSystem();
  } else {
    //manualSystem();
  }
}

void autoSystem(){
  //if (soilValue < 100000){
    //Pump();
  //}
  if (_time->tm_sec >= screenTimer){
    screenTimer = (_time->tm_sec + screenWaitTime + 60) % 60;
    screenNr = (screenNr + 1 + screenTotal) % screenTotal;
  }

  switch(screenNr){
    case 0:
      printTime();
      break;
    case 1:
      printBME280();
      break;
    case 2:
      printLight();
      break;
    case 3:
      printSoil();
      break;
  }
}
