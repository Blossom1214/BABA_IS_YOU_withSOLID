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
    Tile* GetTile() const noexcept { return tile_; } //�ش���ġ�� Ÿ���� ������������..
    void SetTile(Tile* tile) noexcept { tile_ = tile; }//�ش���ġ�� Ÿ���� �����ϱ�����...
    void SetterFlag(std::shared_ptr<NotifyFlag> Flag) { _Flag = std::move(Flag); }//�̵�����


    virtual void AddRule(RuleType rule) = 0;
    virtual void RemoveRule(RuleType rule) = 0;
    virtual void ClearRules() = 0;
    virtual bool HasRule(RuleType rule) const = 0;

private:
    Tile* tile_ = nullptr;
    std::shared_ptr<NotifyFlag> _Flag;
};