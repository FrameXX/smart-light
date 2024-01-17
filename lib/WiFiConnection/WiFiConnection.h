#pragma once

class WiFiConnection
{
private:
  const char *SSID;
  const char *password;

  void connect();

public:
  WiFiConnection(const char *SSID, const char *password);

  bool inquireConnection();
};