#include "GrammerManager.h"

std::vector<ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
{
	size_t i = 0;//체인을 순회하는 용도로 일단 선언해봄(인덱스를 ++해서 다음칸을 탐색해야함)//이제야 비로소 사용할때가왓다
	ParseState State = ParseState::Start;//fsm의 상태!
	ObjectType currentSubject{};//명사저장용..(다음에 오는 값이 이것을 알고있어야하기때문)
	TextTile* subjectTile = nullptr;
	VerbTextToTile* verbTile = nullptr;
	VerbKind currentVerb = VerbKind::Invalid;//이번엔 동사임 //나중에 더 사용할가치가 있는거같은데 일단 만들어 놓고 쓰지 않는중...
	std::vector<ParsedRule> result; //결과물 반환

	for (int index = 0; index < Chain.size();)
	{
		switch (State)
		{
		case ParseState::Start:
		{
			TextTile* tile = Chain[index];
			if (auto optObj = tile->ToObjectType()) //음...이러면 유효성은 여기서밖에 적용이 안되는건가?
			{
				currentSubject = *optObj;//역참조의 사유... 반환값이 optional객체이기때문에 해당객체의 값을 사용하기위해 역참조함
				subjectTile = tile;
				State = ParseState::ExpectVerb;
				index++;
			}
			//명사를 저장해야함 그러면 일단 반환타입을 가지고있는 tile을 다운캐스팅하던지 아니면 함수를 호출해서 오브젝트 타입으로 변환을 시켜주어야함
			else
			{
				State = ParseState::Error;
			}
		}
		break;
		case ParseState::ExpectVerb:
		{
			TextTile* tile = Chain[index];
			if (auto optVerb = tile->ToVerbKind()) 
			{
				currentVerb = *optVerb;//역참조의 사유... 반환값이 optional객체이기때문에 해당객체의 값을 사용하기위해 역참조함
				verbTile = dynamic_cast<VerbTextToTile*>(tile);
				State = ParseState::ExpectValue;
				index++;
			}
			//명사를 저장해야함 그러면 일단 반환타입을 가지고있는 tile을 다운캐스팅하던지 아니면 함수를 호출해서 오브젝트 타입으로 변환을 시켜주어야함
			else
			{
				State = ParseState::Error;
			}
		}
		break;
		case ParseState::ExpectValue:
		{
			//여기 문제가 좀 생긴듯
			//무조건적으로 accept로 상태를 바꾸면 안됨..
			//푸시백도 뭔가 잘못된게 맞음 여기 전체 과정에서 동사가 어떤것인지
			//그 동사가 어떻게 문법적으로 적용될수있는지 여부는 1도 확인하지않고 그냥 넣고있는 모습
			//따라서 이전체를 둘러싸는걸로하여끔 위에있는 저장된 동사를 가지고 시작해야함...
			TextTile* valueTile = Chain[index];
			if (verbTile && subjectTile)
			{
				if (auto parsed = verbTile->Validate(Chain, i))
				{
					result.push_back(*parsed);
					State = ParseState::Accept;
					index++;
					break;
				}
			}
			State = ParseState::Error;
			//푸시백은 따로 해야함 위에서 미리 먼저 체크하고 돌아온것을 가지고 유효성 체크를 하고 아래의 타입을 보고 추가하는방식을 택해야하는것이 올바른방법임
			//if (auto optRule = tile->ToRuleType()) //음...이러면 유효성은 여기서밖에 적용이 안되는건가?
			//{
			//	result.push_back(ParsedRule{ currentSubject,*optRule });
			//	State = ParseState::Accept;
			//	index++;
			//
			//}
			//else if (auto optobj = tile->ToObjectType())
			//{
			//	result.push_back(ParsedRule{ currentSubject,*optobj}); //좀더 공부해야할듯
			//	//해결방법을 찾아야함.... 찾음!!(variant)//변종같은쉑...
			//	State = ParseState::Accept;
			//	index++;
			//}
			//else
			//{
			//	State = ParseState::Error;
			//}
		}
		break;
		case ParseState::Accept:
		{
			if (index < Chain.size())//사이즈보다 작다면 체인되어있는게 존재함 따라서 다음으로 이동하기위해 상태를변경
			{
				TextTile* tile = Chain[index];
				if (tile->ToVerbKind()) //동사라면 동사상태로만들기
				{
					State = ParseState::ExpectVerb;
				}
				else if (tile->ToObjectType()) //obj상태라면 obj상태로만들기
				{
					State = ParseState::Start;
				}
				else
				{
					State = ParseState::Error; //그것도 아니면 에러상태로 만들기..
				}
			}
			else
			{
				break;
			}
		}break;
		case ParseState::Error:
			State = ParseState::Start;
			index++;
			break;
		default:
			break;
		}

	}
	return result;
}
