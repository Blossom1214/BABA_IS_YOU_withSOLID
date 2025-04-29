#pragma once
#include "TextTile.h"
#include "VerbType.h"
class VerbTextToTile : public TextTile
{
    virtual VerbType GetVerbType() const = 0;

    virtual TextType GetTextType() const override final;
   
};

