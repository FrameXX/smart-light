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
  this->stepTimeMs = static_cast<float>(this->intervalMs) / 768.0;
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
  case PhaseBlueDown:
    this->phase = PhaseGreenUp;
    break;
  default:
    report("invalid HueAnimation phase!");
    return;
  }
}

void HueAnimation::update()
{
  const int millisDiff = millis() - this->lastMillis;
  this->updateLastMillis();

  const float step = static_cast<float>(millisDiff) / this->stepTimeMs;

  switch (this->phase)
  {
  case PhaseGreenUp:
    this->currentColor.addG(step);
    this->currentColor.subtractB(step);
    if (this->currentColor.getG() >= 128)
      this->nextPhase();
    break;
  case PhaseRedDown:
    this->currentColor.subtractR(step);
    this->currentColor.addG(step);
    if (this->currentColor.getR() < 128)
      this->nextPhase();
    break;
  case PhaseBlueUp:
    this->currentColor.addB(step);
    this->currentColor.subtractR(step);
    if (this->currentColor.getB() >= 128)
      this->nextPhase();
    break;
  case PhaseGreenDown:
    this->currentColor.subtractG(step);
    this->currentColor.addB(step);
    if (this->currentColor.getG() < 128)
      this->nextPhase();
    break;
  case PhaseRedUp:
    this->currentColor.addR(step);
    this->currentColor.subtractG(step);
    if (this->currentColor.getR() >= 128)
      this->nextPhase();
    break;
  case PhaseBlueDown:
    this->currentColor.subtractB(step);
    this->currentColor.addR(step);
    if (this->currentColor.getB() < 128)
      this->nextPhase();
    break;
  default:
    report("invalid HueAnimation phase!");
    return;
  }

  this->light.setColor(this->currentColor);
}