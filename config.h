#include <pgmspace.h>

void connectWiFi(void);
void NTPConnect(void);
void NTPConnect(void);
void connectMQTT(void);
void publishMessage(void);
void readSensor(void);


#define SECRET_SSID "AP"
#define SECRET_PSW "lavit2ap_"

int8_t TIME_ZONE = +2;

#define THINGNAME "md5stack_demo_board"
#define MQTT_VERSION MQTT_VERSION_3_1_1
const char MQTT_HOST[] = "test.mosquitto.org";
const int MQTT_PORT = 1883;
#define TOPIC_PUB "md5stack/temp"