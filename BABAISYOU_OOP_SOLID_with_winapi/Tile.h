#pragma once
#include "TileBackGroundType.h"
#include "Position.h"
#include "ObjectType.h"
class Tile abstract
{
private:
	Tile();
public:
	virtual~Tile(){	}
	virtual void Render();
	virtual bool isType(const ObjectType& type) = 0;
protected:
	Tiletype TileBakcGroundType_;
	ObjectType ObjectType_;
	Position pos_;
};
