#pragma once
#include "StateTextToTile.h"
#include "RuleType.h"
class StateText_PUSH final :public StateTextToTile
{
public:
	StateText_PUSH() = default;
	virtual ~StateText_PUSH() override = default;
	virtual RuleType GetLinkedRule() const override;
	virtual void Render()override;

};

