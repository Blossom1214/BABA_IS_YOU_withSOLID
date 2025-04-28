#pragma once
#include "TileBackGroundType.h"
#include "Position.h"
#include "ObjectType.h"
#include <vector>
class Tile abstract
{
private:
	Tile();
public:
	virtual~Tile(){	}
	virtual void Render();
private:
	void SetTile(ObjectType type);
protected:
	Tiletype TileBakcGroundType_;
	Position pos_;
private:
	std::vector<ObjectType> ObjectType_;
	
};
