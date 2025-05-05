#pragma once
#include "Direction.h"
#include "Tile.h"
class InputManager;
class TileObjectBase;
class ObjectManager;
class NotificationManager;
class TileMap;
class ControlManager
{
public:
    ControlManager(ObjectManager* objectManager);

    void Update();
    void TryMove(TileObjectBase* obj, Direction dir);

    void Move(TileObjectBase* obj, Tile* from, Tile* to);
    void SetNotificationManager(NotificationManager* manager) noexcept {_notificationManager = manager;}
private:
    InputManager* _inputManager;
    ObjectManager* _objectManager; 
    NotificationManager* _notificationManager =nullptr;
};
