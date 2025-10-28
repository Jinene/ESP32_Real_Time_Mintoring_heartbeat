// heartbeat_sensor.cpp
#include "heartbeat_sensor.h"

MAX30105 heartSensor;

void initHeartSensor() {
  if (!heartSensor.begin()) {
    Serial.println("MAX30102 not found. Check wiring!");
    while (1);
  }
  // Optional: sensor configuration
  heartSensor.setup(); // default configuration
}

long readHeartRate() {
  // Implement a simple pulse calculation
  long bpm = heartSensor.getHeartRate(); // or custom reading
  return bpm;
}
