#pragma once

#include <WiFiConnection.h>
#include <ArduinoWebsockets.h>
#include <Arduino.h>
#include <Report.h>

class NtfyTopicClient
{
private:
  WiFiConnection wifiConnection;
  WiFiClientSecure wifiClient;
  websockets::WebsocketsClient websocketClient;
  String topic;
  String serverURL;
  bool connected = false;
  bool dispatcher = false;

  void
  onNewMessage(websockets::WebsocketsMessage message);

  void setupWifiClient();

  void setupWebsocketClient();

  void connect();

  void disconnect();

  void postMessage(String message);

public:
  NtfyTopicClient(WiFiConnection wifiConnection, String topic);

  void sendMessage(String message);

  void keepAlive();

  void pollMessages();
};