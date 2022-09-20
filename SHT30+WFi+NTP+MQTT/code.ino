#include <M5Stack.h>
#include <WiFi.h>
#include <ESPDateTime.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <SHT3X.h>
#include "config.h"

SHT3X sht30;
float tmp = 0.0;
float hum = 0.0;

unsigned long lastMillis = 0;
unsigned long previousMillis = 0;
const long interval = 5000;

WiFiClient net;
PubSubClient client(net);

void connectWiFi(void) {
  WiFi.mode(WIFI_AP_STA);
  WiFi.disconnect();
  delay(1000);

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
}

void NTPConnect(void) {
  DateTime.setServer(NTP_SERVER);
  DateTime.setTimeZone(TIME_ZONE);
  DateTime.begin();
  if (!DateTime.isTimeValid()) {
    Serial.println("NTP server: fail.");
  } else {
    Serial.printf("Date Now is %s\n", DateTime.toISOString().c_str());
    Serial.printf("Timestamp is %ld\n", DateTime.now());
  }
}

void connectMQTT(void) {
  client.setServer(MQTT_HOST, MQTT_PORT);
  Serial.println("Connecting MQTT Broker...");
  M5.Lcd.println("Connecting MQTT Broker...");

  while (!client.connect(THINGNAME, MQTT_USER, MQTT_PASSWORD))
  {
    Serial.println(client.state());
    M5.Lcd.print(".");
    delay(1000);
  }
  if (!client.connected()) {
    Serial.println("Timeout!");
    M5.Lcd.println("Timeout!");
    return;
  }
  Serial.println("Connected!");
  M5.Lcd.println("Connected!");
}

void publishMessage(void) {
  StaticJsonDocument<200> doc;
  doc["ts"] = DateTime.toISOString();
  doc["epoch"] = time(nullptr);
  doc["humidity"] = hum;
  doc["temperature"] = tmp;
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client
 
  client.publish(TOPIC_PUB, jsonBuffer);
}

void readSensor(void) {
  if (sht30.get()==0) {
    tmp = sht30.cTemp;
    hum = sht30.humidity;
  }

  Serial.print(DateTime.toISOString());
  Serial.printf(" Temperatura: %2.2f*C Humedad: %0.2f%%\r\n", tmp, hum);
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.println(DateTime.toISOString());
  M5.Lcd.printf("Temp: %2.1f \r\nHumi: %2.0f%% \r\n", tmp, hum);
}

void setup() {
  M5.begin(115200);
  M5.Power.begin(); 
  M5.lcd.setTextSize(2);
  M5.Lcd.println("Booting...");

  connectWiFi();
  NTPConnect();
  connectMQTT();
  delay(5000);
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  } else {
    client.loop();
    if (millis() - lastMillis > interval) {
      lastMillis = millis();
      readSensor();
      publishMessage();
    }
  }
  delay(1000);
}