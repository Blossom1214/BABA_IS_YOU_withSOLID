#pragma once
#include "Position.h"
struct NotifyFlag //���� ������Ʈ���̽�Ÿ�Ͽ� ������ �÷�����...
{
	Position pos; //��ġ�� üũ�ϱ�����
	bool isDirtyFlag = false; //�������
	void SetDirty() { isDirtyFlag = true; };//���º�ȭ��
	bool isDirty() const { return isDirtyFlag; };//���°����üũ
	void initDirtyFlag() { isDirtyFlag = false; } //�����ʱ�ȭ
};