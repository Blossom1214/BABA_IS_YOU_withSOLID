#pragma once
#include "Tile.h"
class TextTile :public Tile
{
public:
	void SetTile(ObjectType type)override; //�ش���ġ�� �о����� ������ƮŸ���� �ؽ�Ʈ Ÿ���̸� �ؽ�Ʈ �ѿ��ٰ� ����...
protected:
	TextRole _Textrole; //�ؽ�Ʈ ���� �����ϴ� ��������..

};

