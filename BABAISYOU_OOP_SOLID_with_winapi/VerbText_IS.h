#pragma once
#include "VerbTextToTile.h"
#include "VerbType.h"
class VerbText_IS final :public VerbTextToTile
{
public:
	VerbText_IS():VerbTextToTile(VerbKind::IS){}
	virtual ~VerbText_IS() override = default;
	virtual std::optional<ParsedRule> Validate(const TextTile* subject, const TextTile* value) const override;
	virtual VerbType GetVerbType() const override;
	virtual void Render()override;
};

