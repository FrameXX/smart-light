#include <WiFiConnection.h>

WiFiConnection::WiFiConnection(const char *SSID, const char *password) : SSID(SSID), password(password)
{
  this->connect();
}

void WiFiConnection::connect()
{
  WiFi.begin(this->SSID, this->password);
}

bool WiFiConnection::getConnected()
{
  const bool connected = WiFi.status() == WL_CONNECTED;
  return connected;
}

void WiFiConnection::keepAlive()
{
  const bool connected = this->getConnected();
  reportValue(connected, "wifi");
  if (connected)
    return;
  this->connect();
}

void WiFiConnection::resolveEvent(WiFiEvent_t event)
{
}