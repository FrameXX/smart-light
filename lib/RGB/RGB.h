#pragma once

#include <Clamp.h>

class RGB
{
private:
  unsigned char R;
  unsigned char G;
  unsigned char B;

public:
  RGB(unsigned char R, unsigned char G, unsigned char B);

  void setR(unsigned char R);
  void setG(unsigned char G);
  void setB(unsigned char B);

  unsigned char getR();
  unsigned char getG();
  unsigned char getB();
};