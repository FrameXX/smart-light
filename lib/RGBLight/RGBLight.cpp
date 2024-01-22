#include <RGBLight.h>

RGBLight::RGBLight(Pin &RLEDSupply,
                   Pin &GLEDSupply,
                   Pin &BLEDSupply) : RLEDSupply(RLEDSupply),
                                      GLEDSupply(GLEDSupply),
                                      BLEDSupply(BLEDSupply)
{
}

void RGBLight::setColor(RGB color)
{
  this->RLEDSupply.modulate(color.R);
  this->GLEDSupply.modulate(color.G);
  this->BLEDSupply.modulate(color.B);
}