#pragma once
class Tile;
class TileObjectBase;
class ObjectManager
{
public:
	void AddObjectAndText();
	
private:
	Tile* _ObjectTile;
	TileObjectBase* _Object;

};

