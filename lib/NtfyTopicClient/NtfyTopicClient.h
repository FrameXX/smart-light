#pragma once

#include <WiFiConnection.h>
#include <ArduinoWebsockets.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WsMsgChannelClient.h>

class NtfyTopicClient : public WsMsgChannelClient
{
private:
  String topic;
  bool busy = false;

  void
  onNewMessage(websockets::WebsocketsMessage message);

  void setupWifiClient();

  void setupWebsocketClient();

  void postMessage(String message);

public:
  NtfyTopicClient(WiFiConnection &wifiConnection, String topic, MessageCallback messageCallback);

  void sendMessage(String message);

  void keepAlive();

  void pollMessages();
};