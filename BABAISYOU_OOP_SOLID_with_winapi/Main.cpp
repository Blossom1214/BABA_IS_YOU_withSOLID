#include<iostream>
#include"Windows.h"
using namespace std;
void MoveCursorToTop() //ȭ�� �������� ���̱����� Ŀ�� �� ó������ �����ؼ� �ٽ� �׸��� �뵵�λ����
{
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void HideCursor() //Ŀ���� ���̵� �ؼ� �ڵ�(�ܼ�������â)���� ����
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
int main()
{
    
	return 0;
}