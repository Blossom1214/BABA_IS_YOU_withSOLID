#include "ObjectTile.h"

void ObjectTile::SetTile(ObjectType type)
{
	if (!isText(type))
	{
		if (type != ObjectType::NONE)
			ObjectType_.push_back(type);

	}
}
