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

    void AddObject(TileObjectBase* obj)noexcept;//오브젝트추가
    void RemoveObject(TileObjectBase* obj);//오브젝트 빼기
    const Position& GetPosition()const; //타일의 위치얻기
    const std::deque<TileObjectBase*>& GetObjects() const; //쌓여있는 오브젝트덱을 받아오기
    bool Contains(TileObjectBase* obj) const;//그안에 내가 원하는 오브젝트타일이 있는가?!
protected:
    TileType tileBackGroundType_;
    Position pos_;
    std::deque<TileObjectBase*> objectList_;
};
