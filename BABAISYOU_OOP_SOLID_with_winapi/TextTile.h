#pragma once
#include "Tile.h"
#include "TextRole.h"
class TextTile :public Tile//여기는 텍스트타일을 분류하는 작업하고 텍스트타일이 공통적으로 가져야하는것들만 있으면됨
{
public:
	void CheckPosTextType();//해당위치에 들어간 오브젝트가 text타입이라면 textrole에 저장함..
	
protected:
	TextRole _Textrole; //텍스트 롤을 저장하는 역할을함..

};

