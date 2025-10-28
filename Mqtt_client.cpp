// mqtt_client.cpp
#include "mqtt_client.h"

const char* mqttServer = "broker.hivemq.com"; 
int mqttPort = 1883;
const char* topic = "esp32/heartbeat";

WiFiClient espClient;
PubSubClient client(espClient);

void setupMQTT() {
  client.setServer(mqttServer, mqttPort);
}

void reconnectMQTT() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe(topic);
    } else {
      delay(5000);
    }
  }
}

void publishHeartbeat(long heartRate) {
  client.publish(topic, String(heartRate).c_str());
}
