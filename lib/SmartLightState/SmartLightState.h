#pragma once

class SmartLightState
{
public:
  bool enabled = true;
  unsigned char RDutyCycle = 255;
  unsigned char GDutyCycle = 255;
  unsigned char BDutyCycle = 255;

  SmartLightState();
};