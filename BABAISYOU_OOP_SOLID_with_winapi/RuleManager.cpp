#include "RuleManager.h"
#include "TileMap.h"
#include "TileObjectBase.h"
#include "GrammerManager.h"
#include <algorithm>
#include "Tile.h"
#include"Movement.h"
#include "TextTile.h"
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
	std::vector<TextTile*> chaine;
	Position currentPos = start;
	Position delta = Movement::Vector(dir);
	for (int i = 0; i < maxDepth; ++i)
	{
		if (!_map->Isinside(currentPos))
			break;
		Tile* tile = _map->GetTile(currentPos);
		if (!tile)break;
		bool foundTextTile = false;

		for (TileObjectBase* obj : tile->GetObjects()) 
		{
			if (TextTile* Text = dynamic_cast<TextTile*>(obj))
			{
				chaine.push_back(Text);
				foundTextTile = true;
				break;
			}
		}
		
		if (!foundTextTile) break;
		currentPos = currentPos + delta;
	}
	return chaine;
}
//1. ü�� ���� ����
//2. ���� ��ġ = start
//3. maxDepth ��ŭ �ݺ� :
//���� �� ���� Ȯ��
//���� Ÿ�� ��������
//���� TextTile * �ִ��� Ȯ��(dynamic_cast)
//�� ������ break
//���� ������ ü�ο� �߰�
//�� ���� ��ġ�� �̵�(Position + DirectionVector)
//4. ��ȯ: ü��
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
