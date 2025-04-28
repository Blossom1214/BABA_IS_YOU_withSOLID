#include "Tile.h"


const std::vector<ObjectType*>& Tile::GetObjectTypes() const
{
	return ObjectType_list;
}

void Tile::AddObject(ObjectType* obj)
{
	ObjectType_list.push_back(obj);
}

void Tile::RemoveObject(ObjectType* obj)
{
	std::erase(ObjectType_list, obj);
}

