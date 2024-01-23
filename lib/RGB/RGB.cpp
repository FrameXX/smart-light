#include <RGB.h>

void RGB::setR(unsigned char R)
{
  this->R = clamp(R, static_cast<unsigned char>(0), static_cast<unsigned char>(255));
}

void RGB::setG(unsigned char G)
{
  this->G = clamp(G, static_cast<unsigned char>(0), static_cast<unsigned char>(255));
}

void RGB::setB(unsigned char B)
{
  this->B = clamp(B, static_cast<unsigned char>(0), static_cast<unsigned char>(255));
}

unsigned char RGB::getR()
{
  return this->R;
}

unsigned char RGB::getG()
{
  return this->G;
}

unsigned char RGB::getB()
{
  return this->B;
}