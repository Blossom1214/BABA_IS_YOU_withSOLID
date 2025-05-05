#pragma once
#include <functional>
struct Position
{
	int s_x;//열
	int s_y;//행
	Position(int x = 0, int y = 0) : s_x(x), s_y(y)
	{

	}
	Position operator+(const Position& other) const //덧셈연산
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
			return hash<int>()(p.s_x) ^ (hash<int>()(p.s_y) << 1); //해싱결합시 충돌을 피하기위해 <<1사용
		}
	};
}