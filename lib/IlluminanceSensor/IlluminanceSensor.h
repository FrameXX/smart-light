#pragma once

#include <Pin.h>

class IlluminanceSensor
{
private:
  Pin analogPin;
  Pin supplyPin;

public:
  IlluminanceSensor(const Pin &supplyPin, const Pin &analogPin);

  int getVoltage();
};