#pragma once
#include "Tile.h"
#include "TextRole.h"
class TextTile :public Tile//����� �ؽ�ƮŸ���� �з��ϴ� �۾��ϰ� �ؽ�ƮŸ���� ���������� �������ϴ°͵鸸 �������
{
public:
	void CheckPosTextType();//�ش���ġ�� �� ������Ʈ�� textŸ���̶�� textrole�� ������..
	
protected:
	TextRole _Textrole; //�ؽ�Ʈ ���� �����ϴ� ��������..

};

