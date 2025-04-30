#include "NounText_BABA.h"
#include <iostream>
NounType NounText_BABA::GetLinkedObjectType() const
{
    return NounType::BABA;
}

void NounText_BABA::Render()
{
    std::cout << "TEXT_BABA";

}
