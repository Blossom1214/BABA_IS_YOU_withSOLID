#pragma once
#include "RuleType.h"
#include "NotifyFlag.h"
#include <memory>
class Tile;
class TileObjectBase
{
public:
    virtual ~TileObjectBase() = default;

    virtual void Render() = 0;
    Tile* GetTile() const noexcept { return tile_; } //해당위치의 타일을 가져오기위함..
    void SetTile(Tile* tile) noexcept { tile_ = tile; }//해당위치의 타일을 셋팅하기위함...
    void SetterFlag(std::shared_ptr<NotifyFlag> Flag) { _Flag = std::move(Flag); }//이동생성


    virtual void AddRule(RuleType rule) = 0;
    virtual void RemoveRule(RuleType rule) = 0;
    virtual void ClearRules() = 0;
    virtual bool HasRule(RuleType rule) const = 0;

private:
    Tile* tile_ = nullptr;
    std::shared_ptr<NotifyFlag> _Flag;
};