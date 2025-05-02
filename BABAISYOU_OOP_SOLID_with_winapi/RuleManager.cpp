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
	for (const Position& StartPos : _parseTargets) //시작지점은.. 명사가 저장된 위치를 탐색해서 시작하기
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
			//이제 여기에서 문장해석기로 Chain를 보내서 문장 판별을해야한다!!
		}
	}
	_parseTargets.clear();
}

void RuleManager::OnNotify(TileObjectBase* changedObj)
{
}

std::vector<TextTile*> RuleManager::SlideChainFrom(const Position& start, Direction dir, int maxDepth)
{
	std::vector<TextTile*> chaine;//체이닝 문장적용
	Position currentPos = start; //현재위치체크
	Position delta = Movement::Vector(dir);//다음위치으 ㅣ포지션을 확인
	for (int i = 0; i < maxDepth; ++i)//최대길이만큼체크
	{
		if (!_map->Isinside(currentPos))//현재위치가맵밖인가?
			break;
		Tile* tile = _map->GetTile(currentPos);//맵에서현재의 위치에있는 타일을 타일에넣어!
		if (!tile)break; //근데 타일이아니면 나가야해(그럴일은 거의없지만 혹시나..)
		bool foundTextTile = false; //기본적으로 텍스트타일인지여부체크는 false로 되어잇음

		for (TileObjectBase* obj : tile->GetObjects()) //해당타일에 오브젝트 베이스안에있는 덱자료구조에서 오브젝트 전체를 탐색하는것을함
		{
			if (TextTile* Text = dynamic_cast<TextTile*>(obj))//해당 obj가 텍스트타일로 변환이 가능하다면 text타일로 넣어두고!체인에 넣어!
			{
				chaine.push_back(Text);
				foundTextTile = true; //해당위치에있는 그오브젝트는 텍스트타일이라고 생각을하고 true로 변환
				break;
			}
		}
		
		if (!foundTextTile) break; //찾은게 텍스트 타일이 아니면....나와야함...
		currentPos = currentPos + delta; //다음 위치확인!
	}
	return chaine;//현재 체인되어있는반환!
}
//1. 체인 벡터 선언
//2. 현재 위치 = start
//3. maxDepth 만큼 반복 :
//├─ 맵 범위 확인
//├─ 타일 가져오기
//├─ TextTile * 있는지 확인(dynamic_cast)
//└ 없으면 break
//├─ 있으면 체인에 추가
//└ 다음 위치로 이동(Position + DirectionVector)
//4. 반환: 체인

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
