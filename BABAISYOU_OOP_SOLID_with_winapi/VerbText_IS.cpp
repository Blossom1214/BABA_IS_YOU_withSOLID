#include "VerbText_IS.h"
#include <iostream>

std::optional<ParsedRule> VerbText_IS::Validate(const std::vector<TextTile*>& chain, size_t index) const
{
    //�� +1�� �Ͽ��� ������ Ư���� �����ʿ��� ���� �;��ϴµ�
    //ü���� ������� �ε����� ũ�ų� ����..? 
    //�Ǵ� 0�̴�? �̰� �̹� is��� ������ Ư���Ӿƴ϶� ��� ������ Ư���� ����Ǵ� �ൿ�̹Ƿ� nullopt���־���
    if (index == 0 || index + 1 >= chain.size())
    {
        return std::nullopt;
    }
    TextTile* subject = chain[index - 1]; //�����̵� �����̵� ������ ��翩���� is�� Ư����
    TextTile* value = chain[index + 1]; //�������̳� �Ʒ��� �����ϳ��� �͵� �������

    if (auto subopt = subject->ToObjectType()) //�� ���� ������ ��簡 �´ٸ�
    {
        if (auto ruleopt = value->ToRuleType()) //�Ʒ��������ʿ��ִ°� ���¶��?
        {
            return ParsedRule(*subopt, *ruleopt, VerbKind::IS);
        }
        if (auto objopt = value->ToObjectType())//�Ʒ��� �����ʿ��ִ°� �����?
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
