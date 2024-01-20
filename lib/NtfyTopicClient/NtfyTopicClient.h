#pragma once

#include <WiFiConnection.h>
#include <ArduinoWebsockets.h>
#include <Arduino.h>
#include <ArduinoJson.h>

class NtfyTopicClient
{
private:
  typedef std::function<void(String)> MessageCallback;
  WiFiConnection wifiConnection;
  WiFiClientSecure wifiClient;
  websockets::WebsocketsClient websocketClient;
  String topic;
  MessageCallback messageCallback;
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
  NtfyTopicClient(WiFiConnection &wifiConnection, String topic, MessageCallback messageCallback);

  void sendMessage(String message);

  void keepAlive();

  void pollMessages();
};