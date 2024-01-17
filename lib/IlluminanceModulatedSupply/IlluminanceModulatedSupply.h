#pragma once

#include <IlluminanceSensor.h>
#include <RollingAverage.h>
#include <Pin.h>

class IlluminanceModulatedSupply
{
private:
  Pin supplyPIN;
  IlluminanceSensor illuminanceSensor;
  RollingAverage<int> illuminanceMeasurements;
  float maxBrightnessIluminance;
  float minBrightnessIluminance;

public:
  IlluminanceModulatedSupply(const Pin &supplyPIN, const IlluminanceSensor &illuminanceSensor, int illuminanceMeasurements, float maxBrightnessIluminance = 100, float minBrightnessIluminance = 400);

  void update();
};