#include "Eremy.h"

// 적 초기 세팅 ( 위치 , 그려주기)
void Eremy::Init(int x, int y, Input* _Input)
{
	EremyCurrentPosition.X = x;
	EremyCurrentPosition.Y = y;
	EremyNextPosition = EremyCurrentPosition;
	Delete = false;

	DrawEremy(_Input);
}

// 이동하는 함수
void Eremy::Move(char map[][80], Tick* _Tick, Input* _Input, int Speed)
{
	// 적 이동하기 ( Speed 값에 따라서 속도 변환, 3을 만나면 막히고, G를 만나면 G 없애기 )
	if (_Tick->fixedEnemyCount >= Speed && Delete != true)
	{
		EremyNextPosition.X += 1;

		if (map[EremyNextPosition.Y][EremyNextPosition.X] == '3')
			EremyNextPosition = EremyCurrentPosition;
		else if (map[EremyNextPosition.Y][EremyNextPosition.X] == 'G')
		{
			map[EremyNextPosition.Y][EremyNextPosition.X] = '0';
			Delete = true;
			_Input->Gotoxy(EremyCurrentPosition.X, EremyCurrentPosition.Y);
			std::wcout << " ";
			_Input->Gotoxy(EremyNextPosition.X, EremyNextPosition.Y);
			std::wcout << " ";
		}
		else
		{
			DrawEremy(_Input);
			EremyCurrentPosition = EremyNextPosition;
		}

		_Tick->fixedEnemyCount = 0;
	}
}

// 적 그려주는 함수
void Eremy::DrawEremy(Input* _Input)
{
	_Input->Gotoxy(EremyCurrentPosition.X, EremyCurrentPosition.Y);
	std::wcout << L" ";
	_Input->Gotoxy(EremyNextPosition.X, EremyNextPosition.Y);
	std::wcout << L"몹";
}