#include <IlluminanceSensor.h>

IlluminanceSensor::IlluminanceSensor(const Pin &supplyPin, const Pin &analogPin) : supplyPin(supplyPin), analogPin(analogPin)
{
  this->supplyPin.useAsOutput();
  this->supplyPin.writeHigh();
}

int IlluminanceSensor::getVoltage()
{
  const int voltage = this->analogPin.readAnalog();
  return voltage;
}