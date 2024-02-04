#include <WsMsgChannelClient.h>

WsMsgChannelClient::WsMsgChannelClient(WiFiConnection &wifiConnection,
                                       WiFiClientSecure &wifiClient,
                                       websockets::WebsocketsClient &websocketClient,
                                       MessageCallback messageCallback,
                                       String serverURL) : wifiConnection(wifiConnection),
                                                           wifiClient(wifiClient),
                                                           websocketClient(websocketClient),
                                                           messageCallback(messageCallback),
                                                           serverURL(serverURL)
{
}

void WsMsgChannelClient::connect()
{
  report("trying to connect to channel");
  if (!this->wifiConnection.getConnected())
    return;
  this->connected = this->websocketClient.connect(this->serverURL);
}

void WsMsgChannelClient::disconnect()
{
  report("disconnecting from channel");
  this->websocketClient.close();
  this->connected = false;
}