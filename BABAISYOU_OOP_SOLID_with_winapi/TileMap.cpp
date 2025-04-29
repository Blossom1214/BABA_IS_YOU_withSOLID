#include "TileMap.h"

void TileMap::RenderMap(Tile* tile)
{
	_map = new std::vector<std::vector<Tile*>>(_Height, std::vector<Tile*>(_Width));

}

bool TileMap::Isinside(const Position& pos) const
{
	return pos.s_x >= 0 && pos.s_x < _Width && pos.s_y >= 0 && pos.s_y < _Height;
}
