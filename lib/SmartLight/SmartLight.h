#pragma once

#include <Pin.h>
#include <IlluminanceSensor.h>
#include <IlluminanceModulatedSupply.h>
#include <WiFiConnection.h>
#include <NtfyTopicClient.h>
#include <Arduino.h>
#include <Ticker.h>
#include <MessageCommand.h>
#include <SmartLightState.h>

class SmartLight
{
private:
  SmartLightState state = SmartLightState();
  Pin RLEDSupply;
  Pin GLEDSupply;
  Pin BLEDSupply;
  WiFiConnection wifiConnection;
  NtfyTopicClient channel;
  Ticker wifiConnectionKeepAliveTicker;
  Ticker channelKeepAliveTicker;
  Ticker channelPollingTicker;

  void updateTickers();

  void resolveMessage(String message);

  void resolveCommand(MessageCommand command);

  void sendState();

  void applyRGBDutyCycles();

  void disable();

  void enable();

  void loadState(std::vector<int> arguments);

public:
  SmartLight(Pin &RLEDSupply, Pin &GLEDSupply, Pin &BLEDSupply, String ntfyTopic, const char *wifiSSID, const char *wifiPass);

  void update();
};