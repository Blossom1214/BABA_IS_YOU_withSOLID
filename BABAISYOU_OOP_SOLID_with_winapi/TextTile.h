#pragma once
#include "TileObjectBase.h"
#include "RuleType.h"
#include "TextType.h"
#include <unordered_set>
class TextTile : public TileObjectBase
{
public:
    TextTile();
	virtual ~TextTile() override;

    virtual void Render() override;
    virtual void AddRule(RuleType rule);
    virtual void RemoveRule(RuleType rule);
    virtual void ClearRules();
    virtual bool HasRule(RuleType rule) const;
    virtual TextType GetTextType() const = 0;
protected:
    std::unordered_set<RuleType> activeRules_;

};
