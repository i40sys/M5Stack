# Description

Gathers temperature and humidity from a snsor (SHT30),
then data is published to AWS IoT Cores using MQTT.

Connects to a WiFi for getting Internet, and synchronizes 
internal clock using NTP.

Communications with AWS IoT Core are secure and uses X509 
certificates emitted by AWS.
