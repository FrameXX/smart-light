#pragma once

#include <LightEmittingDiode.h>
#include <IlluminanceSensor.h>
#include <RollingAverage.h>

class AdaptiveLED
{
private:
  LightEmittingDiode lightEmittingDiode;
  IlluminanceSensor illuminanceSensor;
  RollingAverage<int> illuminanceMeasurements;
  float maxBrightnessIluminance;
  float minBrightnessIluminance;

public:
  AdaptiveLED(const LightEmittingDiode &lightEmittingDiode, const IlluminanceSensor &illuminanceSensor, int illuminanceMeasurements, float maxBrightnessIluminance = 100, float minBrightnessIluminance = 400);

  void update();
};