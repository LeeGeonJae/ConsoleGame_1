#include "Input.h"
#include <Windows.h>
#include <cassert>
#include <stdio.h>

void Input::Init()
{
	for (int i = 0; i < sizeof(inputKeyTable); i++)
		inputKeyTable[i] = false;

	// 깜박이는 커서를 좀 진정 시키자.
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
	cursorInfo.dwSize = 1; // 커서의 크기를 결정 (1~100 사이만 가능)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Input::Set(const int keyIdx, bool bOn)
{
	assert(keyIdx >= 0 && keyIdx < MAX_KEY); // 방어 코드를 작성하는 것에 익숙해져야 합니다.  배열을 다룰 때는 인덱스를 조심해야 합니다!!

	inputKeyTable[keyIdx] = bOn;			// bool 타입을 활용 합시다.
}

void Input::Gotoxy(int x, int y)
{
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

bool Input::IsSpaceCmdOn()
{
	return inputKeyTable[ESCAPE_KEY_INDEX];
}

bool Input::IsLeftCmdOn()
{
	return inputKeyTable[USER_CMD_LEFT];
}

bool Input::IsRightCmdOn()
{
	return inputKeyTable[USER_CMD_RIGHT];
}

bool Input::IsUpCmdOn()
{
	return inputKeyTable[USER_CMD_UP];
}

bool Input::IsDownCmdOn()
{
	return inputKeyTable[USER_CMD_DOWN];
}

void Input::UpdateInput(bool* Input)
{
	if (GetAsyncKeyState(' ') & 0x8000) //스페이스 바
	{
		Set(ESCAPE_KEY_INDEX, true);
		*Input = false;					//입력을 받았다 _Input->FirstInput의 원본 건들기
	}

	if (GetAsyncKeyState('A') & 0x8000) //왼쪽 'A'
	{
		Set(USER_CMD_LEFT, true);
		*Input = false;
	}

	if (GetAsyncKeyState('D') & 0x8000) //오른쪽 'D'
	{
		Set(USER_CMD_RIGHT, true);
		*Input = false;
	}

	if (GetAsyncKeyState('W') & 0x8000) //위 'W'
	{
		Set(USER_CMD_UP, true);
		*Input = false;
	}

	if (GetAsyncKeyState('S') & 0x8000) //아래 'S'
	{
		Set(USER_CMD_DOWN, true);
		*Input = false;
	}
}