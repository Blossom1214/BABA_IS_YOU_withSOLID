#pragma once
#include <functional>
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
	bool operator==(const Position& other) const noexcept {
		return s_x == other.s_x && s_y == other.s_y;
	}
};
namespace std {
	template<>
	struct hash<Position> {
		size_t operator()(const Position& p) const noexcept 
		{
			return hash<int>()(p.s_x) ^ (hash<int>()(p.s_y) << 1); //�ؽ̰��ս� �浹�� ���ϱ����� <<1���
		}
	};
}