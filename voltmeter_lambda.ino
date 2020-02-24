#include <ESP8266WiFi.h>
#include <Wire.h>  

//for 0.96" SSD1306 screen
//#include "SSD1306Wire.h" 
//SSD1306Wire  display(0x3c, D2, D1);  //D2=SDA  D1=SCL

//for 1.3" SH1106 screen
#include <SH1106Wire.h>
SH1106Wire  display(0x3c, D2, D1);  //D2=SDA  D1=SCL



String AFR;

void setup() {
  WiFi.forceSleepBegin();
  delay(1000);
  display.init();
  display.flipScreenVertically();

}

void loop() {
  int sensorValue = analogRead(A0);
  float volt = sensorValue * (3.2 / 1023.0)-0.03;  //looks like ESP8266 is not very accurate reading voltage, thus -0.03 in my case

if (volt>=0.895) {AFR = "rich";}
else if (volt>=0.885) {AFR = "11.50";}
else if (volt>=0.875) {AFR = "11.75";}
else if (volt>=0.865) {AFR = "12.00";}
else if (volt>=0.855) {AFR = "12.25";}
else if (volt>=0.845) {AFR = "12.50";}
else if (volt>=0.835) {AFR = "12.75";}
else if (volt>=0.825) {AFR = "13.00";}
else if (volt>=0.81) {AFR = "13.25";}
else if (volt>=0.7875) {AFR = "13.50";}
else if (volt>=0.7625) {AFR = "13.75";}
else if (volt>=0.725) {AFR = "14.00";}
else if (volt>=0.65) {AFR = "14.25";}
else if (volt>=0.525) {AFR = "14.50";}
else {AFR = "lean";}

String volt1 = String(volt,3);
  
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(Dialog_bold_42);
    display.drawString(0, 0, AFR);
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 40, volt1);
    display.display();
    delay(100);
}
