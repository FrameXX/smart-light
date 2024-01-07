#include "RollingAverage.h"

template <typename Number>
RollingAverage<Number>::RollingAverage(int capacity) : capacity(capacity)
{
  values.reserve(capacity);
}

template <typename Number>
Number RollingAverage<Number>::getAverage()
{
  Number sum = 0;
  for (Number value : values)
  {
    sum += value;
  }
  return sum / values.size();
}

template <typename Number>
void RollingAverage<Number>::addValue(Number value)
{
  if (values.size() >= capacity)
  {
    values.erase(values.begin());
  }
  values.push_back(value);
}

template <typename Number>
void RollingAverage<Number>::resize(int newCapacity)
{
  capacity = newCapacity;
  values.resize(capacity);
}