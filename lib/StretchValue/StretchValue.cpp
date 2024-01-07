#include "StretchValue.h"

template <typename Number>
Number stretchValue(Number value, Number floor, Number ceil)
{
  if (ceil < floor)
  {
    const Number ceilTemp = ceil;
    ceil = floor;
    floor = ceilTemp;
  }

  assert(0 <= value <= 1);

  constexpr Number range = ceil - floor;
  constexpr Number scaledValue = value * range;
  constexpr Number stretchedValue = floor + scaledValue;

  return stretchedValue;
}