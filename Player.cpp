#include "Player.h"
#include <iostream>

// Player�� ��ġ ����
void Player::Init(int x, int y, Input* _Input)
{
	PlayerCurrentPosition.X = x;
	PlayerCurrentPosition.Y = y;
	PlayerNextPosition = PlayerCurrentPosition;
	bool Clear = false;

	DrawPlayer(_Input);
}

// �÷��̾� �׸��� (���� ��ġ ����, ���� ��ġ ���׶��)
void Player::DrawPlayer(Input* _Input)
{
	_Input->Gotoxy(PlayerCurrentPosition.X, PlayerCurrentPosition.Y);
	std::cout << " ";
	_Input->Gotoxy(PlayerNextPosition.X, PlayerNextPosition.Y);
	std::cout << "@";
}

// PlayerNextPosition�� '0'�̸� �̵�, �ƴϸ� ������
void Player::Move(char map[][80], Input* _Input, Tick* _Tick, Word* _Word)
{
	// 'W'Ű �Է�
	if (_Input->IsUpCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_UP, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.Y -= 1;

		// ���࿡ �÷��̾��� ���� ��ġ�� 'G' �̶�� Ŭ����
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// �̵��� �� �ִ� ��ġ���� üũ�ϰ� �ش� ��ǥ�� �̵� , �ƴϸ� �ǵ��ư���
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.Y = PlayerNextPosition.Y;
		}
		else
			PlayerNextPosition.Y = PlayerCurrentPosition.Y;
	}

	// 'S'Ű �Է�
	if (_Input->IsDownCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_DOWN, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.Y += 1;

		// ���࿡ �÷��̾��� ���� ��ġ�� 'G' �̶�� Ŭ����
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// �̵��� �� �ִ� ��ġ���� üũ�ϰ� �ش� ��ǥ�� �̵� , �ƴϸ� �ǵ��ư���
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.Y = PlayerNextPosition.Y;
		}
		else
			PlayerNextPosition.Y = PlayerCurrentPosition.Y;
	}

	// 'D'Ű �Է�
	if (_Input->IsRightCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_RIGHT, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.X += 1;

		// ���࿡ �÷��̾��� ���� ��ġ�� 'G' �̶�� Ŭ����
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// �̵��� �� �ִ� ��ġ���� üũ�ϰ� �ش� ��ǥ�� �̵� , �ƴϸ� �ǵ��ư���
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.X = PlayerNextPosition.X;
		}
		else
			PlayerNextPosition.X = PlayerCurrentPosition.X;
	}

	// AŰ �Է�
	if (_Input->IsLeftCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_LEFT, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.X -= 1;

		// ���࿡ �÷��̾��� ���� ��ġ�� 'G' �̶�� Ŭ����
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// �̵��� �� �ִ� ��ġ���� üũ�ϰ� �ش� ��ǥ�� �̵� , �ƴϸ� �ǵ��ư���
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.X = PlayerNextPosition.X;
		}
		else
			PlayerNextPosition.X = PlayerCurrentPosition.X;
	}
}

// Player�� ������ �� �ִ��� ������ �Ǵ�
bool Player::CanMove(char map[][80], Input* _Input, Word* _Word)
{
	if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == '0')
		return true;

	// ���� �÷��̾ ������ ��ǥ�� ���ĺ��� ������ �� ���ڰ� ������ �� �ִ��� üũ�ϰ� �̵���Ű��
	if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'W'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'A'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'L'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'O'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'P'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'E'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'N'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'C'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'S'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'B'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'U'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'R'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'D'
		|| map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'Y')
	{
		return CanMoveWord(map, _Input, _Word);
	}

	return false;
}

// ���� �̵��Ϸ��� ���� ���ĺ��� ������ �ش� ���ĺ��� ���� �̵���Ű��
bool Player::CanMoveWord(char map[][80], Input* _Input, Word* _Word)
{
	COORD WordPosition;
	char temp;

	// �Է� ���� �÷��̾��� ���� ��ǥ�� ���ڸ� ����
	temp = map[PlayerNextPosition.Y][PlayerNextPosition.X];

	// ���ڰ� �������� �̵��� ��ǥ�� �÷��̾��� ���� ��ǥ�� ���� ��ǥ�� ���� ����
	WordPosition.X = PlayerNextPosition.X - PlayerCurrentPosition.X;
	WordPosition.Y = PlayerNextPosition.Y - PlayerCurrentPosition.Y;

	// ���� �÷��̾��� �����ʿ� ���ڰ� �ְ� ���������� �о��� ��� ������ �������� �� �������� üũ, ������� �ƴ� ��쿡 false�ݳ��ϰ� ����
	if (map[PlayerNextPosition.Y + WordPosition.Y][PlayerNextPosition.X + WordPosition.X] != '0')
		return false;

	// �ʿ� �÷��̾��� ���� ��ǥ�� �� �������� �ٲٰ� " "���� ���
	map[PlayerNextPosition.Y][PlayerNextPosition.X] = '0';
	_Input->Gotoxy(PlayerNextPosition.X, PlayerNextPosition.Y);
	std::cout << " ";

	// ���ڰ� ������ ���� ��ǥ�� ����� ���ڸ� ���� �ش� ��ǥ�� �����ϰ� �ش� ��ǥ�� ���� ���
	map[PlayerNextPosition.Y + WordPosition.Y][PlayerNextPosition.X + WordPosition.X] = temp;
	_Input->Gotoxy((PlayerNextPosition.X + WordPosition.X), (PlayerNextPosition.Y + WordPosition.Y));
	std::cout << temp;

	// ���ڰ� �̵��ϴµ� ���������� ���������� �� �ٿ� �ִ� ���ڵ��� üũ�ϴ� �Լ� ����
	_Word->ChecktheWord(map, PlayerNextPosition.Y + WordPosition.Y);

	return true;
}