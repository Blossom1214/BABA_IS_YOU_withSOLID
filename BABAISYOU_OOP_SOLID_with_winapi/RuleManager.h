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
	RuleManager(TileMap* map);//생성자
	RuleManager(const RuleManager&) = delete; //복사생성은 하지않음!
public:

	void InitialParse();
	void OnNotify(TileObjectBase* changedObj);//알림 수신용 함수(실시간 상태확인용)

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

