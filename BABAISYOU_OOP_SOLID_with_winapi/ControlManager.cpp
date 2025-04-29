#include "ControlManager.h"
#include "Movement.h"
#include "TileMap.h"
ControlManager::ControlManager(ObjectManager* objectManager) :_objectManager(objectManager)
{
}

void ControlManager::Update()
{
}

void ControlManager::TryMove(TileObjectBase* obj, Direction dir)
{
	
	if (!obj)
		return;
	Tile* currentTile = obj->GetTile();
	if (!currentTile)
		return;
	Position currentPos=currentTile->GetPosition();
	Position vec = Movement::Vector(dir);
	bool Moved = false;

	Position nextPos = currentPos + vec;
	if (!_map->Isinside(nextPos))
		return;
	Tile* nextTile = _map->GetTile(nextPos);
	if (!nextTile)
		return;
}
