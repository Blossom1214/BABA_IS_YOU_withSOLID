#pragma once
#include "TextTile.h"
#include "TextType.h"
#include "NounType.h"
class NounTextToTile :public TextTile
{
public:
    virtual NounType GetLinkedObjectType() const = 0;

    virtual TextType GetTextType() const override final;
};

