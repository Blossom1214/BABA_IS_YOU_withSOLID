#include "VerbText_IS.h"
#include <iostream>

std::optional<ParsedRule> VerbText_IS::Validate(const TextTile* subject, const TextTile* value) const
{
    auto sub = subject->ToObjectType();
    if (!sub) return std::nullopt;

    if (auto rule = value->ToRuleType())
        return ParsedRule{ *sub, *rule, VerbKind::IS };
    else if (auto obj = value->ToObjectType())
        return ParsedRule{ *sub, *obj, VerbKind::IS };

    return std::nullopt;
}


VerbType VerbText_IS::GetVerbType() const
{
    return VerbType::TEXT_IS;
}

void VerbText_IS::Render()
{
    std::cout << "TEXT_IS";
}
