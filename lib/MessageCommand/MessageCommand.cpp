#include "MessageCommand.h"

MessageCommand::MessageCommand(int cmdType, std::vector<int> args) : commandId(cmdType), arguments(args) {}

MessageCommand MessageCommand::fromString(String message)
{
  int cmdType = message.toInt();
  message.remove(0, message.indexOf(' ') + 1);
  std::vector<int> args;
  while (message.length() > 0)
  {
    int arg = message.toInt();
    message.remove(0, message.indexOf(' ') + 1);
    args.push_back(arg);
  }
  return MessageCommand(cmdType, args);
}

String MessageCommand::toString()
{
  String result = String(commandId);
  for (int arg : arguments)
  {
    result += " ";
    result += String(arg);
  }
  return result;
}