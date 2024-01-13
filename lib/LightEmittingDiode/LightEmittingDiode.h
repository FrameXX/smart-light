#pragma once

#include <Pin.h>

class LightEmittingDiode
{
private:
  Pin supplyPin;

public:
  LightEmittingDiode(Pin supplyPin);

  void setBrightness(int brightness);

  void turnOn();

  void turnOff();
};