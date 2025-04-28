#include "TextTile.h"
void TextTile::SetTile(ObjectType type)
{
	if (isText(type)) 
	{
		_Textrole = GetTextRole(type);
	}
}
