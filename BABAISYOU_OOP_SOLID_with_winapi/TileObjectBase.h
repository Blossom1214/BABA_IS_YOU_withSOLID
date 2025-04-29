#pragma once
class Tile;
class TileObjectBase
{
public:
    virtual ~TileObjectBase() = default;

    virtual void Render() = 0;
    Tile* GetTile() const noexcept { return tile_; } //�ش���ġ�� Ÿ���� ������������..
    void SetTile(Tile* tile) noexcept { tile_ = tile; }//�ش���ġ�� Ÿ���� �����ϱ�����...
private:
    Tile* tile_ = nullptr;
};