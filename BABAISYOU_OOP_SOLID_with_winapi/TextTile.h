#pragma once
#include "TileObjectBase.h"
#include <unordered_set>
class TextTile : public TileObjectBase
{
public:
    TextTile();
	virtual ~TextTile() override;

    virtual void Render() override;
    void AddRule(RuleType rule);
    void RemoveRule(RuleType rule);
    void ClearRules();
    bool HasRule(RuleType rule) const;
protected:
    std::unordered_set<RuleType> activeRules_;

};
