#include <NtfyClient.h>
#include <WiFiConnection.h>
#include <ArduinoWebsockets.h>

NtfyClient::NtfyClient(WiFiConnection wifiConnection, const char *topic) : wifiConnection(wifiConnection), topic(topic)
{
  WiFiClientSecure wifiClient;
  this->wifiClient = wifiClient;
  this->wifiClient.setInsecure();

  websockets::WebsocketsClient websocketClient;
  this->websocketClient = websocketClient;
  this->websocketClient.setInsecure();
  this->websocketClient.onMessage([this](const websockets::WebsocketsMessage &message)
                                  { this->onNewMessage(message); });
}

void NtfyClient::connect()
{
}

void NtfyClient::disconnect()
{
}

void NtfyClient::onNewMessage(websockets::WebsocketsMessage message)
{
}