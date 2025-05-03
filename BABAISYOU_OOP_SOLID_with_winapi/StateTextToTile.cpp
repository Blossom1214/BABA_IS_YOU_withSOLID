#include "StateTextToTile.h"

StateTextToTile::StateTextToTile(RuleType rule):_ruleType(rule)
{
}

TextType StateTextToTile::GetTextType() const
{
    return TextType::State;
}

std::optional<RuleType> StateTextToTile::ToRuleType() const
{
    return _ruleType;
}
