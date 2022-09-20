#define SECRET_SSID "AP"
#define SECRET_PSW "lavit2ap_"

#define NTP_SERVER "time.pool.aliyun.com"
#define TIME_ZONE "CET-1CEST"

#define THINGNAME "m5stack_demo_board"
#define MQTT_VERSION MQTT_VERSION_3_1_1
const char MQTT_HOST[] = "broker.hivemq.com";
const int MQTT_PORT = 1883;
#define TOPIC_PUB "m5stack/temp"

void connectWiFi(void);
void NTPConnect(void);
void NTPConnect(void);
void connectMQTT(void);
void publishMessage(void);
void readSensor(void);
