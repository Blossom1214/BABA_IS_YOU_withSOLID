#include "InputManager.h"
#include<conio.h>
Direction InputManager::GetInput()
{
	char cInput = _getch();//키입력 받기

	switch (cInput)
	{
	case 'w':
		_lastInput = Direction::UP;
		break;
	case 'a':
		_lastInput = Direction::LEFT;
		break;
	case 's':
		_lastInput = Direction::DOWN;
		break;
	case 'd':
		_lastInput = Direction::RIGHT;
		break;
	case 'r':
		_lastInput = Direction::RESET;
		break;
	case 27:
		_lastInput = Direction::PAUSE;
		break;
	default:
		_lastInput = Direction::NONE;
		break;
	}
	return _lastInput;
}