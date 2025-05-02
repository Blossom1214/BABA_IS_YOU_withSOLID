#include "GrammerManager.h"

std::vector<GrammerManager::ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
{
	size_t i = 0;//체인을 순회하는 용도로 일단 선언해봄(인덱스를 ++해서 다음칸을 탐색해야함)
	ParseState State = ParseState::Start;//fsm의 상태!
	ObjectType currentSubject{};//명사저장용..(다음에 오는 값이 이것을 알고있어야하기때문)
	bool hasSubject = false; //상태가 명사를 가지게 되는상황을 알기위함
	VerbKind currentVerb = VerbKind::Invalid;//이번엔 동사임
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
				hasSubject = true; //참으로 바꾸어줌
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
			if (Chain[index]->GetTextType() != TextType::Verb)
			{
				State = ParseState::Error;
				break;
			}
			State = ParseState::ExpectValue;
			index++;
		}
			break;
		case ParseState::ExpectValue:
		{
			TextTile* tile = Chain[index];
			if (Chain[index]->GetTextType() != TextType::Noun && Chain[index]->GetTextType() != TextType::State)
			{
				State = ParseState::Error;
				break;
			}
			index++;
		}
			break;
		case ParseState::Accept:
		{
			//여기는 증감연산자 사용안함
			//재귀적인 호출을 통해서 사용? 해당사항이라는건 체인을 받아서...
			//해당문장이 연결의 가능성을 의미하고 결국 expectVerb를 만났다는것!
			
		}
		break;
		case ParseState::Error:
			break;

		default:
			break;
		}

	}
	return result;
}
