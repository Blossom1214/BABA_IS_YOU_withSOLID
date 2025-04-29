#include "TextTile.h"

TextTile::TextTile()
{
}

TextTile::~TextTile()
{
}

void TextTile::Render()
{
}
void TextTile::AddRule(RuleType rule)
{
	activeRules_.insert(rule);
}

void TextTile::RemoveRule(RuleType rule)
{
	activeRules_.erase(rule);
}

void TextTile::ClearRules()
{
	activeRules_.clear();
}

bool TextTile::HasRule(RuleType rule) const
{
	return activeRules_.contains(rule);
}