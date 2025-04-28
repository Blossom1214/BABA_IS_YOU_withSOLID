#include "TileMap.h"

void TileMap::RenderMap(Tile* tile)
{
	_map = new std::vector<std::vector<Tile*>>(_Height, std::vector<Tile*>(_Width));

}
