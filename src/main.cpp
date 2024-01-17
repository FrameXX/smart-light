#include <Pin.h>
#include <IlluminanceSensor.h>
#include <Report.h>
#include <Ticker.h>
#include <IlluminanceModulatedSupply.h>
#include <WifiCredentials.h>
#include <WiFiConnection.h>

Pin LEDSupplyPin(5);
Pin IlluminanceSensorSupplyPin(16);
Pin IlluminanceSensorAnalogPin(A0);
IlluminanceSensor
    illuminanceSensor(IlluminanceSensorSupplyPin, IlluminanceSensorAnalogPin);
IlluminanceModulatedSupply LEDSupply(LEDSupplyPin, illuminanceSensor, 10);
WiFiConnection wifi(WIFI_SSID, WIFI_PASS);

void updateAdaptiveLed()
{
  LEDSupply.update();
}

Ticker adaptiveLEDTIcker(updateAdaptiveLed, 25);

void updateTickers()
{
  adaptiveLEDTIcker.update();
}

void initTickers()
{
  adaptiveLEDTIcker.start();
}

void setup()
{
  initSerial();
  report("Serial initiated.");
  initTickers();
}

void loop()
{
  updateTickers();
}