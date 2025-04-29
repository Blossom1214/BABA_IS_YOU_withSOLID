#include "ObjectManager.h"
#include "Tile.h"
#include "TileObjectBase.h"
#include "TileMap.h"

ObjectManager::ObjectManager(TileMap* map)
    : _map(map)
{
}

void ObjectManager::AddObject(TileObjectBase* obj)
{
    if (!obj || !_map)
        return;

    Position pos = obj->GetTile()->GetPosition();
    if (!_map->Isinside(pos))
        return;

    Tile* tile = _map->GetTile(pos);
    tile->AddObject(obj);
    obj->SetTile(tile);
}

void ObjectManager::RemoveObject(TileObjectBase* obj)
{
    if (!obj)
        return;

    Tile* tile = obj->GetTile();
    if (!tile)
        return;

    tile->RemoveObject(obj);
    obj->SetTile(nullptr); //������Ʈ�� ������ ���ٰ������� �ȱ׷������ֱ⶧���� ���� ���߿� �ּ�ó���Ҽ�������
}

std::deque<TileObjectBase*> ObjectManager::GetObjectsWithRule(RuleType rule) const
{
    std::deque<TileObjectBase*> result;

    if (!_map)
        return result;

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
//void ObjectManager::AddObjectAndText()
//{
//	_ObjectTile->AddObject(_Object);
//	
//	//���ڷᱸ���� Ǫ������Ʈ�� text�� �ϰ�Ǫ�ù��� object�� ����
//}
//
//void ObjectManager::RemoveObj()
//{
//    _ObjectTile->RemoveObject(_Object);
//}
//
//std::deque<TileObjectBase*> ObjectManager::GetObjectsWithRule(RuleType rule) const
//{
//    std::deque<TileObjectBase*> result;
//    for (int y = 0; y < _map->GetHeight(); ++y)
//    {
//        for (int x = 0; x < _map->GetWidth(); ++x)
//        {
//            Tile* tile = _map->GetTile(Position(x, y));
//            for (TileObjectBase* obj : tile->GetObjects())
//            {
//                if (obj->HasRule(rule))
//                {
//                    result.push_back(obj);
//                }
//            }
//        }
//    }
//	return result;
//}

