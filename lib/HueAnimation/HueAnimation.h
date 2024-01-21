#pragma once

#include <Pin.h>

class HueAnimation
{
public:
  HueAnimation(Pin RLEDSupply,
               Pin GLEDSupply,
               Pin BLEDSupply);

  void update();
};