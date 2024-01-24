#pragma once

#include <Pin.h>
#include <RGB.h>
#include <Amplify.h>

class RGBLight
{
private:
  Pin RLEDSupply;
  Pin GLEDSupply;
  Pin BLEDSupply;

public:
  RGBLight(Pin &RLEDSupply,
           Pin &GLEDSupply,
           Pin &BLEDSupply);

  void setColor(RGB color);
};