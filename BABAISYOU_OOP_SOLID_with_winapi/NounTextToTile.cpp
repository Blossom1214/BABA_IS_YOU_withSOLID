#include "NounTextToTile.h"

TextType ObjectTextToTile::GetTextType() const
{
	return TextType::Noun;
}

std::optional<ObjectType> ObjectTextToTile::ToObjectType() const
{
	return _ObjectType;
}
