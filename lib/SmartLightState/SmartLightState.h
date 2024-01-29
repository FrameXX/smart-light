#pragma once

#include <MsgCmd.h>

class SmartLightState
{
public:
  bool enabled = true;
  unsigned char RDutyCycle = 255;
  unsigned char GDutyCycle = 255;
  unsigned char BDutyCycle = 255;
  bool hueAnimationEnabled = true;
  int hueAnimationIntervalMs = 3000;

  SmartLightState();

  MsgCmd toMsgCmd() const;
};