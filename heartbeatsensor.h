// heartbeat_sensor.h
#ifndef HEARTBEAT_SENSOR_H
#define HEARTBEAT_SENSOR_H

#include <MAX30105.h>

void initHeartSensor();
long readHeartRate();

extern MAX30105 heartSensor;

#endif
