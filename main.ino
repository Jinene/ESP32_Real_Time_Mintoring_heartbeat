#include <WiFi.h>
#include <PubSubClient.h>
#include "lcd_display.h"
#include "heartbeat_sensor.h"
#include "mqtt_client.h"

// Wi-Fi credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);

  // Initialize LCD/OLED
  initLCD();

  // Initialize heartbeat sensor
  initHeartSensor();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Initialize MQTT
  setupMQTT();
}

void loop() {
  // Read heart rate
  long heartRate = readHeartRate();

  // Update LCD/OLED display
  updateLCD(heartRate);

  // Publish heartbeat to MQTT
  if (!client.connected()) reconnectMQTT();
  client.loop();
  publishHeartbeat(heartRate);

  delay(1000);
}
