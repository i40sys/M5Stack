#include <M5Stack.h>
#include <SHT3X.h>

SHT3X sht30;
float tmp = 0.0;
float hum = 0.0;

void setup() {
  M5.begin(115200);
  M5.Power.begin(); 
  M5.lcd.setTextSize(4);
  M5.Lcd.println("Booting...");
  delay(10000);
}

void loop() {
  if (sht30.get()==0) {
    tmp = sht30.cTemp;
    hum = sht30.humidity;
  }

  Serial.printf("Temperatura: %2.2fºC Humedad: %0.2f%%\r\n", tmp, hum);
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.printf("Temp: %2.1f \r\nHumi: %2.0f%% \r\n", tmp, hum);

  delay(5000);
}