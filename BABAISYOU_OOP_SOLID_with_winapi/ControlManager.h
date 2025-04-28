#pragma once
#include "Direction.h"
#include "Tile.h"
class TileObjectBase;
class ObjectManager;
class ControlManager
{
public:
    ControlManager(ObjectManager* objectManager);

    void Update();
    void TryMove(TileObjectBase* obj, Direction dir);

private:
    ObjectManager* objectManager_; 
};
