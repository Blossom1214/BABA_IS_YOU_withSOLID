#pragma once
#include "TileObjectBase.h"
#include "RuleType.h"
#include "TextType.h"
#include "ObjectType.h"
#include "VerbKind.h"
#include <unordered_set>
#include <optional>
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
    virtual std::optional<ObjectType> ToObjectType() const{ return std::nullopt; }
    virtual std::optional<RuleType> ToRuleType() const{ return std::nullopt; }
    virtual std::optional<VerbKind> ToVerbKind() const{ return std::nullopt; }
protected:
    std::unordered_set<RuleType> activeRules_;

};
