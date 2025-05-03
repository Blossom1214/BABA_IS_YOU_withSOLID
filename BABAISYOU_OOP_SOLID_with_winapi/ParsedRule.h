#pragma once
#include "ObjectType.h"
#include "RuleType.h"
#include "TextTile.h"
#include "VerbKind.h"
#include <variant>
struct ParsedRule //������ �ؼ� ���(����ü�� ��� ��ȯ)
{
	ObjectType _subject;//�ش��ϴ� �־�
	std::variant<ObjectType, RuleType> _rule;//�ش��ϴ»���
	VerbKind _verb; //������ ����(�ݵ�� �ʿ�)

};