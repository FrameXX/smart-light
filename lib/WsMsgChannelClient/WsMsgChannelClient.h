#pragma once

#include <Report.h>
#include <Arduino.h>
#include <WiFiConnection.h>
#include <ArduinoWebsockets.h>

class WsMsgChannelClient
{
protected:
  typedef std::function<void(String)> MessageCallback;
  WiFiConnection wifiConnection;
  WiFiClientSecure wifiClient;
  websockets::WebsocketsClient websocketClient;
  MessageCallback messageCallback;
  String serverURL;
  bool connected = false;

  WsMsgChannelClient(WiFiConnection &wifiConnection,
                     WiFiClientSecure &wifiClient,
                     websockets::WebsocketsClient &websocketClient,
                     MessageCallback messageCallback,
                     String serverURL);

  void connect();

  void disconnect();

public:
  virtual void sendMessage(String message) = 0;

  virtual void keepAlive() = 0;

  virtual void pollMessages() = 0;
};