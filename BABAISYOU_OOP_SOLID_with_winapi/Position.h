#pragma once
struct Position
{
	int s_x;//��
	int s_y;//��
	Position(int x = 0, int y = 0) : s_x(x), s_y(y)
	{

	}
	Position operator+(const Position& other) const //��������
	{
		return Position(s_x + other.s_x, s_y + other.s_y);
	}
};