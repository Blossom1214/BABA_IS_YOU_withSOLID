#include "RuleManager.h"
#include "TileMap.h"
#include "TileObjectBase.h"
#include "GrammerManager.h"
#include <algorithm>

RuleManager::RuleManager(TileMap* map):_map(map)
{
}

void RuleManager::InitialParse()
{
}

void RuleManager::OnNotify(TileObjectBase* changedObj)
{
}

std::vector<TextTile*> RuleManager::SlideChainFrom(const Position& start, Direction dir, int maxDepth)
{





	return std::vector<TextTile*>();
}

bool RuleManager::HasRule(ObjectType obj, RuleType rule) const
{
	
	auto it = _rules.find(obj);
	if (it == _rules.end())
	{
		return false;
	}
	return it->second.find(rule) != it->second.end();
}

const std::unordered_set<RuleType>& RuleManager::GetRules(ObjectType obj) const
{
	static const std::unordered_set<RuleType> empty;
	auto it = _rules.find(obj);
	if (it == _rules.end())
	{
		return empty;
	}
	return it->second;
}

void RuleManager::RegisterParseTarget(const Position& pos)
{
	_parseTargets.push_back(pos);
}

void RuleManager::AddRule(ObjectType subject, RuleType rule)
{
	_rules[subject].insert(rule);
}

void RuleManager::RemoveRulesLinkedTo(Position center)
{
}

void RuleManager::UpdateRulesAt(Position center)
{
}
