#include <Pin.h>
#include <Report.h>
#include <WiFiCredentials.h>
#include <SmartLight.h>
#include <RGB.h>
#include <WiFi.h>

#define DEBUG true

void setup()
{
  initSerial(115200);
  report("Serial initiated.");
  if (DEBUG)
  {
    report("3s delay...");
    delay(3000);
    report("start");
  }

  Pin RLEDSupply(16);
  Pin GLEDSupply(5);
  Pin BLEDSupply(4);

  SmartLight light(RLEDSupply, GLEDSupply, BLEDSupply, "smart-light-channel", WIFI_SSID, WIFI_PASS);

  report("setup done");
  while (true)
  {
    delay(50);
    light.update();
  }
}

void loop()
{
}