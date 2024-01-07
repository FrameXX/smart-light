#include <Arduino.h>
#include <Pin.h>
#include "IlluminanceMeasurement.h"

IlluminanceMeasurement::IlluminanceMeasurement(Pin pin, float sensitivity, float supplyVoltage, float resistorResistance) : sensitivity(sensitivity),
                                                                                                                            supplyVoltage(supplyVoltage),
                                                                                                                            resistorResistance(resistorResistance)
{
  this->relativeVoltage = pin.readRelativeVoltage();
  this->voltage = relativeVoltage * (supplyVoltage / 1023.0);
}

float IlluminanceMeasurement::getRawValue()
{
  return relativeVoltage;
}

float IlluminanceMeasurement::toLux()
{
  float lux = (this->voltage / this->supplyVoltage) * (this->sensitivity / this->resistorResistance);
  return lux;
}