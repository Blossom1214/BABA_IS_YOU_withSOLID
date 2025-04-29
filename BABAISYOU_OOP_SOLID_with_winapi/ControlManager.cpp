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
	Tile* currentTile = obj->GetTile(); //현재위치
	if (!currentTile)
		return;
	Position currentPos=currentTile->GetPosition();
	Position vec = Movement::Vector(dir);
	Position nextPos = currentPos + vec;//다음칸
	if (!_map||!_map->Isinside(nextPos))
		return;
	Tile* nextTile = _map->GetTile(nextPos);
	if (!nextTile)
		return;
	const std::deque<TileObjectBase*>& objectsInNextTile = nextTile->GetObjects();
	for (TileObjectBase* objInNextTile : objectsInNextTile) //밀수있어?!
	{

	}
	//실제로 밀기!
	currentTile->RemoveObject(obj); 
	nextTile->AddObject(obj);
	obj->SetTile(nextTile);

}
