#pragma once

#include <Arduino.h>
#include <RGBLight.h>
#include <RGB.h>
#include <Report.h>

class HueAnimation
{
  enum Phase : unsigned char
  {
    PhaseGreenUp,
    PhaseRedDown,
    PhaseBlueUp,
    PhaseGreenDown,
    PhaseRedUp,
    PhaseBlueDown,
  };

private:
  RGBLight light;
  int intervalMs;
  unsigned char updateDiff;
  unsigned long lastMillis = 0;
  Phase phase = PhaseGreenUp;

  void updateLastMillis();

public:
  HueAnimation(RGBLight &light,
               int intervalMs);

  void update();

  void setInterval(int intervalMs);
};