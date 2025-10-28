#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_SSD1306.h>
#include <MAX30105.h>

// Wi-Fi credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

// MQTT Broker
const char* mqttServer = "broker.hivemq.com"; 
int mqttPort = 1883;
const char* topic = "esp32/heartbeat";

// Sensor and display initialization
MAX30105 heartSensor;
Adafruit_SSD1306 display(128, 64, &Wire);

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // MQTT setup
  client.setServer(mqttServer, mqttPort);

  // Initialize sensor
  heartSensor.begin();
  
  // Initialize OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  // Read heart rate
  long heartRate = heartSensor.getHeartRate(); 

  // Display on OLED
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Heart Rate: ");
  display.println(heartRate);
  display.display();

  // Publish to MQTT
  if (!client.connected()) reconnectMQTT();
  client.loop();
  client.publish(topic, String(heartRate).c_str());

  delay(1000);
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
