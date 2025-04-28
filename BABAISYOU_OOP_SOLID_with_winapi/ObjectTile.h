#pragma once
#include "Tile.h"
class ObjectTile :public Tile
{
public:
	bool isType(const ObjectType& type)override;
protected:
	
};

