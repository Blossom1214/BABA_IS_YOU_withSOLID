#pragma once
#include <vector>
class Tile;
class TileMap
{
public:


private:
	int _Height;
	int _Width;
	std::vector<std::vector<Tile*>>* _map;
};

