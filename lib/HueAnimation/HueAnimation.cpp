#include <HueAnimation.h>

HueAnimation::HueAnimation(RGBLight &light,
                           int intervalMs) : light(light),
                                             intervalMs(intervalMs)
{
  this->lastMillis = millis();
}

void HueAnimation::updateLastMillis()
{
  this->lastMillis = millis();
}

void HueAnimation::update()
{
  if (this->lastMillis == 0)
  {
    RGB color(255, 0, 0);
    this->light.setColor(color);
    this->updateLastMillis();
    return;
  }
}