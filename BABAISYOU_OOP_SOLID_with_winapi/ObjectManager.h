//#pragma once
//#include <deque>
//#include "RuleType.h"
//#include "Position.h"
//
//class Tile;
//class TileMap;
//class TileObjectBase;
//
//class ObjectManager
//{
//public:
//	void AddObjectAndText();
//	void RemoveObj();
//	std::deque<TileObjectBase*> GetObjectsWithRule(RuleType rule) const;
//private:
//	Tile* _ObjectTile;
//	TileObjectBase* _Object;
//	TileMap* _map;
//};
//
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

private:
    TileMap* _map;
};
