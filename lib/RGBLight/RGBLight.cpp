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
  const unsigned char R = amplify(int(color.getR()), 0, 255, 2);
  const unsigned char G = amplify(int(color.getG()), 0, 255, 2);
  const unsigned char B = amplify(int(color.getB()), 0, 255, 2);

  this->RLEDSupply.modulate(R);
  this->GLEDSupply.modulate(G);
  this->BLEDSupply.modulate(B);
}