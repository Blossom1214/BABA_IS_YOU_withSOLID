#pragma once
#include "Direction.h"
#include "Tile.h"
class InputManager;
class TileObjectBase;
class ObjectManager;
class TileMap;
class ControlManager
{
public:
    ControlManager(ObjectManager* objectManager);

    void Update();
    void TryMove(TileObjectBase* obj, Direction dir);

private:
    InputManager* _inputManager;
    ObjectManager* _objectManager; 
    TileMap* _map;
};
