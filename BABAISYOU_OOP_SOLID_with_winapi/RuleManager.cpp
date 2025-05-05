#include "RuleManager.h"
#include "TileMap.h"
#include "TileObjectBase.h"
#include "GrammerManager.h"
#include <algorithm>
#include "Tile.h"
#include  "Movement.h"
#include "TextTile.h"
#include "ParsedRule.h"
#include <variant>
#pragma warning(disable:26495) //�ش��ڵ忡 ���� ��� �������� ��ó���� �������ϳ�..
//26495 ������ ����� ������� ���ʱ�ȭ�� ���� ���..
RuleManager::RuleManager(TileMap* map):_map(map)
{
}

void RuleManager::InitialParse()
{
	_rulesMap.clear();
	for (const Position& StartPos : _parseTargets) //����������.. ��簡 ����� ��ġ�� Ž���ؼ� �����ϱ�
	{
		for (Direction dir : {Direction::RIGHT, Direction::DOWN})
		{
			std::vector<TextTile*> Chain = SlideChainFrom(StartPos, dir, 7);
			if (Chain.size() < 3)
				continue;
			std::vector<ParsedRule> rules = _grammerManager->parseFSM(Chain);//������ ��������..
			for (const auto& rule : rules) //���ƿ� ����� ���� �߰��ؾ���..
			{
				//���� ���
				std::visit([this,&rule](auto&& val) {
					using A = std::decay_t<decltype(val)>;
					if constexpr (std::is_same_v<A, RuleType>)
						AddRule(rule._subject, val);
					else if constexpr (std::is_same_v<A, ObjectType>)//baba is rock������츦 ó���ϱ�����
					{
						AddTransForm(rule._subject, val);
					}

				}, rule._rule);
			}
		}
	}
	_parseTargets.clear();
}

//void RuleManager::OnNotify(TileObjectBase* changedObj)
//{
//}

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
	
	auto it = _rulesMap.find(obj);
	if (it == _rulesMap.end())
	{
		return false;
	}
	return it->second.find(rule) != it->second.end();
}

const std::unordered_set<RuleType>& RuleManager::GetRules(ObjectType obj) const
{
	static const std::unordered_set<RuleType> empty;
	auto it = _rulesMap.find(obj);
	if (it == _rulesMap.end())
	{
		return empty;
	}
	return it->second;
}

std::optional<ObjectType> RuleManager::GetTransFormObj(ObjectType obj) const
{
	auto it = _transFormMap.find(obj);
	if (it == _transFormMap.end())
	{
		return std::nullopt;
	}

	return it->second;
	
}

void RuleManager::RegisterParseTarget(const Position& pos)
{
	_parseTargets.push_back(pos);
}

void RuleManager::AddRule(ObjectType subject, RuleType rule)
{
	_rulesMap[subject].insert(rule);
}

void RuleManager::AddTransForm(ObjectType subject, ObjectType target)
{
	_transFormMap[subject] = target;
}

void RuleManager::RemoveRulesLinkedTo(Position center)
{
	for (Direction dir : {Direction::RIGHT, Direction::DOWN})
	{
		auto chain = SlideChainFrom(center, dir, 7);//7ü��
		if (chain.size() < 3) continue;

		auto parsed = _grammerManager->parseFSM(chain);

		if (parsed.empty()) 
		{
			if (auto optObj = chain[0]->ToObjectType()) 
			{
				_rulesMap.erase(*optObj);
				_transFormMap.erase(*optObj);
			}
		}
	}
}

void RuleManager::UpdateRulesAt(Position center)
{
	RemoveRulesLinkedTo(center);
	for (Direction dir : {Direction::RIGHT, Direction::DOWN})
	{
		auto chain = SlideChainFrom(center, dir, 7);
		if (chain.size() < 3) continue;
		auto parsed = _grammerManager->parseFSM(chain);
		for (const auto& rule : parsed) //���ƿ� ����� ���� �߰��ؾ���..
		{
			//���� ���
			std::visit([this, &rule](auto&& val)
				{
				using A = std::decay_t<decltype(val)>;
				if constexpr (std::is_same_v<A, RuleType>)
					AddRule(rule._subject, val);
				else if constexpr (std::is_same_v<A, ObjectType>)//baba is rock������츦 ó���ϱ�����
				{
					AddTransForm(rule._subject, val);
				}

			}, rule._rule);
		}
	}


}
