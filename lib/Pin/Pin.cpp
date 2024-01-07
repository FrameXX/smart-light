#include <Arduino.h>
#include "Pin.h"

Pin::Pin(uint8_t target) : target(target) {}

void Pin::useAsOutput()
{
  pinMode(this->target, OUTPUT);
}

void Pin::changeTarget(uint8_t target)
{
  this->target = target;
}

void Pin::setHigh()
{
  digitalWrite(this->target, HIGH);
}

void Pin::setLow()
{
  digitalWrite(this->target, LOW);
}

int Pin::readRelativeVoltage()
{
  return analogRead(this->target);
}

void Pin::modulate(float dutyFactor)
{
  analogWrite(this->target, dutyFactor);
}