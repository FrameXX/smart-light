#pragma once

#include <Arduino.h>
#include <IlluminanceSensor.h>
#include <RollingAverage.h>
#include <Pin.h>
#include <Clamp.h>

class IlluminanceModulatedSupply
{
private:
  Pin supplyPIN;
  IlluminanceSensor illuminanceSensor;
  RollingAverage<int> illuminanceMeasurements;
  float maxBrightnessIluminance;
  float minBrightnessIluminance;

public:
  IlluminanceModulatedSupply(const Pin &supplyPIN, const IlluminanceSensor &illuminanceSensor, int illuminanceMeasurements, float maxBrightnessIluminance = 0, float minBrightnessIluminance = 500);

  void update();

  void setIlluminanceMeasurementsSize(int size);
};