#pragma once
#include <WiFiConnection.h>
#include <ArduinoWebsockets.h>

class NtfyClient
{
private:
  WiFiConnection wifiConnection;
  WiFiClientSecure wifiClient;
  websockets::WebsocketsClient websocketClient;
  const char *topic;
  const char *wsServer;

  void onNewMessage(websockets::WebsocketsMessage message);

public:
  NtfyClient(WiFiConnection wifiConnection, const char *topic);

  void connect();

  void disconnect();

  void sendMessage(const char *message);
};