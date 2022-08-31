# M5stack Demo Board notes

- M5Stack-HelloWorld - the basics
- SHT30 - temperature
- WFi+NTP - Connecting to WiFi
- SHT30+WFi+NTP+MQTT - publishing sensor data to MQTT broker
- SHT30+WFi+NTP+AWSIoTCore - publishing sensor data to AWS IoT Core

# References
- Tech datails and code of M5Stack library for Core Basic: https://github.com/m5stack/m5stack
- https://randomnerdtutorials.com/esp32-useful-wi-fi-functions-arduino/#4
- M5Stack.h functions: https://github.com/m5stack/M5Stack/blob/master/src/M5Stack.h
- ESPDateTime, Time library: https://github.com/mcxiaoke/ESPDateTime/blob/master/examples/simple/main.cpp
- Timezones: https://github.com/mcxiaoke/ESPDateTime/blob/master/src/DateTimeTZ.h

# Troubleshouting 

Remove "build/" directory if building process fails.