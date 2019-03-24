void displaySetup(){
  Wire.begin(D6, D5);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  
}

void printDisplay(char* string){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); 
  display.println(string);
  display.display();
  delay(2000);
}
