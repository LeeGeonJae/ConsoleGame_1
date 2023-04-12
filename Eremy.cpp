#include "Eremy.h"

// �� �ʱ� ���� ( ��ġ , �׷��ֱ�)
void Eremy::Init(int x, int y, Input* _Input)
{
	EremyCurrentPosition.X = x;
	EremyCurrentPosition.Y = y;
	EremyNextPosition = EremyCurrentPosition;
	Delete = false;

	DrawEremy(_Input);
}

// �̵��ϴ� �Լ�
void Eremy::Move(char map[][80], Tick* _Tick, Input* _Input, int Speed)
{
	// �� �̵��ϱ� ( Speed ���� ���� �ӵ� ��ȯ, 3�� ������ ������, G�� ������ G ���ֱ� )
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

// �� �׷��ִ� �Լ�
void Eremy::DrawEremy(Input* _Input)
{
	_Input->Gotoxy(EremyCurrentPosition.X, EremyCurrentPosition.Y);
	std::wcout << L" ";
	_Input->Gotoxy(EremyNextPosition.X, EremyNextPosition.Y);
	std::wcout << L"��";
}