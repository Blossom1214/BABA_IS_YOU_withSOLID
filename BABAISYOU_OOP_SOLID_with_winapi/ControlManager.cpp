#include "ControlManager.h"

ControlManager::ControlManager(ObjectManager* objectManager) :objectManager_(objectManager)
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
}
