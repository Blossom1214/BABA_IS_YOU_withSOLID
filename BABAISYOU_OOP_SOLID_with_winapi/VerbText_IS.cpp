#include "VerbText_IS.h"
#include <iostream>

std::optional<ParsedRule> VerbText_IS::Validate(const std::vector<TextTile*>& chain, size_t index) const
{
    //왜 +1을 하였나 동사의 특성상 오른쪽에는 뭔가 와야하는데
    //체인의 사이즈보다 인덱스가 크거나 같다..? 
    //또는 0이다? 이건 이미 is라는 동사의 특성뿐아니라 모든 동사의 특성에 위배되는 행동이므로 nullopt해주었음
    if (index == 0 || index + 1 >= chain.size())
    {
        return std::nullopt;
    }
    TextTile* subject = chain[index - 1]; //왼쪽이든 위쪽이든 무조건 명사여야함 is의 특성상
    TextTile* value = chain[index + 1]; //오른쪽이나 아래는 둘중하나가 와도 상관없음

    if (auto subopt = subject->ToObjectType()) //내 위나 왼쪽이 명사가 맞다면
    {
        if (auto ruleopt = value->ToRuleType()) //아래나오른쪽에있는게 상태라면?
        {
            return ParsedRule(*subopt, *ruleopt, VerbKind::IS);
        }
        if (auto objopt = value->ToObjectType())//아래나 오른쪽에있는게 명사라면?
        {
            return ParsedRule(*subopt, *objopt, VerbKind::IS);
        }
    }
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
