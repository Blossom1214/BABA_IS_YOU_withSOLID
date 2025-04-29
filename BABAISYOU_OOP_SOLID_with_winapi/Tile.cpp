#include "Tile.h"
#include <algorithm>
#include <ranges>
#include "ObjectTile.h"
#include "TextTile.h"
void Tile::AddObject(TileObjectBase* obj) noexcept
{
    if (obj)
    {
        if (dynamic_cast<ObjectTile*>(obj) != nullptr)
            objectList_.push_back(obj);
        else if (dynamic_cast<TextTile*>(obj) != nullptr)
            objectList_.push_front(obj);
        else 
            return;
    }
}

void Tile::RemoveObject(TileObjectBase* obj)
{
    std::erase(objectList_, obj);
}

const Position& Tile::GetPosition() const
{
    return pos_;
}

const std::deque<TileObjectBase*>& Tile::GetObjects() const
{
    return objectList_;
}

bool Tile::Contains(TileObjectBase* obj) const
{
    return std::ranges::find(objectList_, obj) != objectList_.end();
}
