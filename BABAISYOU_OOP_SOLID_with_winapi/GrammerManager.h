#pragma once
#include <vector>
//#include<optional>
#include "ObjectType.h"
#include "RuleType.h"
#include "TextTile.h"
#include "VerbKind.h"
//문장해석기
class GrammerManager 
{
public:
	struct ParsedRule //문장의 해석 결과(구조체로 묶어서 반환)
	{
		ObjectType _subject;//해당하는 주어
		RuleType _rule;//해당하는상태
	};
	enum class ParseState //파서함수의 상태
	{
		Start, //시작점
		ExpectVerb, //is,has 와같은 동사
		ExpectValue, //상태나 명사
		Accept, //다음 문제로 진행할수있는지에대한여부
		Error //불가하면...반환하기위함
	};

	//옵셔널을 사용해서 해당하는 값이 유효하다면 반환 값이 불가능하다면 반환하지않음..
	//static std::optional<ParsedRule> parse(const std::vector<TextTile*>& Chain);
	//옵셔널이란?
	//값이없더라도 에러나 그런것을 표기하지않고... 값이 없다면 없을때값을 반환하고 있으면 해당값을반환하는 컨테이너
	//따라서 현재상황에선 해당하는 문장이 성립한다면 다시 해당하는 주어랑 룰을 반환하여 룰매니저가 적용시킬수있게함
	//아니라면 룰이 거짓이됨..
	//swift에서는 ?로 사용했던 기억을 더듬어 혹시나 있을까 찾아봄..
	//결과는 c++17이상부터 사용가능

	//해당옵셔널은 단일 대상으로는 유리하지만 다중대상으로는 불리한구조를 알게됨... 벡터로 구현후 옵셔널으로도 변형이가능하다면 재작성해볼듯..
	static std::vector<ParsedRule> parseFSM(const std::vector<TextTile*>& Chain);
	//유한 상태 기계
private:
	//static bool IsVaildNoun(const TextTile* tile);
	//static bool IsVaildVerb(const TextTile* tile);
	//static bool IsVaildState(const TextTile* tile);
	//static bool IsVaildConnector(const TextTile* tile); //문장연결동사(and)인지 확인

};


//fsm구조로 만들어야함
//실시간 최초 둘다 사용할꺼고
//이건 [0]명사[1]동사(is일수도있고 다른 동사가 올수도있음)
//그때그때 해당 동사의 문법이 맞는지 확인
//[2]상태나 명사 [3]동사(이때도 확인하되...연결이 가능한지 절차를 확인해야함
//체이닝을 통해 일단 넘겨받고 문법적으로 합리적이다 판단하면 적용해야함
//[4]명사나 상태!(다만 앞의 동사가 어떻게 오는지에따라다름...)

