#pragma once
#include "Tile.h"
class TextTile :public Tile
{
public:
	void SetTile(ObjectType type)override; //해당위치를 읽었을때 오브젝트타입이 텍스트 타입이면 텍스트 롤에다가 저장...
protected:
	TextRole _Textrole; //텍스트 롤을 저장하는 역할을함..

};

