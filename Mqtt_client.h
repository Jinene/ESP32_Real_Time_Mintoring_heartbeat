#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <WiFi.h>
#include <PubSubClient.h>

extern WiFiClient espClient;
extern PubSubClient client;

void setupMQTT();
void reconnectMQTT();
void publishHeartbeat(long heartRate);

#endif
// mqtt_client.h
// mqtt_client.h
