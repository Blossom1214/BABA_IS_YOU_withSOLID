#include "StateText_WIN.h"
#include<iostream>
RuleType WinTextTile::GetLinkedRule() const
{
    return RuleType::WIN;
}
void WinTextTile::Render()
{
    std::cout << "WIN";
}