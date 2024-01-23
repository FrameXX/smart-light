#include <HueAnimation.h>

HueAnimation::HueAnimation(RGBLight &light,
                           int intervalMs) : light(light),
                                             intervalMs(intervalMs)
{
  this->updateLastMillis();
  this->updateStepTimeMs();
  this->light.setColor(this->currentColor);
}

void HueAnimation::updateLastMillis()
{
  this->lastMillis = millis();
}

void HueAnimation::updateStepTimeMs()
{
  this->stepTimeMs = static_cast<float>(this->intervalMs) / 1530.0;
}

void HueAnimation::setInterval(int intervalMs)
{
  this->intervalMs = intervalMs;
  this->updateStepTimeMs();
}

void HueAnimation::nextPhase()
{
  switch (this->phase)
  {
  case PhaseGreenUp:
    this->phase = PhaseRedDown;
    break;
  case PhaseRedDown:
    this->phase = PhaseBlueUp;
    break;
  case PhaseBlueUp:
    this->phase = PhaseGreenDown;
    break;
  case PhaseGreenDown:
    this->phase = PhaseRedUp;
    break;
  case PhaseRedUp:
    this->phase = PhaseBlueDown;
    break;
  default:
    report("invalid HueAnimation phase!");
    return;
  }
}

void HueAnimation::update()
{
  const int millisDiff = millis() - this->lastMillis;
  const float step = static_cast<float>(millisDiff) / this->stepTimeMs;

  switch (this->phase)
  {
  case PhaseGreenUp:
    this->currentColor.setG(this->currentColor.getG() + step);
    if (this->currentColor.getG() == 255)
      this->nextPhase();
    break;
  case PhaseRedDown:
    this->currentColor.setR(this->currentColor.getR() - step);
    if (this->currentColor.getR() == 0)
      this->nextPhase();
    break;
  case PhaseBlueUp:
    this->currentColor.setB(this->currentColor.getB() + step);
    if (this->currentColor.getB() == 255)
      this->nextPhase();
    break;
  case PhaseGreenDown:
    this->currentColor.setG(this->currentColor.getG() - step);
    if (this->currentColor.getG() == 0)
      this->nextPhase();
    break;
  case PhaseRedUp:
    this->currentColor.setR(this->currentColor.getR() + step);
    if (this->currentColor.getR() == 255)
      this->nextPhase();
    break;
  case PhaseBlueDown:
    this->currentColor.setB(this->currentColor.getB() - step);
    if (this->currentColor.getB() == 0)
      this->nextPhase();
    break;
  default:
    report("invalid HueAnimation phase!");
    return;
  }

  this->light.setColor(this->currentColor);
}