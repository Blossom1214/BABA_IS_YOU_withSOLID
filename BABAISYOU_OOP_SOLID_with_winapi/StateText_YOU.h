#pragma once
#include "StateTextToTile.h"
#include "RuleType.h"
class StateText_YOU final :public StateTextToTile
{
public:
	StateText_YOU()=default;
	virtual ~StateText_YOU()override =default;
	virtual RuleType GetLinkedRule() const override;
	virtual void Render()override;
};