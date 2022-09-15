#include <M5Stack.h>

void setup(){
  M5.begin(); 
  M5.Power.begin();
  
  M5.lcd.setTextSize(30);
  M5.Lcd.println("Hello");
  M5.Lcd.println("World");
}

void loop() {

}
