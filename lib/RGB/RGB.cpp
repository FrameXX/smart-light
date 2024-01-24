#include <RGB.h>

RGB::RGB(unsigned char R,
         unsigned char G,
         unsigned char B)
{
  this->setR(R);
  this->setG(G);
  this->setB(B);
}

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

void RGB::addR(unsigned char R)
{
  if (255 - this->R >= R)
  {
    this->R += R;
  }
  else
  {
    this->R = 255;
  }
}

void RGB::subtractR(unsigned char R)
{
  if (this->R >= R)
  {
    this->R -= R;
  }
  else
  {
    this->R = 0;
  }
}

void RGB::addG(unsigned char G)
{
  if (255 - this->G >= G)
  {
    this->G += G;
  }
  else
  {
    this->G = 255;
  }
}

void RGB::subtractG(unsigned char G)
{
  if (this->G >= G)
  {
    this->G -= G;
  }
  else
  {
    this->G = 0;
  }
}

void RGB::addB(unsigned char B)
{
  if (255 - this->B >= B)
  {
    this->B += B;
  }
  else
  {
    this->B = 255;
  }
}

void RGB::subtractB(unsigned char B)
{
  if (this->B >= B)
  {
    this->B -= B;
  }
  else
  {
    this->B = 0;
  }
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

String RGB::toString()
{
  String R(this->R);
  String G(this->G);
  String B(this->B);
  String RGB = R + " " + G + " " + B;
  return RGB;
}