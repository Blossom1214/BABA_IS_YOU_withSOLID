#pragma once
class Tile;
class TileObjectBase
{
public:
    virtual ~TileObjectBase() = default;

    virtual void Render() = 0;
    Tile* GetTile() const noexcept { return tile_; } //해당위치의 타일을 가져오기위함..
    void SetTile(Tile* tile) noexcept { tile_ = tile; }//해당위치의 타일을 셋팅하기위함...
private:
    Tile* tile_ = nullptr;
};