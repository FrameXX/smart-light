#include <AdaptiveLED.h>
#include <Arduino.h>
#include <LightEmittingDiode.h>
#include <IlluminanceSensor.h>
#include <RollingAverage.h>
#include <Report.h>

AdaptiveLED::AdaptiveLED(const LightEmittingDiode &lightEmittingDiode,
                         const IlluminanceSensor &illuminanceSensor,
                         int illuminanceMeasurementsSize,
                         float maxBrightnessIluminance,
                         float minBrightnessIluminance) : lightEmittingDiode(lightEmittingDiode),
                                                          illuminanceSensor(illuminanceSensor),
                                                          maxBrightnessIluminance(maxBrightnessIluminance),
                                                          minBrightnessIluminance(minBrightnessIluminance),
                                                          illuminanceMeasurements(RollingAverage<int>(illuminanceMeasurementsSize))
{
}

void AdaptiveLED::update()
{
  const int illuminance = this->illuminanceSensor.getVoltage();
  this->illuminanceMeasurements.addValue(illuminance);

  const int averageIlluminance = illuminanceMeasurements.getAverage();
  reportValue(averageIlluminance, "averageIlluminance");
  const int absoluteBrightness = map(averageIlluminance, this->minBrightnessIluminance, this->maxBrightnessIluminance, 0, 255);
  const int brightness = max<int>(min<float>(absoluteBrightness, 255), 0);
  reportValue(brightness, "brightness");

  this->lightEmittingDiode.setBrightness(brightness);
}