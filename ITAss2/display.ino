void displaySetup(){
  Wire.begin(D6, D5);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void printTime(){
  timeString = "";
  timeString += _time->tm_hour;
  timeString += ":";
  if (_time->tm_min < 10) {timeString += "0";}
  timeString += _time->tm_min;
  dateString = "";
  dateString += _time->tm_mday;
  dateString += ".";
  dateString += _time->tm_mon + 1;
  dateString += ".";
  dateString += _time->tm_year + 1900;

  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(4, 0); 
  display.println(timeString);
  display.setTextSize(2);
  display.setCursor(11,40);
  display.println(dateString);
  display.display();
}

void printBME280(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 0); 
  display.print(temperature); display.println("'C");
  display.setCursor(5,20);
  display.print(pressure); display.println("hPa");
  display.setCursor(30,40);
  display.print(humidity); display.println("%");
  display.display();
}

void printLight(){
  int lightPer = (lightValue * 100) / 1024;
  if (lightPer == 100){
    display.clearDisplay();
    display.drawBitmap(0, 0, sun, 128, 64 , WHITE);
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(48,25);
    display.print(lightPer); display.println("%");
    display.display();
  } else
  if (lightPer < 100 && lightPer >= 20){
    display.clearDisplay();
    display.drawBitmap(0, 0, cloud, 128, 64 , WHITE);
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(48,25);
    display.print(lightPer); display.println("%");
    display.display();
  } else
  if (lightPer < 20){
    display.clearDisplay();
    display.drawBitmap(0, 0, moon, 128, 64 , WHITE);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(60,18);
    display.print(lightPer); display.println("%");
    display.display();
  }
}

void printSoil(){
    display.clearDisplay();
    display.drawBitmap(0, 0, plant, 128, 64 , WHITE);
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(67,20);
    display.print("50"); display.println("%");
    display.setTextSize(1);
    display.setCursor(20,55);
    display.println("1500");
    display.setTextColor(WHITE);
    display.setCursor(68,55);
    display.println(waterTime);
    display.display();
}

void printPump(){
    display.clearDisplay();
    display.drawBitmap(0, 0, raindrops, 128, 64 , WHITE);
    display.display();
}
