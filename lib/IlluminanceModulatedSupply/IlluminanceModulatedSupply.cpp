#include <IlluminanceModulatedSupply.h>
#include <Arduino.h>
#include <IlluminanceSensor.h>
#include <RollingAverage.h>
#include <Report.h>
#include <Pin.h>

IlluminanceModulatedSupply::IlluminanceModulatedSupply(const Pin &supplyPIN,
                                                       const IlluminanceSensor &illuminanceSensor,
                                                       int illuminanceMeasurementsSize,
                                                       float maxBrightnessIluminance,
                                                       float minBrightnessIluminance) : supplyPIN(supplyPIN),
                                                                                        illuminanceSensor(illuminanceSensor),
                                                                                        maxBrightnessIluminance(maxBrightnessIluminance),
                                                                                        minBrightnessIluminance(minBrightnessIluminance),
                                                                                        illuminanceMeasurements(RollingAverage<int>(illuminanceMeasurementsSize))
{
}

void IlluminanceModulatedSupply::update()
{
  const int illuminance = this->illuminanceSensor.getVoltage();
  this->illuminanceMeasurements.addValue(illuminance);

  const int averageIlluminance = illuminanceMeasurements.getAverage();
  reportValue(averageIlluminance, "averageIlluminance");
  const int absoluteBrightness = map(averageIlluminance, this->minBrightnessIluminance, this->maxBrightnessIluminance, 0, 255);
  const int brightness = max<int>(min<float>(absoluteBrightness, 255), 0);
  reportValue(brightness, "brightness");

  this->supplyPIN.modulate(brightness);
}