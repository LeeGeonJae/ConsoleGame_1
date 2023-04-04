#include "Stage.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void Stage::Menu(Input* _Input)
{
	// �����̼� �迭 ����
	Narrationarrlen = 6;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Hello?";
	narrationarr[1] = "I'm the fairy of the tutorial";
	narrationarr[2] = "Welcome to my console game";
	narrationarr[3] = "\'W\' is up, \'S\' is down, \'D\' is right, \'A\' is left";
	narrationarr[4] = "and \'space bar\' is choice";
	narrationarr[5] = "I hope you play a good game";

	_Input->Gotoxy(1, 4);
	cout << "    #     #                         #     # ###                           " << endl;
	cout << "     #  #  #  ####  #####  #####     #  #  #  #  ######   ##   #####  #####     " << endl;
	cout << "     #  #  # #    # #    # #    #    #  #  #  #      #   #  #  #    # #    #    " << endl;
	cout << "     #  #  # #    # #    # #    #    #  #  #  #     #   #    # #    # #    #    " << endl;
	cout << "     #  #  # #    # #####  #    #    #  #  #  #    #    ###### #####  #    #    " << endl;
	cout << "     #  #  # #    # #   #  #    #    #  #  #  #   #     #    # #   #  #    #    " << endl;
	cout << "      ## ##   ####  #    # #####      ## ##  ### ###### #    # #    # #####     " << endl;

	if (Once == false)
	{
		_Input->Gotoxy(x - 2, 15);
		cout << "> ���� ����";
		_Input->Gotoxy(x, 16);
		cout << "���� ����";
		_Input->Gotoxy(x, 17);
		cout << "  ����  ";

		Once = true;
	}

	if (_Input->IsUpCmdOn())
	{
		_Input->Set(USER_CMD_UP, false);

		if (y > 15)
		{
			_Input->Gotoxy(x - 2, y);
			cout << " ";
			_Input->Gotoxy(x - 2, --y);
			cout << ">";
			Sleep(150);
		}
	}

	if (_Input->IsDownCmdOn())
	{
		_Input->Set(USER_CMD_DOWN, false);

		if (y < 17)
		{
			_Input->Gotoxy(x - 2, y);
			cout << " ";
			_Input->Gotoxy(x - 2, ++y);
			cout << ">";
			Sleep(150);
		}
	}
}

void Stage::GameOver(Input* _Input)
{

}

void Stage::GameInformation(Input* _Input)
{
	if (Once == false)
	{
		system("cls");
		Narrationarrlen = 0;
		Once = true;

		_Input->Gotoxy(1, 4);
		cout << "\n\n";
		cout << "  --��������� 5�� ���α׷��� �а� �̴� �ܼ� ���� ������Ʈ--    " << endl;
		cout << "                    [ �� �� �� ]                          " << endl;
		cout << "                 �� �� : W, A, S, D                       " << endl;
		cout << "                 �� �� : �����̽� ��                       " << endl;
		cout << "              �� �� �� : Lee Geon Jae                     " << endl << endl;
		cout << "      �� ������ baba is you�� ��Ƽ��� ����������ϴ�         " << endl;
		cout << "        �����̽� �ٸ� ������ ���� ȭ������ ���ư��ϴ�          " << endl;
	}

}

void Stage::StageOne(Input* _Input)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Oh! Welcome to the first stage!";
	narrationarr[1] = "\'w\' is up, \'s\' is down, \'d\' is right, and \'a\' is left.";
	narrationarr[2] = "You didn't forget, did you?";
	narrationarr[3] = "How to move on to the next stage?";
	narrationarr[4] = "Think about it!";

	DrawMap(80, 15, StageOneMap, _Input);
}

void Stage::DrawMap(int x, int y, char Map[][80], Input* _Input)
{
	int h, w;
	for (h = 0; h < y; h++)
	{
		for (w = 0; w < x; w++)
		{
			_Input->Gotoxy(w, h);
			char temp = Map[h][w];
			if (temp == '0')
				cout << " ";
			else if (temp == '1')
				cout << "#";
		}
	}
}
