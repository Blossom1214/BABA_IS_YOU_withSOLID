#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "RuleType.h"
#include "ObjectType.h"
#include "Position.h"
#include "Direction.h"
#include "EnumClassHash.h"
class TileMap;
class TileObjectBase;
class TextTile;



class RuleManager
{
	friend class GrammerManager;
public:
	RuleManager(TileMap* map);//������
	RuleManager(const RuleManager&) = delete; //��������� ��������!
public:

	void InitialParse();//�����̵� ü�̴�(�� �����ÿ���)
	void OnNotify(TileObjectBase* changedObj);

	std::vector<TextTile*> SlideChainFrom(const Position& start, Direction dir, int maxDepth);//�����̵� ü�̴�...

	bool HasRule(ObjectType obj, RuleType rule) const; //�̿�����Ʈ�� �� ���� �ֳ���?!
	const std::unordered_set<RuleType>& GetRules(ObjectType obj) const;//�ش������Ʈ�� �ִ� �����̺��б�!
	void RegisterParseTarget(const Position& pos);//�ؽ�ƮŸ���̸�.. ����� ��ġ!(�����..)(�ʻ����� ���ʸ�)
private:
	
	void AddRule(ObjectType subject, RuleType rule); //�����ؼ��� ���߰�
	void AddTransForm(ObjectType subject, ObjectType subject_2);//���� baba is rock�������� �´ٸ�..?
	void RemoveRulesLinkedTo(Position center);

	//��� ���� �����غ��鼭 ������ �Ǵٸ� ��Ģ�� �׳� ���� �ʹ� ��ư� ��������
	void UpdateRulesAt(Position center);
private:
	TileMap* _map;
	GrammerManager* _grammerManager;
	std::vector<Position> _parseTargets;
	std::unordered_map<ObjectType, std::unordered_set<RuleType>> _rulesMap;
	std::unordered_map<ObjectType, ObjectType> _transFormMap;

};

