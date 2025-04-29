#pragma once
#include "TileObjectBase.h"
#include "RuleType.h"
#include <unordered_set>
class ObjectTile : public TileObjectBase
{
public:
    ObjectTile();
    virtual ~ObjectTile() override;

    virtual void Render() override;
    virtual void AddRule(RuleType rule)override;
    virtual void RemoveRule(RuleType rule)override;
    virtual void ClearRules()override;
    virtual bool HasRule(RuleType rule) const override;

protected:
    std::unordered_set<RuleType> activeRules_;
};