#include <M5Stack.h>
#include <WiFi.h>
#include <ESPDateTime.h>
#include "config.h"

void NTPConnect(void) {
  DateTime.setServer("time.pool.aliyun.com");
  DateTime.setTimeZone(TIME_ZONE);
  DateTime.begin();
  if (!DateTime.isTimeValid()) {
    Serial.println("NTP server: fail.");
  } else {
    Serial.printf("Date Now is %s\n", DateTime.toISOString().c_str());
    M5.Lcd.println(DateTime.toISOString());
  }
}

void setup() {
  M5.begin(115200);
  M5.Power.begin(); 
  M5.lcd.setTextSize(2);
  M5.Lcd.println("Booting...");

  WiFi.mode(WIFI_AP_STA);
  WiFi.disconnect();
  delay(3000);

  WiFi.begin(SECRET_SSID, SECRET_PSW);
  Serial.println(String("Connecting SSID: ") + String(SECRET_SSID));
  M5.Lcd.println(String("Connecting SSID: ") + String(SECRET_SSID));
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());

  M5.Lcd.println("Connected!");
  M5.Lcd.print("IP: ");
  M5.Lcd.println(WiFi.localIP());
  M5.Lcd.print("SSID: ");
  M5.Lcd.println(WiFi.SSID());
  M5.Lcd.print("RSSI: ");
  M5.Lcd.println(WiFi.RSSI());

  NTPConnect();
}

void loop() {
}