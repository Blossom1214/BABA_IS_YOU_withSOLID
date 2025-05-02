#include "RuleManager.h"
#include "TileMap.h"
#include "TileObjectBase.h"
#include "GrammerManager.h"
#include <algorithm>
#include "Tile.h"
#include  "Movement.h"
#include "TextTile.h"
RuleManager::RuleManager(TileMap* map):_map(map)
{
}

void RuleManager::InitialParse()
{
	for (const Position& StartPos : _parseTargets) //����������.. ��簡 ����� ��ġ�� Ž���ؼ� �����ϱ�
	{
		for (Direction dir : {Direction::RIGHT, Direction::DOWN})
		{
			std::vector<TextTile*> Chain = SlideChainFrom(StartPos, dir, 7);
			if (Chain.size() < 3)
				continue;
			TextTile* first = Chain[0];
			TextTile* second = Chain[1];
			TextTile* third = Chain[2];
			if (first->GetTextType() != TextType::Noun)
				continue;
			if (second->GetTextType() != TextType::Verb)
				continue;
			if (third->GetTextType() == TextType::Verb)
				continue;
			//���� ���⿡�� �����ؼ���� Chain�� ������ ���� �Ǻ����ؾ��Ѵ�!!
		}
	}
	_parseTargets.clear();
}

void RuleManager::OnNotify(TileObjectBase* changedObj)
{
}

std::vector<TextTile*> RuleManager::SlideChainFrom(const Position& start, Direction dir, int maxDepth)
{
	std::vector<TextTile*> chaine;//ü�̴� ��������
	Position currentPos = start; //������ġüũ
	Position delta = Movement::Vector(dir);//������ġ�� ���������� Ȯ��
	for (int i = 0; i < maxDepth; ++i)//�ִ���̸�ŭüũ
	{
		if (!_map->Isinside(currentPos))//������ġ���ʹ��ΰ�?
			break;
		Tile* tile = _map->GetTile(currentPos);//�ʿ��������� ��ġ���ִ� Ÿ���� Ÿ�Ͽ��־�!
		if (!tile)break; //�ٵ� Ÿ���̾ƴϸ� ��������(�׷����� ���Ǿ����� Ȥ�ó�..)
		bool foundTextTile = false; //�⺻������ �ؽ�ƮŸ����������üũ�� false�� �Ǿ�����

		for (TileObjectBase* obj : tile->GetObjects()) //�ش�Ÿ�Ͽ� ������Ʈ ���̽��ȿ��ִ� ���ڷᱸ������ ������Ʈ ��ü�� Ž���ϴ°�����
		{
			if (TextTile* Text = dynamic_cast<TextTile*>(obj))//�ش� obj�� �ؽ�ƮŸ�Ϸ� ��ȯ�� �����ϴٸ� textŸ�Ϸ� �־�ΰ�!ü�ο� �־�!
			{
				chaine.push_back(Text);
				foundTextTile = true; //�ش���ġ���ִ� �׿�����Ʈ�� �ؽ�ƮŸ���̶�� �������ϰ� true�� ��ȯ
				break;
			}
		}
		
		if (!foundTextTile) break; //ã���� �ؽ�Ʈ Ÿ���� �ƴϸ�....���;���...
		currentPos = currentPos + delta; //���� ��ġȮ��!
	}
	return chaine;//���� ü�εǾ��ִ¹�ȯ!
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
