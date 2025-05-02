#pragma once
#include "TextTile.h"
#include "TextType.h"
#include "NounType.h"
#include "ObjectType.h"
class ObjectTextToTile :public TextTile
{
public:
    virtual NounType GetLinkedObjectType() const = 0;

    virtual TextType GetTextType() const override final;
    std::optional<ObjectType> ToObjectType() const override;
private:
    ObjectType _ObjectType;
};

