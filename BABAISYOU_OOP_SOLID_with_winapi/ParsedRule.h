#pragma once
#include "ObjectType.h"
#include "RuleType.h"
#include "TextTile.h"
#include "VerbKind.h"
#include <variant>
struct ParsedRule //문장의 해석 결과(구조체로 묶어서 반환)
{
	ObjectType _subject;//해당하는 주어
	std::variant<ObjectType, RuleType> _rule;//해당하는상태
	VerbKind _verb; //문장의 동사(반드시 필요)

};