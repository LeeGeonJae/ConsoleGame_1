#include "Input.h"
#include <Windows.h>
#include <cassert>

void Input::Init()
{
	for (int i = 0; i < sizeof(inputKeyTable); i++)
		inputKeyTable[i] = false;
}

void Input::Set(const int keyIdx, bool bOn)
{
	assert(keyIdx >= 0 && keyIdx < MAX_KEY); // 방어 코드를 작성하는 것에 익숙해져야 합니다.  배열을 다룰 때는 인덱스를 조심해야 합니다!!

	inputKeyTable[keyIdx] = bOn;			// bool 타입을 활용 합시다.
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

void Input::UpdateInput()
{
	if (GetAsyncKeyState(' ') & 0x8000)
	{
		Set(ESCAPE_KEY_INDEX, true);
	}

	if (GetAsyncKeyState('A') & 0x8000) //왼쪽 'A'
	{
		Set(USER_CMD_LEFT, true);
	}

	if (GetAsyncKeyState('D') & 0x8000) //오른쪽 'D'
	{
		Set(USER_CMD_RIGHT, true);
	}

	if (GetAsyncKeyState('W') & 0x8000) //위 'W'
	{
		Set(USER_CMD_UP, true);
	}

	if (GetAsyncKeyState('S') & 0x8000) //아래 'S'
	{
		Set(USER_CMD_DOWN, true);
	}
}
