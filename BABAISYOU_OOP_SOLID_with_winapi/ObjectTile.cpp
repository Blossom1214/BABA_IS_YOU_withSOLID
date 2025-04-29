#include "ObjectTile.h"
ObjectTile::ObjectTile()
{
}

ObjectTile::~ObjectTile()
{
}

void ObjectTile::Render()
{
}

void ObjectTile::AddRule(RuleType rule)
{
	activeRules_.insert(rule);
}

void ObjectTile::RemoveRule(RuleType rule)
{
	activeRules_.erase(rule);
}

void ObjectTile::ClearRules()
{
	activeRules_.clear();
}

bool ObjectTile::HasRule(RuleType rule) const
{
	return activeRules_.contains(rule);
}
