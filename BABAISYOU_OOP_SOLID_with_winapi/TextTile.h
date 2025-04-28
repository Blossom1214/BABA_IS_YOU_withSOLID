#pragma once
#include "TileObjectBase.h"

class TextTile : public TileObjectBase
{
public:
    TextTile();
	virtual ~TextTile() override;

    virtual void Render() override;
};
