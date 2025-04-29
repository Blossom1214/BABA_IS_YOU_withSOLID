#pragma once
#include <deque>
#include "RuleType.h"
#include "Position.h"
class Tile;
class TileMap;
class TileObjectBase;
class ObjectManager
{
public:
    ObjectManager(TileMap* map);

    void AddObject(TileObjectBase* obj);
    void RemoveObject(TileObjectBase* obj);
    std::deque<TileObjectBase*> GetObjectsWithRule(RuleType rule) const;
    Tile* GetTile(const Position& pos) const;
private:
    TileMap* _map;
};
