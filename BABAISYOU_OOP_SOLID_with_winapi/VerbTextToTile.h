#pragma once
#include "GrammerManager.h"
#include "TextTile.h"
#include "VerbType.h"
#include "VerbKind.h"
#include "ParsedRule.h"
class VerbTextToTile : public TextTile
{
public:
    VerbTextToTile(VerbKind verb);
    virtual VerbType GetVerbType() const = 0;
    virtual std::optional<ParsedRule> Validate(const TextTile* subject, const TextTile* value) const = 0;
    virtual TextType GetTextType() const override final;
    std::optional<VerbKind> ToVerbKind() const override;

private:
    VerbKind _verbKind;
};

