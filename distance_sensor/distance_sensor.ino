#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();

void setup()
{
  Serial.begin(115200);
  while (!sensor.begin()) {}
  sensor.startRangeContinuous();
}

long distance_c()
{
  if (sensor.isRangeComplete())
  {
    return sensor.readRange();
  }
  else
  {
    return 10000;
  }
}

void loop()
{
  Serial.println(distance_c());
}























