#pragma once
#include "Position.h"
#include <vector>
class Tile;
class TileMap
{
public:
	void RenderMap(Tile* tile);
	bool Isinside(const Position& pos)const;
	Tile* GetTile(const Position& pos);
	const int& GetHeight()const;
	const int& GetWidth()const;
private:
	int _Height;
	int _Width;
	std::vector<std::vector<Tile*>>* _map;
};

