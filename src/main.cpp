#include <Pin.h>
#include <IlluminanceSensor.h>
#include <Report.h>
#include <Ticker.h>
#include <IlluminanceModulatedSupply.h>
#include <WifiCredentials.h>
#include <WiFiConnection.h>
#include <NtfyTopicClient.h>

#define DEBUG true

Pin LEDSupplyPin(5);
Pin IlluminanceSensorSupplyPin(16);
Pin IlluminanceSensorAnalogPin(A0);
IlluminanceSensor
    illuminanceSensor(IlluminanceSensorSupplyPin, IlluminanceSensorAnalogPin);
IlluminanceModulatedSupply LEDSupply(LEDSupplyPin, illuminanceSensor, 10);
WiFiConnection wifiConnection(WIFI_SSID, WIFI_PASS);
String ntfyTopic = "esp8266-smart-light";
NtfyTopicClient channel(wifiConnection, ntfyTopic);

Ticker adaptiveLEDTicker([]()
                         { LEDSupply.update(); },
                         25);
Ticker wifiConnectionKeepAliveTicker([]()
                                     { wifiConnection.keepAlive(); },
                                     1000);
Ticker channelKeepAliveTicker([]()
                              { channel.keepAlive(); },
                              1000);
Ticker channelPollingTicker([]()
                            { channel.pollMessages(); },
                            200);

void updateTickers()
{
  adaptiveLEDTicker.update();
  wifiConnectionKeepAliveTicker.update();
  channelKeepAliveTicker.update();
  channelPollingTicker.update();
}

void initTickers()
{
  adaptiveLEDTicker.start();
  wifiConnectionKeepAliveTicker.start();
  channelKeepAliveTicker.start();
  channelPollingTicker.start();
}

void setup()
{
  initSerial();
  report("Serial initiated.");
  if (DEBUG)
  {
    report("3s delay...");
    delay(3000);
    report("start");
  }
  initTickers();
}

void loop()
{
  updateTickers();
}