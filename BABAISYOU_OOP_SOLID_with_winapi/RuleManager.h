#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "RuleType.h"
#include "ObjectType.h"
#include "Position.h"
class TileMap;
class GrammerManager;
class TileObjectBase;
class RuleManager
{
public:
	RuleManager(TileMap* map);//������
	RuleManager(const RuleManager&) = delete; //��������� ��������!
public:

	void InitialParse();
	void OnNotify(TileObjectBase* changedObj);//�˸� ���ſ� �Լ�(�ǽð� ����Ȯ�ο�)

	bool HasRule(ObjectType obj, RuleType rule) const;
	const std::unordered_set<RuleType>& GetRules(ObjectType obj) const;

private:
	
	void AddRule(ObjectType subject, RuleType rule);
	void RemoveRulesLinkedTo(Position center);

	
	void UpdateRulesAt(Position center);
private:
	TileMap* _map;
	GrammerManager* _grammerManager;
	std::unordered_map<ObjectType, std::unordered_set<RuleType>> _rules;

};

