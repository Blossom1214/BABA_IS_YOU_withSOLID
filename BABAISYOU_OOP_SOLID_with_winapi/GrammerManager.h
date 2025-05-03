#pragma once
#include <vector>
#include "ObjectType.h"
#include "RuleType.h"
#include "TextTile.h"
#include "VerbKind.h"
#include "VerbTextToTile.h"
#include <variant>
#include "ParsedRule.h"
//문장해석기
class GrammerManager 
{
public:
	enum class ParseState //파서함수의 상태
	{
		Start, //시작점
		ExpectVerb, //is,has 와같은 동사
		ExpectValue, //상태나 명사
		Accept, //다음 문제로 진행할수있는지에대한여부
		Error //불가하면...반환하기위함
	};
	//해당옵셔널은 단일 대상으로는 유리하지만 다중대상으로는 불리한구조를 알게됨... 벡터로 구현후 옵셔널으로도 변형이가능하다면 재작성해볼듯..
	static std::vector<ParsedRule> parseFSM(const std::vector<TextTile*>& Chain);
	//유한 상태 기계
private:
	static bool IsVaildNoun(const TextTile* tile);
	static bool IsVaildVerb(const TextTile* tile);
	static bool IsVaildState(const TextTile* tile);
	//static bool IsVaildConnector(const TextTile* tile); //문장연결동사(and)인지 확인

};


//fsm구조로 만들어야함
//실시간 최초 둘다 사용할꺼고
//이건 [0]명사[1]동사(is일수도있고 다른 동사가 올수도있음)
//그때그때 해당 동사의 문법이 맞는지 확인
//[2]상태나 명사 [3]동사(이때도 확인하되...연결이 가능한지 절차를 확인해야함
//체이닝을 통해 일단 넘겨받고 문법적으로 합리적이다 판단하면 적용해야함
//[4]명사나 상태!(다만 앞의 동사가 어떻게 오는지에따라다름...)
//일단 해결은했는데 지금 중요한건 체이닝해서 들어온 문장배열의 위치까진 좋은데
//그게 어떤 역할로 룰에 적용을해야하는지를 모르는상태
//따라서 해당동사가 어떻게 작용하여 주어에 어떻게 상태든 명사든 부여해야하는지를
//현재 fsm 문장해석기는 모르는상태
//결국 만들어주어야함...



//is같은경우에도 결국 3칸을 탐색은 무조건적으로 다하고
//저장한값을...가지고 is로 가서 해당체인이 합리적인가를 따져서 반환하였을때 거짓이면 사실상 그문장은 합리적이지 않게됨
//다만 이제 주의할거는... 아직 예외처리를 덜한게 잇음 명사 is 명사 is 상태 이런경우에는 최초탐색시
//문제가 생길 여지가 잇음 명사의 위치를 다 기억하기때문에 이미 명사는 저 다른 명사로 대체되어있는상태이기때문에
//해당 오브젝트에음...플레이상으로는 문제가 없을꺼같은데 
//프로그램 내부적으로는 두명사에 두개의 타입이 다들어가있는상태로 판단하게 될것임
//이동생성자를 통해서 전달참조를 하던가...
//아니면 다른 방법을 또다시 생각해봐야겟음...