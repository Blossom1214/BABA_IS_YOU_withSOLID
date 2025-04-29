#include "ObjectManager.h"
#include "Tile.h"
#include "TileObjectBase.h"
#include "TileMap.h"
void ObjectManager::AddObjectAndText()
{
	_ObjectTile->AddObject(_Object);
	
	//���ڷᱸ���� Ǫ������Ʈ�� text�� �ϰ�Ǫ�ù��� object�� ����
}

std::deque<TileObjectBase*> ObjectManager::GetObjectsWithRule(RuleType rule) const
{
    std::deque<TileObjectBase*> result;
    for (int y = 0; y < _map->GetHeight(); ++y)
    {
        for (int x = 0; x < _map->GetWidth(); ++x)
        {
            Tile* tile = _map->GetTile(Position(x, y));
            for (TileObjectBase* obj : tile->GetObjects())
            {
                if (obj->HasRule(rule))
                {
                    result.push_back(obj);
                }
            }
        }
    }
	return result;
}


