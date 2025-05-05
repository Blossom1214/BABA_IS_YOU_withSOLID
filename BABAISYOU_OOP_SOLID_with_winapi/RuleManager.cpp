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
#pragma warning(disable:26495) //해당코드에 대한 경고를 꺼버리는 전처리기 문법중하나..
//26495 생성자 선언시 멤버변수 비초기화에 따른 경고..
RuleManager::RuleManager(TileMap* map):_map(map)
{
}

void RuleManager::InitialParse()
{
	_rulesMap.clear();
	for (const Position& StartPos : _parseTargets) //시작지점은.. 명사가 저장된 위치를 탐색해서 시작하기
	{
		for (Direction dir : {Direction::RIGHT, Direction::DOWN})
		{
			std::vector<TextTile*> Chain = SlideChainFrom(StartPos, dir, 7);
			if (Chain.size() < 3)
				continue;
			std::vector<ParsedRule> rules = _grammerManager->parseFSM(Chain);//문장을 보내버림..
			for (const auto& rule : rules) //돌아온 결과를 이제 추가해야함..
			{
				//람다 사용
				std::visit([this,&rule](auto&& val) {
					using A = std::decay_t<decltype(val)>;
					if constexpr (std::is_same_v<A, RuleType>)
						AddRule(rule._subject, val);
					else if constexpr (std::is_same_v<A, ObjectType>)//baba is rock같은경우를 처리하기위함
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
		auto chain = SlideChainFrom(center, dir, 7);//7체인
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
		for (const auto& rule : parsed) //돌아온 결과를 이제 추가해야함..
		{
			//람다 사용
			std::visit([this, &rule](auto&& val)
				{
				using A = std::decay_t<decltype(val)>;
				if constexpr (std::is_same_v<A, RuleType>)
					AddRule(rule._subject, val);
				else if constexpr (std::is_same_v<A, ObjectType>)//baba is rock같은경우를 처리하기위함
				{
					AddTransForm(rule._subject, val);
				}

			}, rule._rule);
		}
	}


}
