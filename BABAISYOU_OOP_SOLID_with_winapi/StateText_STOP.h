#pragma once
#include "StateTextToTile.h"
#include "RuleType.h"
class StateText_STOP final :public StateTextToTile
{
public:
	StateText_STOP() = default;
	virtual ~StateText_STOP() override = default;
	virtual RuleType GetLinkedRule() const override;
	virtual void Render()override;

};