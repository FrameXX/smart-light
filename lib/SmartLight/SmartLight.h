#pragma once

#include <Pin.h>
#include <IlluminanceSensor.h>
#include <IlluminanceModulatedSupply.h>
#include <WiFiConnection.h>
#include <NtfyTopicClient.h>
#include <Arduino.h>
#include <Ticker.h>

class SmartLight
{
private:
  bool enabled = true;

  Pin LEDSupplyPin;
  Pin IlluminanceSensorSupplyPin;
  Pin IlluminanceSensorAnalogPin;
  IlluminanceSensor illuminanceSensor;
  IlluminanceModulatedSupply LEDSupply;
  WiFiConnection wifiConnection;
  NtfyTopicClient channel;
  Ticker adaptiveLEDTicker;
  Ticker wifiConnectionKeepAliveTicker;
  Ticker channelKeepAliveTicker;
  Ticker channelPollingTicker;

  void updateTickers();

  void resolveMessage(String message);

public:
  SmartLight(Pin &LEDSupplyPin, Pin &IlluminanceSensorSupplyPin, Pin &IlluminanceSensorAnalogPin, String ntfyTopic, const char *wifiSSID, const char *wifiPass);

  void update();
};