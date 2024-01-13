#pragma once

#include <Arduino.h>

template <typename SerialMessage>
inline void report(SerialMessage message, bool omitNewLine = false)
{
  if (!omitNewLine)
    Serial.print("\n");
  Serial.print(message);
}

template <typename ValueName, typename Value>
inline void reportValue(Value value, ValueName valueName = "value")
{
  report(valueName);
  report(": ", true);
  report(value, true);
}

inline void omitLine()
{
  Serial.print("\n");
}

inline void initSerial(unsigned long baudRate = 9600)
{
  Serial.begin(baudRate);
}