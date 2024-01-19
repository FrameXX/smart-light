#pragma once

#include <vector>
#include <Arduino.h>

class MessageCommand
{
private:
  int commandType;
  std::vector<int> arguments;

public:
  MessageCommand(int cmdType, std::vector<int> args);

  static MessageCommand fromString(String message);

  String toString();
};
