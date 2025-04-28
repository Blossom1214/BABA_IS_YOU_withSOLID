#pragma once
#include"ObjectTile.h"
class Tile;
class ObjectManager
{
public:
	void AddObject();

private:
	Tile* _ObjectTile;
	ObjectTile _ObjTile;
};

