#pragma once

template <typename Number>
Number amplify(Number value, Number minValue, Number maxValue, float exponent)
{
  const Number size = maxValue - minValue;
  const Number part = value - minValue;
  const float fraction = static_cast<float>(value) / static_cast<float>(size);
  const Number amplified = pow(fraction, exponent) * value;
  return amplified;
}