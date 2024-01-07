#pragma once

#include <Arduino.h>

class Pin
{
private:
  uint8_t target;

public:
  Pin(uint8_t target);

  void changeTarget(uint8_t target);

  void useAsOutput();

  int readRelativeVoltage();

  void setHigh();

  void setLow();

  void modulate(float dutyFactor);
};