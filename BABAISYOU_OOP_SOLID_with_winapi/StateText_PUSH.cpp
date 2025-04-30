#include "StateText_PUSH.h"
#include <iostream>
RuleType StateText_PUSH::GetLinkedRule() const
{
    return RuleType::PUSH;
}

void StateText_PUSH::Render()
{
    std::cout << "TEXT_PUSH";
}
