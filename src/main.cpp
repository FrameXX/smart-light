#include <Pin.h>
#include <LightEmittingDiode.h>
#include <IlluminanceSensor.h>
#include <AdaptiveLED.h>
#include <Report.h>
#include <Ticker.h>

Pin LEDSupplyPin(5);
Pin IlluminanceSensorSupplyPin(16);
Pin IlluminanceSensorAnalogPin(A0);
LightEmittingDiode lightEmittingDiode(LEDSupplyPin);
IlluminanceSensor
    illuminanceSensor(IlluminanceSensorSupplyPin, IlluminanceSensorAnalogPin);
AdaptiveLED adaptiveLED(lightEmittingDiode, illuminanceSensor, 10);

void updateAdaptiveLed()
{
  adaptiveLED.update();
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