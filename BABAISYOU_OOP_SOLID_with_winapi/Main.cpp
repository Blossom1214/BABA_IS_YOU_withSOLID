// main.cpp
#include <iostream>
#include "TileMap.h"
#include "RuleManager.h"
#include "GrammerManager.h"
#include "NounTextToTile.h"
#include "VerbTextToTile.h"
#include "StateTextToTile.h"

#include"Windows.h"
using namespace std;

void MoveCursorToTop() //화면 깜밖임을 줄이기위해 커서 를 처음으로 셋팅해서 다시 그리는 용도로사용함
{
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void HideCursor() //커서를 하이딩 해서 핸들(콘솔윈도우창)에서 지움
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
