#pragma once
#include "TileObjectBase.h"

class ObjectTile : public TileObjectBase
{
public:
    ObjectTile();
    virtual ~ObjectTile() override;

    virtual void Render() override;
};