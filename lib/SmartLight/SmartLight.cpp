#include <SmartLight.h>

SmartLight::SmartLight(Pin &RLEDSupply, Pin &GLEDSupply, Pin &BLEDSupply, String ntfyTopic, const char *wifiSSID, const char *wifiPass)
    : RLEDSupply(RLEDSupply),
      GLEDSupply(GLEDSupply),
      BLEDSupply(BLEDSupply),
      wifiConnection(wifiSSID, wifiPass),
      channel(wifiConnection, ntfyTopic, [this](String message)
              { this->resolveMessage(message); }),
      wifiConnectionKeepAliveTicker([this]()
                                    { this->wifiConnection.keepAlive(); },
                                    10000),
      channelKeepAliveTicker([this]()
                             { this->channel.keepAlive(); },
                             5000),
      channelPollingTicker([this]()
                           { this->channel.pollMessages(); },
                           200)
{
  this->wifiConnectionKeepAliveTicker.start();
  this->channelKeepAliveTicker.start();
  this->channelPollingTicker.start();

  this->enable();
}

void SmartLight::disable()
{
  this->state.enabled = false;
  this->RLEDSupply.modulate(0);
  this->GLEDSupply.modulate(0);
  this->BLEDSupply.modulate(0);
}

void SmartLight::enable()
{
  this->state.enabled = true;
  this->applyRGBDutyCycles();
}

void SmartLight::applyRGBDutyCycles()
{
  if (!this->state.enabled)
    return;
  this->RLEDSupply.modulate(this->state.RDutyCycle);
  this->GLEDSupply.modulate(this->state.GDutyCycle);
  this->BLEDSupply.modulate(this->state.BDutyCycle);
}

void SmartLight::sendState()
{
  const MessageCommand state = this->state.toMessageCommand();
  const String message = state.toString();
  this->channel.sendMessage(message);
}

void SmartLight::loadState(std::vector<int> arguments)
{
  const int argumentsCount = arguments.size();
  reportValue(argumentsCount, "load state command argument count");
  if (argumentsCount != 4)
  {
    report("invalid count of arguments of load state command!");
    return;
  }

  if (arguments[0] == 0)
  {
    this->state.enabled = false;
    this->disable();
  }
  else
  {
    this->state.enabled = true;
    this->enable();
  }

  this->state.RDutyCycle = arguments[1];
  this->state.GDutyCycle = arguments[2];
  this->state.BDutyCycle = arguments[3];

  this->applyRGBDutyCycles();
}

void SmartLight::resolveCommand(MessageCommand command)
{
  report("resolving command");
  const int commandId = command.commandId;
  reportValue(commandId, "command id");
  switch (commandId)
  {
  case 0:
    this->sendState();
    break;
  case 2:
    this->loadState(command.arguments);
  default:
    report("unknown command id?");
    break;
  }
}

void SmartLight::resolveMessage(String message)
{
  report("new message in channel");
  reportValue(message, "message");
  MessageCommand command = MessageCommand::fromString(message);
  this->resolveCommand(command);
}

void SmartLight::updateTickers()
{
  this->wifiConnectionKeepAliveTicker.update();
  this->channelKeepAliveTicker.update();
  this->channelPollingTicker.update();
}

void SmartLight::update()
{
  this->updateTickers();
}