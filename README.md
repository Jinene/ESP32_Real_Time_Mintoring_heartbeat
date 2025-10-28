1. Hardware Components

ESP32 board (any standard dev kit)

Pulse/heartbeat sensor (e.g., MAX30102, Pulse Sensor)

OLED/LCD display (e.g., 0.96" I2C OLED or 16x2 LCD)

Wi-Fi router (for MQTT and Node-RED connectivity)

Optional: buzzer or LED for alerts

2. Software/Platforms

Arduino IDE (or PlatformIO)

MQTT Broker (e.g., Mosquitto, or use cloud broker like HiveMQ)

Node-RED (dashboard for visualization)

Libraries:

WiFi.h – ESP32 Wi-Fi connection

PubSubClient.h – MQTT

Adafruit_GFX.h & Adafruit_SSD1306.h – for OLED

MAX30105.h – for MAX30102 sensor

LiquidCrystal_I2C.h – for LCD
