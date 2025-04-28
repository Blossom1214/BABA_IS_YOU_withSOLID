#pragma once
#include "TileBackGroundType.h"
#include "Position.h"
#include "ObjectType.h"
#include <vector>
class Tile abstract
{
public:
	Tile() = default;
	virtual~Tile(){	}
	virtual void Render()=0;
	const std::vector<ObjectType>& GetObjectTypes() const;
	
protected:
	Tiletype TileBakcGroundType_;
	Position pos_;
	std::vector<ObjectType> ObjectType_;
	
};
