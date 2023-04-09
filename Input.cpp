#include "Input.h"
#include <Windows.h>
#include <cassert>
#include <stdio.h>

void Input::Init()
{
	for (int i = 0; i < sizeof(inputKeyTable); i++)
		inputKeyTable[i] = false;

	// �����̴� Ŀ���� �� ���� ��Ű��.
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0; // Ŀ���� ������ ���� ����(0�̸� �Ⱥ���, 0���� ���� ���̸� ����)
	cursorInfo.dwSize = 1; // Ŀ���� ũ�⸦ ���� (1~100 ���̸� ����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Input::Set(const int keyIdx, bool bOn)
{
	assert(keyIdx >= 0 && keyIdx < MAX_KEY); // ��� �ڵ带 �ۼ��ϴ� �Ϳ� �ͼ������� �մϴ�.  �迭�� �ٷ� ���� �ε����� �����ؾ� �մϴ�!!

	inputKeyTable[keyIdx] = bOn;			// bool Ÿ���� Ȱ�� �սô�.
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
	if (GetAsyncKeyState(' ') & 0x8000) //�����̽� ��
	{
		Set(ESCAPE_KEY_INDEX, true);
		*Input = false;					//�Է��� �޾Ҵ� _Input->FirstInput�� ���� �ǵ��
	}

	if (GetAsyncKeyState('A') & 0x8000) //���� 'A'
	{
		Set(USER_CMD_LEFT, true);
		*Input = false;
	}

	if (GetAsyncKeyState('D') & 0x8000) //������ 'D'
	{
		Set(USER_CMD_RIGHT, true);
		*Input = false;
	}

	if (GetAsyncKeyState('W') & 0x8000) //�� 'W'
	{
		Set(USER_CMD_UP, true);
		*Input = false;
	}

	if (GetAsyncKeyState('S') & 0x8000) //�Ʒ� 'S'
	{
		Set(USER_CMD_DOWN, true);
		*Input = false;
	}
}