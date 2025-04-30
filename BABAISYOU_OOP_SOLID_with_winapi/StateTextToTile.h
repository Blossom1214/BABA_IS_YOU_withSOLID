#pragma once
#include "TextTile.h"
#include "RuleType.h"
class StateTextToTile :public TextTile
{
	virtual RuleType GetLinkedRule() const = 0;

	virtual TextType GetTextType() const override final;
};

