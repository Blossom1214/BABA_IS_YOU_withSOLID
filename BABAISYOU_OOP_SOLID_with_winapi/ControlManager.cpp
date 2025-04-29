#include "ControlManager.h"
#include "Movement.h"
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
	Position vec = Movement::Vector(dir);
	bool Moved = false;

}
