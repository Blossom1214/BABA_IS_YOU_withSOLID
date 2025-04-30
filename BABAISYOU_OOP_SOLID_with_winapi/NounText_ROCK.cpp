#include "NounText_ROCK.h"
#include <iostream>
NounType NounText_ROCK::GetLinkedObjectType() const
{
    return NounType::ROCK;
}

void NounText_ROCK::Render()
{
    std::cout << "TEXT_ROCK";
}
