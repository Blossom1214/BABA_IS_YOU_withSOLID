#pragma once
#include "VerbTextToTile.h"
#include "VerbType.h"
class VerbText_IS final :public VerbTextToTile
{
public:
	VerbText_IS() = default;
	virtual ~VerbText_IS() override = default;
	virtual VerbType GetVerbType() const override;
	virtual void Render()override;
};

