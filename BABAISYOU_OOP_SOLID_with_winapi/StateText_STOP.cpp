#include "StateText_STOP.h"
#include <iostream>
RuleType StateText_STOP::GetLinkedRule() const
{
	return RuleType::STOP;
}
void StateText_STOP::Render()
{
	std::cout << "TEXT_STOP";
}
