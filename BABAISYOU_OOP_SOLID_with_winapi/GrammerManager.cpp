#include "GrammerManager.h"


std::vector<ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
{
    size_t index = 0;
    ParseState state = ParseState::Start;
    TextTile* subjectTile = nullptr;
    VerbTextToTile* verbTile = nullptr;
    std::vector<ParsedRule> result;
    while (index < Chain.size())
    {
        TextTile* tile = Chain[index];

        switch (state)
        {
        case ParseState::Start:
            if (tile->ToObjectType())
            {
                subjectTile = tile;
                state = ParseState::ExpectVerb;
            }
            else
            {
                state = ParseState::Error;
            }
            break;

        case ParseState::ExpectVerb:
            if (tile->ToVerbKind())
            {
                verbTile = dynamic_cast<VerbTextToTile*>(tile);
                state = verbTile ? ParseState::ExpectValue : ParseState::Error;
            }
            else
            {
                state = ParseState::Error;
            }
            break;

        case ParseState::ExpectValue:
            if (subjectTile && verbTile && tile)
            {
                if (auto parsed = verbTile->Validate(subjectTile, tile))
                {
                    result.push_back(*parsed);
                    state = ParseState::Accept;
                    break;
                }
            }
            state = ParseState::Error;
            break;

        case ParseState::Accept:
            if (tile->ToVerbKind())
                state = ParseState::ExpectVerb;
            else if (tile->ToObjectType())
                state = ParseState::Start;
            else
                state = ParseState::Error;
            break;

        case ParseState::Error:
            state = ParseState::Start;
            break;

        default:
            break;
        }

        ++index;
    }

    return result;
}
//아래코드를 위의 코드로 리펙터링하였음
//std::vector<ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
//{
//	size_t i = 0;//체인을 순회하는 용도로 일단 선언해봄(인덱스를 ++해서 다음칸을 탐색해야함)//이제야 비로소 사용할때가왓다
//	ParseState State = ParseState::Start;//fsm의 상태!
//	TextTile* subjectTile = nullptr;
//	VerbTextToTile* verbTile = nullptr;
//	std::vector<ParsedRule> result; //결과물 반환
//
//	for (int index = 0; index < Chain.size();)
//	{
//		switch (State)
//		{
//		case ParseState::Start:
//		{
//			TextTile* tile = Chain[index];
//			if (auto optObj = tile->ToObjectType()) //음...이러면 유효성은 여기서밖에 적용이 안되는건가?
//			{
//				subjectTile = tile;
//				State = ParseState::ExpectVerb;
//				index++;
//			}
//			//명사를 저장해야함 그러면 일단 반환타입을 가지고있는 tile을 다운캐스팅하던지 아니면 함수를 호출해서 오브젝트 타입으로 변환을 시켜주어야함
//			else
//			{
//				State = ParseState::Error;
//			}
//		}
//		break;
//		case ParseState::ExpectVerb:
//		{
//			TextTile* tile = Chain[index];
//			if (auto optVerb = tile->ToVerbKind())
//			{
//				verbTile = dynamic_cast<VerbTextToTile*>(tile);
//				if (verbTile) {
//					State = ParseState::ExpectValue;
//					index++;
//				}
//				else {
//					State = ParseState::Error;
//				}
//			}
//			//명사를 저장해야함 그러면 일단 반환타입을 가지고있는 tile을 다운캐스팅하던지 아니면 함수를 호출해서 오브젝트 타입으로 변환을 시켜주어야함
//			else
//			{
//				State = ParseState::Error;
//			}
//		}
//		break;
//		case ParseState::ExpectValue:
//		{
//			TextTile* valueTile = Chain[index];
//
//			if (subjectTile && verbTile && valueTile)
//			{
//				if (auto parsed = verbTile->Validate(subjectTile, valueTile))
//				{
//					result.push_back(*parsed);
//					++index;
//					State = ParseState::Accept;
//					break;
//				}
//			}
//
//			State = ParseState::Error;
//		}
//		break;
//
//		case ParseState::Accept:
//		{
//			++index;
//			if (index < Chain.size())//사이즈보다 작다면 체인되어있는게 존재함 따라서 다음으로 이동하기위해 상태를변경
//			{
//				TextTile* tile = Chain[index];
//				if (tile->ToVerbKind()) //동사라면 동사상태로만들기
//				{
//					State = ParseState::ExpectVerb;
//				}
//				else if (tile->ToObjectType()) //obj상태라면 obj상태로만들기
//				{
//					State = ParseState::Start;
//				}
//				else
//				{
//					State = ParseState::Error; //그것도 아니면 에러상태로 만들기..
//				}
//			}
//			else
//			{
//				break;
//			}
//		}break;
//		case ParseState::Error:
//			State = ParseState::Start;
//			index++;
//			break;
//		default:
//			break;
//		}
//
//	}
//	return result;
//}
