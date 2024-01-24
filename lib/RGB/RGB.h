#pragma once

#include <Arduino.h>
#include <Clamp.h>
#include <Report.h>

class RGB
{
private:
  unsigned char R;
  unsigned char G;
  unsigned char B;

public:
  RGB(unsigned char R,
      unsigned char G,
      unsigned char B);

  void setR(unsigned char R);
  void setG(unsigned char G);
  void setB(unsigned char B);

  void addR(unsigned char R);
  void addG(unsigned char G);
  void addB(unsigned char B);

  void subtractR(unsigned char R);
  void subtractG(unsigned char G);
  void subtractB(unsigned char B);

  unsigned char getR();
  unsigned char getG();
  unsigned char getB();

  String toString();
};