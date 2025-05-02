#include "VerbText_IS.h"
#include <iostream>

VerbType VerbText_IS::GetVerbType() const
{
    return VerbType::TEXT_IS;
}

void VerbText_IS::Render()
{
    std::cout << "TEXT_IS";
}
