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
  this->RLEDSupply.modulate(color.getR());
  this->GLEDSupply.modulate(color.getG());
  this->BLEDSupply.modulate(color.getB());
}