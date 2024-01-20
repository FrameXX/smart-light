#include <IlluminanceModulatedSupply.h>

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

  const int absoluteBrightness = map(averageIlluminance, this->minBrightnessIluminance, this->maxBrightnessIluminance, 0, 255);
  const int brightness = clamp(absoluteBrightness, 0, 255);
  this->supplyPIN.modulate(brightness);
}

void IlluminanceModulatedSupply::setIlluminanceMeasurementsSize(int size)
{
  this->illuminanceMeasurements.resize(size);
}