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
	RuleManager(TileMap* map);//������
	RuleManager(const RuleManager&) = delete; //��������� ��������!
public:

	void InitialParse();
	void OnNotify(TileObjectBase* changedObj);//�˸� ���ſ� �Լ�(�ǽð� ����Ȯ�ο�)

	bool HasRule(ObjectType obj, RuleType rule) const; //�̿�����Ʈ�� �� ���� �ֳ���?!
	const std::unordered_set<RuleType>& GetRules(ObjectType obj) const;//�ش������Ʈ�� �ִ� �����̺��б�!
	void RegisterParseTarget(const Position& pos);//�ؽ�ƮŸ���̸�.. ����� ��ġ!(�����..)(�ʻ����� ���ʸ�)
private:
	
	void AddRule(ObjectType subject, RuleType rule); //�����ؼ��� ���߰�
	void RemoveRulesLinkedTo(Position center);

	//��� ���� �����غ��鼭 ������ �Ǵٸ� ��Ģ�� �׳� ���� �ʹ� ��ư� ��������
	void UpdateRulesAt(Position center);
private:
	TileMap* _map;
	GrammerManager* _grammerManager;
	std::vector<Position> _parseTargets;
	std::unordered_map<ObjectType, std::unordered_set<RuleType>> _rules;

};

