#include "Player.h"
#include <iostream>

// Player의 위치 세팅
void Player::Init(int x, int y, Input* _Input)
{
	PlayerCurrentPosition.X = x;
	PlayerCurrentPosition.Y = y;
	PlayerNextPosition = PlayerCurrentPosition;
	bool Clear = false;

	DrawPlayer(_Input);
}

// 플레이어 그리기 (이전 위치 공백, 다음 위치 동그라미)
void Player::DrawPlayer(Input* _Input)
{
	_Input->Gotoxy(PlayerCurrentPosition.X, PlayerCurrentPosition.Y);
	std::cout << " ";
	_Input->Gotoxy(PlayerNextPosition.X, PlayerNextPosition.Y);
	std::cout << "@";
}

// PlayerNextPosition이 '0'이면 이동, 아니면 가만히
void Player::Move(char map[][80], Input* _Input, Tick* _Tick, Word* _Word)
{
	// 'W'키 입력
	if (_Input->IsUpCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_UP, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.Y -= 1;

		// 만약에 플레이어의 다음 위치가 'G' 이라면 클리어
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// 이동할 수 있는 위치인지 체크하고 해당 좌표로 이동 , 아니면 되돌아가기
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.Y = PlayerNextPosition.Y;
		}
		else
			PlayerNextPosition.Y = PlayerCurrentPosition.Y;
	}

	// 'S'키 입력
	if (_Input->IsDownCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_DOWN, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.Y += 1;

		// 만약에 플레이어의 다음 위치가 'G' 이라면 클리어
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// 이동할 수 있는 위치인지 체크하고 해당 좌표로 이동 , 아니면 되돌아가기
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.Y = PlayerNextPosition.Y;
		}
		else
			PlayerNextPosition.Y = PlayerCurrentPosition.Y;
	}

	// 'D'키 입력
	if (_Input->IsRightCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_RIGHT, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.X += 1;

		// 만약에 플레이어의 다음 위치가 'G' 이라면 클리어
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// 이동할 수 있는 위치인지 체크하고 해당 좌표로 이동 , 아니면 되돌아가기
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.X = PlayerNextPosition.X;
		}
		else
			PlayerNextPosition.X = PlayerCurrentPosition.X;
	}

	// A키 입력
	if (_Input->IsLeftCmdOn() && _Tick->PlayerMove)
	{
		_Input->Set(USER_CMD_LEFT, false);
		_Tick->PlayerMove = false;

		PlayerNextPosition.X -= 1;

		// 만약에 플레이어의 다음 위치가 'G' 이라면 클리어
		if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == 'G')
			Clear = true;

		// 이동할 수 있는 위치인지 체크하고 해당 좌표로 이동 , 아니면 되돌아가기
		if (CanMove(map, _Input, _Word))
		{
			DrawPlayer(_Input);
			PlayerCurrentPosition.X = PlayerNextPosition.X;
		}
		else
			PlayerNextPosition.X = PlayerCurrentPosition.X;
	}
}

// Player가 움직일 수 있는지 없는지 판단
bool Player::CanMove(char map[][80], Input* _Input, Word* _Word)
{
	if (map[PlayerNextPosition.Y][PlayerNextPosition.X] == '0')
		return true;

	// 만약 플레이어가 움직일 좌표에 알파벳이 있으면 그 문자가 움직일 수 있는지 체크하고 이동시키기
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

// 만약 이동하려는 곳에 알파벳이 있으면 해당 알파벳도 같이 이동시키기
bool Player::CanMoveWord(char map[][80], Input* _Input, Word* _Word)
{
	COORD WordPosition;
	char temp;

	// 입력 받은 플레이어의 다음 좌표에 문자를 저장
	temp = map[PlayerNextPosition.Y][PlayerNextPosition.X];

	// 문자가 다음으로 이동할 좌표를 플레이어의 다음 좌표와 현재 좌표를 빼서 저장
	WordPosition.X = PlayerNextPosition.X - PlayerCurrentPosition.X;
	WordPosition.Y = PlayerNextPosition.Y - PlayerCurrentPosition.Y;

	// 만약 플레이어의 오른쪽에 문자가 있고 오른쪽으로 밀었을 경우 문자의 오른쪽이 빈 공간인지 체크, 빈공간이 아닐 경우에 false반납하고 종료
	if (map[PlayerNextPosition.Y + WordPosition.Y][PlayerNextPosition.X + WordPosition.X] != '0')
		return false;

	// 맵에 플레이어의 다음 좌표를 빈 공간으로 바꾸고 " "으로 출력
	map[PlayerNextPosition.Y][PlayerNextPosition.X] = '0';
	_Input->Gotoxy(PlayerNextPosition.X, PlayerNextPosition.Y);
	std::cout << " ";

	// 문자가 움직일 다음 좌표에 저장된 문자를 맵의 해당 좌표에 저장하고 해당 좌표에 문자 출력
	map[PlayerNextPosition.Y + WordPosition.Y][PlayerNextPosition.X + WordPosition.X] = temp;
	_Input->Gotoxy((PlayerNextPosition.X + WordPosition.X), (PlayerNextPosition.Y + WordPosition.Y));
	std::cout << temp;

	// 문자가 이동하는데 성공했으면 마지막으로 그 줄에 있는 문자들을 체크하는 함수 실행
	_Word->ChecktheWord(map, PlayerNextPosition.Y + WordPosition.Y);

	return true;
}