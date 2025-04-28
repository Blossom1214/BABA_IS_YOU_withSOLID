#pragma once
#include "Position.h"
#include "Direction.h"

class InputManager
{
public:
	Direction GetInput();//�Է��Ѱ��� ��ȯ�ϴ� �Լ�
	Direction GetLastInput() const { return _lastInput; }//������ �Է��ߴ���
private:
	Direction _lastInput = Direction::NONE;//���� �Է��� Ű getinput�� ��ȯ��(���¸� �����ϴ� ����) �̰� playablechar�� �Ű������� �����Ͽ� �Է��� ���������ÿ� � �Է��� �޾������� Ȯ���ؾ���
};