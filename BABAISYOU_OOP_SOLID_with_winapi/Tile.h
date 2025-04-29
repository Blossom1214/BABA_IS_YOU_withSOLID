#pragma once
#include "TileBackGroundType.h"
#include "Position.h"
#include "TileObjectBase.h"
#include <deque>

class Tile
{
private:
   explicit Tile();
public:
    virtual ~Tile() = default;
    virtual void Render() = 0;


    void AddObject(TileObjectBase* obj);
    void RemoveObject(TileObjectBase* obj);
    const Position& GetPosition()const;
protected:
    TileType tileBackGroundType_;
    Position pos_;
    std::deque<TileObjectBase*> objectList_;
};
