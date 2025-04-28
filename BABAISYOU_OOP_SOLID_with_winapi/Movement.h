#pragma once
#include "InputManager.h"
#include "Position.h"
class Movement
{
public:
	static Position Vector(Direction dir)
	{
		switch (dir)
		{
		case Direction::UP:
			return Position(0, -1);
		case Direction::DOWN:
			return Position(0, 1);
		case Direction::RIGHT:
			return Position(1, 0);
		case Direction::LEFT:
			return Position(-1, 0);
		default:
			return Position(0, 0);
		}
	}
};