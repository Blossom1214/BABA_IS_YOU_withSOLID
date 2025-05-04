#pragma once
#include "Position.h"
struct NotifyFlag //각각 오브젝트베이스타일에 생성될 플래그임...
{
	Position pos; //위치를 체크하기위함
	bool isDirtyFlag = false; //현재상태
	void SetDirty() { isDirtyFlag = true; };//상태변화함
	bool isDirty() const { return isDirtyFlag; };//상태가어떤지체크
	void initDirtyFlag() { isDirtyFlag = false; } //상태초기화
};