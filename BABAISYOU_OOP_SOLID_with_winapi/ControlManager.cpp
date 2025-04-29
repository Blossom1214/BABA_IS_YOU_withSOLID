#include "ControlManager.h"
#include "Movement.h"
#include "TileMap.h"
#include "InputManager.h"
#include "ObjectManager.h"
ControlManager::ControlManager(ObjectManager* objectManager) :_objectManager(objectManager), _inputManager(nullptr)
{
}

void ControlManager::Update()
{
	Direction Inputdir = _inputManager->GetInput();
	if (Inputdir == Direction::NONE)
		return;
	const auto& yourObj = _objectManager->GetObjectsWithRule(RuleType::YOU);
		for (TileObjectBase* obj : yourObj)
		{
			TryMove(obj, Inputdir);
		}
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
	Tile* nextTile = _objectManager->GetTile(nextPos);
	if (!nextTile)
		return;
	const std::deque<TileObjectBase*>& objectsInNextTile = nextTile->GetObjects();
	for (TileObjectBase* objInNextTile : objectsInNextTile) //밀수있어?!
	{
		if (objInNextTile->HasRule(RuleType::STOP))//스탑이면 운직이지마!
			return;
		else if (objInNextTile->HasRule(RuleType::PUSH))
		{
			TryMove(objInNextTile, dir);
			if (nextTile->Contains(objInNextTile))//푸시해서 다음타일이 푸시타입이아니고 오브젝트도 없으면 밀지않음!
			{
				return;
			}
		}
	}
	//실제로 밀기!
	Move(obj, currentTile, nextTile);
}
void ControlManager::Move(TileObjectBase* obj, Tile* from, Tile* to)
{
	if (!obj || !from || !to)
		return;
	from->RemoveObject(obj);
	to->AddObject(obj);
	obj->SetTile(to);
}