#include <SmartLightState.h>

SmartLightState::SmartLightState() {}

MsgCmd SmartLightState::toMsgCmd() const
{
  const MsgCmd state(1,
                             {int(this->enabled),
                              int(this->RDutyCycle),
                              int(this->GDutyCycle),
                              int(this->BDutyCycle),
                              int(this->hueAnimationEnabled),
                              this->hueAnimationIntervalMs});
  return state;
}