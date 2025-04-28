#include "TextTile.h"
#include "TextRole.h"
void TextTile::SetTile(ObjectType type)
{
	if (isText(type)) 
	{
		_Textrole = GetTextRole(type);
		if (_Textrole==TextRole::NONE)
		{
			return;
		}
	}
}
