#include <LightEmittingDiode.h>
#include <Pin.h>

LightEmittingDiode::LightEmittingDiode(Pin supplyPin) : supplyPin(supplyPin)
{
  supplyPin.useAsOutput();
}

void LightEmittingDiode::setBrightness(int brightness)
{
  this->supplyPin.modulate(brightness);
}

void LightEmittingDiode::turnOn()
{
  this->supplyPin.writeHigh();
}

void LightEmittingDiode::turnOff()
{
  this->supplyPin.writeLow();
}