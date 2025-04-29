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
    obj->SetTile(nullptr); //오브젝트를 완전히 비운다고했지만 안그럴수도있기때문에 여긴 나중에 주석처리할수도있음
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
//	//덱자료구조로 푸시프론트는 text로 하고푸시백은 object로 하자
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

