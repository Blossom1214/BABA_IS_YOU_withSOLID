#pragma once
#include <deque>
#include "TileMap.h"
#include "RuleType.h"
class Tile;
class TileObjectBase;
class ObjectManager
{
public:
	void AddObjectAndText();
	std::deque<TileObjectBase*> GetObjectsWithRule(RuleType rule) const;
private:
	Tile* _ObjectTile;
	TileObjectBase* _Object;
	TileMap* _map;
};

