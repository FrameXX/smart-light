#include <SmartLight.h>

SmartLight::SmartLight(Pin &LEDSupplyPin,
                       Pin &IlluminanceSensorSupplyPin,
                       Pin &IlluminanceSensorAnalogPin,
                       String ntfyTopic,
                       const char *wifiSSID,
                       const char *wifiPass)
    : LEDSupplyPin(LEDSupplyPin),
      IlluminanceSensorSupplyPin(IlluminanceSensorSupplyPin),
      IlluminanceSensorAnalogPin(IlluminanceSensorAnalogPin),
      illuminanceSensor(IlluminanceSensorSupplyPin, IlluminanceSensorAnalogPin),
      LEDSupply(LEDSupplyPin, illuminanceSensor, 10),
      wifiConnection(wifiSSID, wifiPass),
      channel(wifiConnection, ntfyTopic, [this](String message)
              { this->resolveMessage(message); }),
      adaptiveLEDTicker([this]()
                        { this->LEDSupply.update(); },
                        25),
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
  this->adaptiveLEDTicker.start();
  this->wifiConnectionKeepAliveTicker.start();
  this->channelKeepAliveTicker.start();
  this->channelPollingTicker.start();
}

void SmartLight::resolveMessage(String message)
{
  report("new message in channel");
  reportValue(message, "message");
  // MessageCommand command = MessageCommand::fromString(message);
  // reportValue(command.commandId, "command id");
}

void SmartLight::updateTickers()
{
  this->adaptiveLEDTicker.update();
  this->wifiConnectionKeepAliveTicker.update();
  this->channelKeepAliveTicker.update();
  this->channelPollingTicker.update();
}

void SmartLight::update()
{
  this->updateTickers();
}