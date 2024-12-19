#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include "wifiData.h"

////////////////////wifiData.h////////////////////
// This file loofs like:

// struct wifiData {
//     const char* ssid     = "YOUR_SSID";
//     const char* password = "YOUR_PASSWORD";
// } wifiData;
//////////////////////////////////////////////////

int splitT;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

String formattedDate;
String dayStamp;
String timeStamp;

void setup() {
  Serial.begin(9600);
  lcd.init();                       // Initialize the LCD
  lcd.backlight();                  // Turn on the backlight
  lcd.clear();

  WiFi.begin(wifiData.ssid, wifiData.password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(7200);

  delay(1000);
}

void loop() {
  lcd.clear();

  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }

  formattedDate = timeClient.getFormattedDate();

  splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  lcd.setCursor(0, 0);
  lcd.print(dayStamp);

  timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
  lcd.setCursor(0, 1);
  lcd.print(timeStamp);

  /////////////clock format/////////////
  // lcd row 1 // yyyy-MM-dd
  // lcd row 2 // hh:mm:ss
  //////////////////////////////////////

  delay(1000);
}
