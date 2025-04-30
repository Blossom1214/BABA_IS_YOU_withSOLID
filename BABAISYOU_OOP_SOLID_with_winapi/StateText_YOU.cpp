#include "StateText_YOU.h"
#include <iostream>
RuleType StateText_YOU::GetLinkedRule() const
{
	return RuleType::YOU;
}

void StateText_YOU::Render()
{
	std::cout << "TEXT_YOU";
}
