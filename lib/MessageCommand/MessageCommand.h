#pragma once

#include <vector>
#include <Arduino.h>

class MessageCommand
{
public:
  int commandId;
  std::vector<int> arguments;

  MessageCommand(int cmdType, std::vector<int> args);

  static MessageCommand fromString(String message);

  String toString();
};
