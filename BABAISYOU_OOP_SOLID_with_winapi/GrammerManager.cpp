#include "GrammerManager.h"

std::vector<ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
{
	size_t i = 0;//ü���� ��ȸ�ϴ� �뵵�� �ϴ� �����غ�(�ε����� ++�ؼ� ����ĭ�� Ž���ؾ���)//������ ��μ� ����Ҷ����Ӵ�
	ParseState State = ParseState::Start;//fsm�� ����!
	ObjectType currentSubject{};//��������..(������ ���� ���� �̰��� �˰��־���ϱ⶧��)
	TextTile* subjectTile = nullptr;
	VerbTextToTile* verbTile = nullptr;
	VerbKind currentVerb = VerbKind::Invalid;//�̹��� ������ //���߿� �� ����Ұ�ġ�� �ִ°Ű����� �ϴ� ����� ���� ���� �ʴ���...
	std::vector<ParsedRule> result; //����� ��ȯ

	for (int index = 0; index < Chain.size();)
	{
		switch (State)
		{
		case ParseState::Start:
		{
			TextTile* tile = Chain[index];
			if (auto optObj = tile->ToObjectType()) //��...�̷��� ��ȿ���� ���⼭�ۿ� ������ �ȵǴ°ǰ�?
			{
				currentSubject = *optObj;//�������� ����... ��ȯ���� optional��ü�̱⶧���� �ش簴ü�� ���� ����ϱ����� ��������
				subjectTile = tile;
				State = ParseState::ExpectVerb;
				index++;
			}
			//��縦 �����ؾ��� �׷��� �ϴ� ��ȯŸ���� �������ִ� tile�� �ٿ�ĳ�����ϴ��� �ƴϸ� �Լ��� ȣ���ؼ� ������Ʈ Ÿ������ ��ȯ�� �����־����
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
				currentVerb = *optVerb;//�������� ����... ��ȯ���� optional��ü�̱⶧���� �ش簴ü�� ���� ����ϱ����� ��������
				verbTile = dynamic_cast<VerbTextToTile*>(tile);
				State = ParseState::ExpectValue;
				index++;
			}
			//��縦 �����ؾ��� �׷��� �ϴ� ��ȯŸ���� �������ִ� tile�� �ٿ�ĳ�����ϴ��� �ƴϸ� �Լ��� ȣ���ؼ� ������Ʈ Ÿ������ ��ȯ�� �����־����
			else
			{
				State = ParseState::Error;
			}
		}
		break;
		case ParseState::ExpectValue:
		{
			//���� ������ �� �����
			//������������ accept�� ���¸� �ٲٸ� �ȵ�..
			//Ǫ�ù鵵 ���� �߸��Ȱ� ���� ���� ��ü �������� ���簡 �������
			//�� ���簡 ��� ���������� ����ɼ��ִ��� ���δ� 1�� Ȯ�������ʰ� �׳� �ְ��ִ� ���
			//���� ����ü�� �ѷ��δ°ɷ��Ͽ��� �����ִ� ����� ���縦 ������ �����ؾ���...
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
			//Ǫ�ù��� ���� �ؾ��� ������ �̸� ���� üũ�ϰ� ���ƿ°��� ������ ��ȿ�� üũ�� �ϰ� �Ʒ��� Ÿ���� ���� �߰��ϴ¹���� ���ؾ��ϴ°��� �ùٸ������
			//if (auto optRule = tile->ToRuleType()) //��...�̷��� ��ȿ���� ���⼭�ۿ� ������ �ȵǴ°ǰ�?
			//{
			//	result.push_back(ParsedRule{ currentSubject,*optRule });
			//	State = ParseState::Accept;
			//	index++;
			//
			//}
			//else if (auto optobj = tile->ToObjectType())
			//{
			//	result.push_back(ParsedRule{ currentSubject,*optobj}); //���� �����ؾ��ҵ�
			//	//�ذ����� ã�ƾ���.... ã��!!(variant)//����������...
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
			if (index < Chain.size())//������� �۴ٸ� ü�εǾ��ִ°� ������ ���� �������� �̵��ϱ����� ���¸�����
			{
				TextTile* tile = Chain[index];
				if (tile->ToVerbKind()) //������ ������·θ����
				{
					State = ParseState::ExpectVerb;
				}
				else if (tile->ToObjectType()) //obj���¶�� obj���·θ����
				{
					State = ParseState::Start;
				}
				else
				{
					State = ParseState::Error; //�װ͵� �ƴϸ� �������·� �����..
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
