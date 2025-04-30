#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "RuleType.h"
#include "ObjectType.h"
#include "Position.h"
#include "MYCustom.h"
class TileMap;
class TileObjectBase;
using namespace MYCustom::Uitility::Hash;


class RuleManager
{
	friend class GrammerManager;
public:
	RuleManager(TileMap* map);//생성자
	RuleManager(const RuleManager&) = delete; //복사생성은 하지않음!
public:

	void InitialParse();
	void OnNotify(TileObjectBase* changedObj);//알림 수신용 함수(실시간 상태확인용)

	bool HasRule(ObjectType obj, RuleType rule) const; //이오브젝트에 이 룰이 있나요?!
	const std::unordered_set<RuleType>& GetRules(ObjectType obj) const;//해당오브젝트에 있는 룰테이블읽기!
	void RegisterParseTarget(const Position& pos);//텍스트타일이며.. 명사의 위치!(저장용..)(맵생성시 최초만)
private:
	
	void AddRule(ObjectType subject, RuleType rule); //문장해석후 룰추가
	void RemoveRulesLinkedTo(Position center);

	//방금 실제 게임해보면서 깨달은 또다른 규칙들 그냥 내가 너무 어렵게 생각햇음
	void UpdateRulesAt(Position center);
private:
	TileMap* _map;
	GrammerManager* _grammerManager;
	std::vector<Position> _parseTargets;
	std::unordered_map<ObjectType, std::unordered_set<RuleType>> _rules;

};

