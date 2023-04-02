#include "Engine.h"
#include <Windows.h>
#include <conio.h>

int KeyControl()
{
    char temp = _getch();

    if (temp == 'w' || temp == 'W')
        return UP;
    else if (temp == 'a' || temp == 'A')
        return LEFT;
    else if (temp == 's' || temp == 'S')
        return DOWN;
    else if (temp == 'd' || temp == 'D')
        return RIGHT;
    else if (temp == ' ')
        return SUBMIT;
}

void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void init()
{
    system("mode con cols=56 lines=20 | title 게 임 제 목 ");

    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void setColor(int forground, int background)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}