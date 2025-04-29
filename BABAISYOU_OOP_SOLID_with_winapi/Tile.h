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

    void AddObject(TileObjectBase* obj)noexcept;//������Ʈ�߰�
    void RemoveObject(TileObjectBase* obj);//������Ʈ ����
    const Position& GetPosition()const; //Ÿ���� ��ġ���
    const std::deque<TileObjectBase*>& GetObjects() const; //�׿��ִ� ������Ʈ���� �޾ƿ���
    bool Contains(TileObjectBase* obj) const;//�׾ȿ� ���� ���ϴ� ������ƮŸ���� �ִ°�?!
protected:
    TileType tileBackGroundType_;
    Position pos_;
    std::deque<TileObjectBase*> objectList_;
};
