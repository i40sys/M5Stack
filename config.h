#include <pgmspace.h>

void connectWiFi(void);
void NTPConnect(void);
void NTPConnect(void);
void connectMQTT(void);
void publishMessage(void);
void readSensor(void);

#define LOOP_TIME 10000

#define TIME_ZONE "CET-1CEST"

#define THINGNAME "m5stack_demo_board"
#define MQTT_VERSION MQTT_VERSION_3_1_1
const char MQTT_HOST[] = "a1b6ebmeqxctip-ats.iot.eu-central-1.amazonaws.com";
const int MQTT_PORT = 8883;
#define TOPIC_PUB "md5stack/temp"

