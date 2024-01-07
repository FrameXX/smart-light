#pragma once

#include <vector>

template <typename Number>
class RollingAverage
{
private:
  std::vector<Number> values;
  int capacity;

public:
  RollingAverage(int capacity);
  Number getAverage();
  void addValue(Number value);
  void resize(int newCapacity);
};