#pragma once
#include "StateTextToTile.h"
#include "RuleType.h"

class WinTextTile final : public StateTextToTile
{
public:
    WinTextTile() = default;
    virtual ~WinTextTile() override = default;

    virtual RuleType GetLinkedRule() const override;

    virtual void Render() override;
};
