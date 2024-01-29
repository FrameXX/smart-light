#include <SmartLight.h>

SmartLight::SmartLight(Pin &RLEDSupply, Pin &GLEDSupply, Pin &BLEDSupply, String ntfyTopic, const char *wifiSSID, const char *wifiPass)
    : wifiConnection(wifiSSID, wifiPass),
      channel(wifiConnection, ntfyTopic, [this](String message)
              { this->resolveMessage(message); }),
      colorLight(RLEDSupply, GLEDSupply, BLEDSupply)
{
  this->wifiConnectionKeepAliveTicker.start();
  this->channelKeepAliveTicker.start();
  this->channelPollingTicker.start();
  this->hueAnimationTicker.start();

  this->enable();
}

void SmartLight::disable()
{
  this->state.enabled = false;
  const RGB color(0, 0, 0);
  this->colorLight.setColor(color);
  this->hueAnimationTicker.pause();
}

void SmartLight::enable()
{
  this->state.enabled = true;
  this->applyRGBDutyCycles();
}

void SmartLight::enableHueAnimation()
{
  this->state.hueAnimationEnabled = true;
  if (this->state.enabled)
    this->hueAnimationTicker.resume();
}

void SmartLight::disableHueAnimation()
{
  this->state.hueAnimationEnabled = false;
  this->hueAnimationTicker.pause();
}

void SmartLight::applyRGBDutyCycles()
{
  if (!this->state.enabled)
    return;
  RGB color(this->state.RDutyCycle, this->state.GDutyCycle, this->state.BDutyCycle);
  this->colorLight.setColor(color);
}

void SmartLight::sendState()
{
  const MsgCmd state = this->state.toMsgCmd();
  const String message = state.toString();
  this->channel.sendMessage(message);
}

void SmartLight::loadState(std::vector<int> arguments)
{
  const int argumentsCount = arguments.size();
  reportValue(argumentsCount, "load state command argument count");
  if (argumentsCount != 6)
  {
    report("invalid count of arguments of load state command!");
    return;
  }

  arguments[0] == 0 ? this->disable() : this->enable();

  this->state.RDutyCycle = arguments[1];
  this->state.GDutyCycle = arguments[2];
  this->state.BDutyCycle = arguments[3];

  arguments[4] == 0 ? this->disableHueAnimation() : this->enableHueAnimation();

  this->state.hueAnimationIntervalMs = arguments[5];
  this->hueAnimation.setInterval(arguments[5]);

  this->applyRGBDutyCycles();
}

void SmartLight::resolveCommand(MsgCmd command)
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
  MsgCmd command = MsgCmd::fromString(message);
  this->resolveCommand(command);
}

void SmartLight::updateTickers()
{
  this->wifiConnectionKeepAliveTicker.update();
  this->channelKeepAliveTicker.update();
  this->channelPollingTicker.update();
  this->hueAnimationTicker.update();
}

void SmartLight::update()
{
  this->updateTickers();
}