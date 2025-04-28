#pragma once
#include "Position.h"
#include "Direction.h"

class InputManager
{
public:
	Direction GetInput();//입력한값을 반환하는 함수
	Direction GetLastInput() const { return _lastInput; }//마지막 입력했던값
private:
	Direction _lastInput = Direction::NONE;//내가 입력한 키 getinput의 반환값(상태를 저장하는 변수) 이걸 playablechar에 매개변수로 전달하여 입력을 받음과동시에 어떤 입력이 받아졌는지 확인해야함
};