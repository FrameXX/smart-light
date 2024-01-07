#pragma once

#include <Pin.h>

class IlluminanceMeasurement
{
private:
  int relativeVoltage;
  float sensitivity;
  float supplyVoltage;
  float resistorResistance;
  float voltage;

public:
  IlluminanceMeasurement(Pin pin, float sensitivity, float supplyVoltage, float resistorResistance);
  float getRawValue();
  float toLux();
};