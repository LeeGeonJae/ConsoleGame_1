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
	assert(keyIdx >= 0 && keyIdx < MAX_KEY); // ��� �ڵ带 �ۼ��ϴ� �Ϳ� �ͼ������� �մϴ�.  �迭�� �ٷ� ���� �ε����� �����ؾ� �մϴ�!!

	inputKeyTable[keyIdx] = bOn;			// bool Ÿ���� Ȱ�� �սô�.
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

	if (GetAsyncKeyState('A') & 0x8000) //���� 'A'
	{
		Set(USER_CMD_LEFT, true);
	}

	if (GetAsyncKeyState('D') & 0x8000) //������ 'D'
	{
		Set(USER_CMD_RIGHT, true);
	}

	if (GetAsyncKeyState('W') & 0x8000) //�� 'W'
	{
		Set(USER_CMD_UP, true);
	}

	if (GetAsyncKeyState('S') & 0x8000) //�Ʒ� 'S'
	{
		Set(USER_CMD_DOWN, true);
	}
}