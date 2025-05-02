#include "GrammerManager.h"

std::vector<GrammerManager::ParsedRule> GrammerManager::parseFSM(const std::vector<TextTile*>& Chain)
{
	size_t i = 0;//ü���� ��ȸ�ϴ� �뵵�� �ϴ� �����غ�(�ε����� ++�ؼ� ����ĭ�� Ž���ؾ���)
	ParseState State = ParseState::Start;//fsm�� ����!
	ObjectType currentSubject{};//��������..(������ ���� ���� �̰��� �˰��־���ϱ⶧��)
	bool hasSubject = false; //���°� ��縦 ������ �Ǵ»�Ȳ�� �˱�����
	VerbKind currentVerb = VerbKind::Invalid;//�̹��� ������
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
				hasSubject = true; //������ �ٲپ���
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
			if (auto optObj = tile->ToVerbKind()) //��...�̷��� ��ȿ���� ���⼭�ۿ� ������ �ȵǴ°ǰ�?
			{
				currentVerb = *optObj;//�������� ����... ��ȯ���� optional��ü�̱⶧���� �ش簴ü�� ���� ����ϱ����� ��������
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
			TextTile* tile = Chain[index];
			if (auto optObj = tile->ToRuleType()) //��...�̷��� ��ȿ���� ���⼭�ۿ� ������ �ȵǴ°ǰ�?
			{
				//�������� ����... ��ȯ���� optional��ü�̱⶧���� �ش簴ü�� ���� ����ϱ����� ��������
				State = ParseState::Accept;
				index++;

			}
			//��縦 �����ؾ��� �׷��� �ϴ� ��ȯŸ���� �������ִ� tile�� �ٿ�ĳ�����ϴ��� �ƴϸ� �Լ��� ȣ���ؼ� ������Ʈ Ÿ������ ��ȯ�� �����־����
			else
			{
				State = ParseState::Error;
			}
		}
			break;
		case ParseState::Accept:
		{
			//����� ���������� ������
			//������� ȣ���� ���ؼ� ���? �ش�����̶�°� ü���� �޾Ƽ�...
			//�ش繮���� ������ ���ɼ��� �ǹ��ϰ� �ᱹ expectVerb�� �����ٴ°�!
			
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
