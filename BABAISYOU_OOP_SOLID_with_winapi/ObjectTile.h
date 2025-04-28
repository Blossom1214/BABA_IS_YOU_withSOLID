#pragma once
#include "Tile.h"
#include "ObjectRole.h"
class ObjectTile :public Tile
{
public:
	void CheckPosObjectType();
	void Render()override;
protected:
};

