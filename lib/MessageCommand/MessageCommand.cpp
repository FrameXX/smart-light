#include <MessageCommand.h>

MessageCommand::MessageCommand(int cmdType, std::vector<int> args) : commandId(cmdType), arguments(args) {}

MessageCommand MessageCommand::fromString(String message)
{
  std::vector argsStr = explode(message, ' ');
  std::vector<int> args;

  for (int i = 0; i < argsStr.size(); i++)
  {
    args.push_back(argsStr[i].toInt());
  }

  const int cmdType = args[0];
  args.erase(args.begin());
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