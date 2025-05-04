#pragma once
#include<unordered_set>
#include "Position.h"

class NotificationManager
{
public:
	void RegisterDirtyPosition(const Position& pos);//특정위치가 변경됨을 등록함
	void ProcessDirtyFlags(class RuleManager& manager);//register에 저장된것들을 이제 룰매니저로 보내서 업데이트 작업을 진행해!
	bool IsEmpty() const; //맵에 변화상태가있는지 여부체크용(없으면 굳이 연산할필요가없기때문에 만듬)
	void RegisterClear();//보관하고있던 레지스터를 비움
private:

	std::unordered_set<Position> _dirtyPositions;

};

//추가 하는 기준으로써 if object의 notifyflag의 isdirty가 true면 해당 pos를 저장하게됨
//이 기준은 어디서 적용되야 하는가
//1)움직이기전에
//2)움직이고나서
//3)움직이는 동안

//1번아니면 3번인데 사실상 3번이다
//3번을 택해서 trymove를하는동안 해당 타일이 이동하여서 생긴것들...에대해서 처리해야하는 문제가생김
// 노티파이가 울리는 기준이 현재 위치로부터인지
//아니면 움직여질수있는 위치여야하는지를 지금 생각해봐야함 움직여진 위치로 체크하면 반응이 늦음
//따라서 현재위치를 반환하고 그에따른 변화를 계산해서 움직인뒤 그것을 반영하는 식으로 해야할꺼같음
//이유는 한번에 모든 작업을 처리해야하는데 이게 타일의 변화를 일괄적이아닌 push같은 재귀적 호출도 예상을 해야함

//다시설명하면 trymove가 완전 가능해! 라고하면 나이제 움직일수있어!
//그러니 이제 너가 누른방향으로 움직일꺼야라고 된것
//확실히 움직일수있기때문에 현재위치로부터 다음위치를 알수있게 되는거고
//그위치에 있는블록이 오브젝트들이라면 이제 notify가 차례대로 알람을 보내게됨
//즉 현재위치의 블록이 변화하는 작업이기때문에 해당 direction으로 가는 곳을 확인하고 이블록이 이쪽으로가면 어떠한 상태가 발생한다 라고 예측?
//예측보다는 사실상.... 확정난결과를 표현작업을 안한거기때문에 그사이에서 계산하게되는것...