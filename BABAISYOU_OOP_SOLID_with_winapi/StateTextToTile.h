#pragma once
#include "TextTile.h"
#include "RuleType.h"
class StateTextToTile :public TextTile
{
public:
	StateTextToTile(RuleType rule);
	virtual RuleType GetLinkedRule() const = 0;

	virtual TextType GetTextType() const override final;
	std::optional<RuleType> ToRuleType() const override;
private:
	RuleType _ruleType;
};

