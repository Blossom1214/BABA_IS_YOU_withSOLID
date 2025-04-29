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
	Tile* currentTile = obj->GetTile(); //������ġ
	if (!currentTile)
		return;
	Position currentPos=currentTile->GetPosition();
	Position vec = Movement::Vector(dir);
	Position nextPos = currentPos + vec;//����ĭ
	Tile* nextTile = _objectManager->GetTile(nextPos);
	if (!nextTile)
		return;
	const std::deque<TileObjectBase*>& objectsInNextTile = nextTile->GetObjects();
	for (TileObjectBase* objInNextTile : objectsInNextTile) //�м��־�?!
	{
		if (objInNextTile->HasRule(RuleType::STOP))//��ž�̸� ����������!
			return;
		else if (objInNextTile->HasRule(RuleType::PUSH))
		{
			TryMove(objInNextTile, dir);
			if (nextTile->Contains(objInNextTile))//Ǫ���ؼ� ����Ÿ���� Ǫ��Ÿ���̾ƴϰ� ������Ʈ�� ������ ��������!
			{
				return;
			}
		}
	}
	//������ �б�!
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