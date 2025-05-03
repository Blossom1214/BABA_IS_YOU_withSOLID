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
//�Ʒ��ڵ带 ���� �ڵ�� �����͸��Ͽ���
//std::vector<ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
//{
//	size_t i = 0;//ü���� ��ȸ�ϴ� �뵵�� �ϴ� �����غ�(�ε����� ++�ؼ� ����ĭ�� Ž���ؾ���)//������ ��μ� ����Ҷ����Ӵ�
//	ParseState State = ParseState::Start;//fsm�� ����!
//	TextTile* subjectTile = nullptr;
//	VerbTextToTile* verbTile = nullptr;
//	std::vector<ParsedRule> result; //����� ��ȯ
//
//	for (int index = 0; index < Chain.size();)
//	{
//		switch (State)
//		{
//		case ParseState::Start:
//		{
//			TextTile* tile = Chain[index];
//			if (auto optObj = tile->ToObjectType()) //��...�̷��� ��ȿ���� ���⼭�ۿ� ������ �ȵǴ°ǰ�?
//			{
//				subjectTile = tile;
//				State = ParseState::ExpectVerb;
//				index++;
//			}
//			//��縦 �����ؾ��� �׷��� �ϴ� ��ȯŸ���� �������ִ� tile�� �ٿ�ĳ�����ϴ��� �ƴϸ� �Լ��� ȣ���ؼ� ������Ʈ Ÿ������ ��ȯ�� �����־����
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
//			//��縦 �����ؾ��� �׷��� �ϴ� ��ȯŸ���� �������ִ� tile�� �ٿ�ĳ�����ϴ��� �ƴϸ� �Լ��� ȣ���ؼ� ������Ʈ Ÿ������ ��ȯ�� �����־����
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
//			if (index < Chain.size())//������� �۴ٸ� ü�εǾ��ִ°� ������ ���� �������� �̵��ϱ����� ���¸�����
//			{
//				TextTile* tile = Chain[index];
//				if (tile->ToVerbKind()) //������ ������·θ����
//				{
//					State = ParseState::ExpectVerb;
//				}
//				else if (tile->ToObjectType()) //obj���¶�� obj���·θ����
//				{
//					State = ParseState::Start;
//				}
//				else
//				{
//					State = ParseState::Error; //�װ͵� �ƴϸ� �������·� �����..
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
