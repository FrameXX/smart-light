#include <SmartLightState.h>

SmartLightState::SmartLightState() {}

MessageCommand SmartLightState::toMessageCommand() const
{
  const MessageCommand state(1,
                             {
                                 int(this->enabled),
                                 int(this->RDutyCycle),
                                 int(this->GDutyCycle),
                                 int(this->BDutyCycle),
                             });
  return state;
}