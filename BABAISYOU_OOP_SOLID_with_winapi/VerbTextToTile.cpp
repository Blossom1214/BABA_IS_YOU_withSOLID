#include "VerbTextToTile.h"

VerbTextToTile::VerbTextToTile(VerbKind verb):_verbKind(verb)
{
}

TextType VerbTextToTile::GetTextType() const
{
    
     return TextType::Verb;
    
}

std::optional<VerbKind> VerbTextToTile::ToVerbKind() const
{
    return _verbKind;
}
