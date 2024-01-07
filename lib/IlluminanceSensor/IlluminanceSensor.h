#pragma once

#include <Pin.h>
#include <IlluminanceMeasurement.h>

class IlluminanceSensor
{
private:
  Pin analogPin;
  Pin supplyPin;
  float sensitivity;
  float supplyVoltage;
  float resistorResistance;

public:
  IlluminanceSensor(Pin &supplyPin, Pin &analogPin);

  IlluminanceMeasurement measure()
  {
    IlluminanceMeasurement measurement(this->analogPin, );
  }
};