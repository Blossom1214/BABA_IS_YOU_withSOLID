#pragma once
#include "Tile.h"
#include "ObjectRole.h"
class ObjectTile :public Tile
{
public:
	void SetTile(ObjectType type)override; //텍스트가 아니라면 object로 넣음..
protected:
};

