#pragma once

#include <Arduino.h>
#include <Report.h>
#include <RGB.h>
#include <RGBLight.h>

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
  RGB currentColor = RGB(255, 0, 128);
  float stepTimeMs;

  void updateLastMillis();

  void updateStepTimeMs();

  void nextPhase();

public:
  HueAnimation(RGBLight &light,
               int intervalMs);

  void update();

  void setInterval(int intervalMs);
};