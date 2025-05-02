#pragma once
#include "NounTextToTile.h"
#include "NounType.h"
class NounText_ROCK final : public ObjectTextToTile
{
public:
	NounText_ROCK() = default;
	virtual ~NounText_ROCK() override = default;
	virtual NounType GetLinkedObjectType() const override;
	virtual void Render()override;

};

