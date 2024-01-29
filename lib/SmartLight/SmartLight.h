#pragma once

#include <Pin.h>
#include <IlluminanceSensor.h>
#include <IlluminanceModulatedSupply.h>
#include <WiFiConnection.h>
#include <NtfyTopicClient.h>
#include <Arduino.h>
#include <Ticker.h>
#include <MsgCmd.h>
#include <SmartLightState.h>
#include <RGB.h>
#include <RGBLight.h>
#include <HueAnimation.h>

class SmartLight
{
private:
  SmartLightState state = SmartLightState();
  WiFiConnection wifiConnection;
  NtfyTopicClient channel;
  RGBLight colorLight;
  HueAnimation hueAnimation = HueAnimation(this->colorLight, this->state.hueAnimationIntervalMs);
  Ticker wifiConnectionKeepAliveTicker = Ticker([this]()
                                                { this->wifiConnection.keepAlive(); },
                                                10000);
  Ticker channelKeepAliveTicker = Ticker([this]()
                                         { this->channel.keepAlive(); },
                                         5000);
  Ticker channelPollingTicker = Ticker([this]()
                                       { this->channel.pollMessages(); },
                                       200);
  Ticker hueAnimationTicker = Ticker([this]()
                                     { this->hueAnimation.update(); },
                                     25);

  void updateTickers();

  void resolveMessage(String message);

  void resolveCommand(MsgCmd command);

  void sendState();

  void applyRGBDutyCycles();

  void disable();

  void enable();

  void disableHueAnimation();

  void enableHueAnimation();

  void loadState(std::vector<int> arguments);

public:
  SmartLight(Pin &RLEDSupply, Pin &GLEDSupply, Pin &BLEDSupply, String ntfyTopic, const char *wifiSSID, const char *wifiPass);

  void update();
};