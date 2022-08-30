#include <M5Stack.h>
#include <WiFi.h>
#include <time.h>
/*
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
*/
#include <SHT3X.h>
#include "config.h"

time_t now;
time_t nowish = 1510592825;

SHT3X sht30;
float tmp = 0.0;
float hum = 0.0;

void NTPConnect(void) {
  Serial.print("Setting time using SNTP");
  configTime(TIME_ZONE * 3600, 0 * 3600, "pool.ntp.org", "time.nist.gov");
  now = time(nullptr);
  while (now < nowish)
  {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("done!");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.print("Current time: ");
  Serial.print(asctime(&timeinfo));
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

  delay(5000);
}

void loop() {
  if (sht30.get()==0) {
    tmp = sht30.cTemp;
    hum = sht30.humidity;
  }

  Serial.printf("Temperatura: %2.2f*C Humedad: %0.2f%%\r\n", tmp, hum);
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.printf("Temp: %2.1f \r\nHumi: %2.0f%% \r\n", tmp, hum);

  delay(500);
}
