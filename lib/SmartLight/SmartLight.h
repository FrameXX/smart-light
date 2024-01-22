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
#include <RGBLight.h>
#include <RGB.h>

class SmartLight
{
private:
  SmartLightState state = SmartLightState();
  WiFiConnection wifiConnection;
  NtfyTopicClient channel;
  Ticker wifiConnectionKeepAliveTicker;
  Ticker channelKeepAliveTicker;
  Ticker channelPollingTicker;
  RGBLight colorLight;

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