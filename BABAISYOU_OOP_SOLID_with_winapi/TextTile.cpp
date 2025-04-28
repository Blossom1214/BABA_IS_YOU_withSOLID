#include "TextTile.h"

void TextTile::CheckPosTextType()
{	
	if (isText(ObjectType_.back()))
	{
		_Textrole = GetTextRole(ObjectType_.back());
		
	}
}
