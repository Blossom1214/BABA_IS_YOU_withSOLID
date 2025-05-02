#pragma once
#include "NounTextToTile.h"
#include "NounType.h"
class NounText_BABA final :public ObjectTextToTile
{
public:
	NounText_BABA() = default;
	virtual ~NounText_BABA() override = default;
	virtual NounType GetLinkedObjectType() const override;
	virtual void Render()override;

};

