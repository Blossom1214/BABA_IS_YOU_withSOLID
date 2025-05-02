#pragma once
#include <vector>
//#include<optional>
#include "ObjectType.h"
#include "RuleType.h"
#include "TextTile.h"
#include "VerbKind.h"
//�����ؼ���
class GrammerManager 
{
public:
	struct ParsedRule //������ �ؼ� ���(����ü�� ��� ��ȯ)
	{
		ObjectType _subject;//�ش��ϴ� �־�
		RuleType _rule;//�ش��ϴ»���
	};
	enum class ParseState //�ļ��Լ��� ����
	{
		Start, //������
		ExpectVerb, //is,has �Ͱ��� ����
		ExpectValue, //���³� ���
		Accept, //���� ������ �����Ҽ��ִ��������ѿ���
		Error //�Ұ��ϸ�...��ȯ�ϱ�����
	};

	//�ɼų��� ����ؼ� �ش��ϴ� ���� ��ȿ�ϴٸ� ��ȯ ���� �Ұ����ϴٸ� ��ȯ��������..
	//static std::optional<ParsedRule> parse(const std::vector<TextTile*>& Chain);
	//�ɼų��̶�?
	//���̾����� ������ �׷����� ǥ�������ʰ�... ���� ���ٸ� ���������� ��ȯ�ϰ� ������ �ش簪����ȯ�ϴ� �����̳�
	//���� �����Ȳ���� �ش��ϴ� ������ �����Ѵٸ� �ٽ� �ش��ϴ� �־�� ���� ��ȯ�Ͽ� ��Ŵ����� �����ų���ְ���
	//�ƴ϶�� ���� �����̵�..
	//swift������ ?�� ����ߴ� ����� ����� Ȥ�ó� ������ ã�ƺ�..
	//����� c++17�̻���� ��밡��

	//�ش�ɼų��� ���� ������δ� ���������� ���ߴ�����δ� �Ҹ��ѱ����� �˰Ե�... ���ͷ� ������ �ɼų����ε� �����̰����ϴٸ� ���ۼ��غ���..
	static std::vector<ParsedRule> parseFSM(const std::vector<TextTile*>& Chain);
	//���� ���� ���
private:
	//static bool IsVaildNoun(const TextTile* tile);
	//static bool IsVaildVerb(const TextTile* tile);
	//static bool IsVaildState(const TextTile* tile);
	//static bool IsVaildConnector(const TextTile* tile); //���忬�ᵿ��(and)���� Ȯ��

};


//fsm������ ��������
//�ǽð� ���� �Ѵ� ����Ҳ���
//�̰� [0]���[1]����(is�ϼ����ְ� �ٸ� ���簡 �ü�������)
//�׶��׶� �ش� ������ ������ �´��� Ȯ��
//[2]���³� ��� [3]����(�̶��� Ȯ���ϵ�...������ �������� ������ Ȯ���ؾ���
//ü�̴��� ���� �ϴ� �Ѱܹް� ���������� �ո����̴� �Ǵ��ϸ� �����ؾ���
//[4]��糪 ����!(�ٸ� ���� ���簡 ��� ������������ٸ�...)

