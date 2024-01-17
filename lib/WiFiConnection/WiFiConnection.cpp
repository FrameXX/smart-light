#include <WiFiConnection.h>
#include <ESP8266WiFi.h>

WiFiConnection::WiFiConnection(const char *SSID, const char *password)
{
  WiFi.begin(SSID, password);
}

void WiFiConnection::connect()
{
  WiFi.begin(this->SSID, this->password);
}

bool WiFiConnection::inquireConnection()
{
  const bool connected = WiFi.status() == WL_CONNECTED;
  if (!connected)
    this->connect();
  return connected;
}