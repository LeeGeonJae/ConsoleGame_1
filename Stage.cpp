#include "Stage.h"
#include <Windows.h>
#include <iostream>

using namespace std;

// �޴� �׸���
void Stage::Menu(Input* _Input)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Hello? I'm the fairy of the tutorial";
	narrationarr[1] = "Welcome to my console game";
	narrationarr[2] = "\'W\' is up, \'S\' is down, \'D\' is right, \'A\' is left";
	narrationarr[3] = "and \'space bar\' is choice";
	narrationarr[4] = "I hope you play a good game";

	// ���� Ÿ��Ʋ ����
	_Input->Gotoxy(0, 3);

	SetColor(white, white);
	cout << "                                                                               " << endl << endl; SetColor(white, black);
	cout << "     #     #                         #     # ###                               " << endl;
	cout << "     #  #  #: ####  #####  #####     #  #  #  #  ######   ##   #####  #####    " << endl;
	cout << "     #  #  # #    # #    # #    #    #  #  #  #      #   #  #  #    # #    #   " << endl;
	cout << "     #  #  # #    # #    # #    #    #  #  #  #     #   #    # #    # #    #   " << endl;
	cout << "     #  #  # #    # #####  #    #    #  #  #  #    #    ###### #####  #    #   " << endl;
	cout << "     #  #  # #    # #    # #    #    #  #  #  #   #     #    # #   #  #    #   " << endl;
	cout << "      ## ##   ####  #    # #####      ## ##  ### ###### #    # #    # #####    " << endl << endl; SetColor(white, white);
	cout << "                                                                               " << endl;
	SetColor(white, black);

	// ���� ó�� ����
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

	// ���� �ö󰡱�
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

	// �Ʒ��� ��������
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

// ���� ����
void Stage::GameOver(Input* _Input, int* GameNumber)
{
	system("cls");
	_Input->Gotoxy(0, 10);
	SetColor(white, white);
	cout << "#############################################################################" << endl; SetColor(white, black);
	cout << "               ����� �����̽��ϴ� 5�� �Ŀ� �޴��� ���ư��ϴ�                " << endl; SetColor(white, white);
	cout << "#############################################################################" << endl;

	Sleep(5000);
	system("cls");
	Once = false;
	*GameNumber = 0;
}

// ���� ����
void Stage::GameInformation(Input* _Input)
{
	if (Once == false)
	{
		system("cls");
		Narrationarrlen = 0;
		Once = true;

		_Input->Gotoxy(1, 4);
		cout << "\n\n";
		cout << "            --��������� 5�� ���α׷��� �а� �̴� �ܼ� ���� ������Ʈ--    " << endl;
		cout << "                               [ �� �� �� ]                          " << endl;
		cout << "                            �� �� : W, A, S, D                       " << endl;
		cout << "                         ���� �� ���� : �����̽� ��                       " << endl;
		cout << "                          �� �� �� : Lee Geon Jae                     " << endl << endl;
		cout << "                 �� ������ baba is you�� ��Ƽ��� ����������ϴ�         " << endl;
		cout << "                  �����̽� �ٸ� ������ ���� ȭ������ ���ư��ϴ�          " << endl;
	}
}

// ��������1
void Stage::StageOne(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Oh! Welcome to the first stage!";
	narrationarr[1] = "\'w\' is up, \'s\' is down, \'d\' is right, and \'a\' is left.";
	narrationarr[2] = "Press the \'Space Bar\' : Map Reset!";
	narrationarr[3] = "How to move on to the next stage?";
	narrationarr[4] = "Think about it!";

	SettingMap(_Input, _Tick, GameNumber, StageOneMap);
}

// ��������2
void Stage::StageTwo(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "excellent! You passed the first stage";
	narrationarr[1] = "What are those alphabets on the map?";
	narrationarr[2] = "Don't you think something will happen";
	narrationarr[3] = "if you complete the word?";
	narrationarr[4] = "Let's complete the word!";

	SettingMap(_Input, _Tick, GameNumber, StageTwoMap);
}

// ��������3
void Stage::StageThree(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 6;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Oh! Alphabet was provided in many ways!";
	narrationarr[1] = "Complete the words you need and move on to the next stage!";
	narrationarr[2] = "Here, \" * \" is a closed door";
	narrationarr[3] = "What's the opposite of closing?";
	narrationarr[4] = "Shouldn't you open the closed door?";
	narrationarr[5] = "o... o... op... en?";

	SettingMap(_Input, _Tick, GameNumber, StageThreeMap);
}

void Stage::StageFour(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Oh! I think that's the enemy!";
	narrationarr[1] = "That's running towards GOAL!";
	narrationarr[2] = "You need to stop them from reaching GOAL!";
	narrationarr[3] = "'*' Shapes won't stop that!";
	narrationarr[4] = "you should find the opposite meaning of \'OPEN\'!";

	if (Once == false)
	{
		_Eremy->Init(5, 12, _Input);
	}

	_Eremy->Move(tempMap, _Tick, _Input);

	SettingMap(_Input, _Tick, GameNumber, StageFourMap);
}

void Stage::StageFive(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = "Oh! I think that's the enemy!";
	narrationarr[1] = "That's running towards GOAL!";
	narrationarr[2] = "You need to stop them from reaching GOAL!";
	narrationarr[3] = "'*' Shapes won't stop that!";
	narrationarr[4] = "you should find the opposite meaning of \'OPEN\'!";

	SettingMap(_Input, _Tick, GameNumber, StageFiveMap);
}

// �� �����ϱ�
void Stage::SetColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

// �� �׸���
void Stage::DrawMap(int x, int y, char Map[][80], Input* _Input)
{
	int h, w;
	for (h = 0; h < y; h++)
	{
		for (w = 0; w < x; w++)
		{
			// ���� �ش� ��ǥ�� �÷��̾ ������ �ٽ� �׸��� �ʱ�
			if (_player->PlayerCurrentPosition.X == w && _player->PlayerCurrentPosition.Y == h)
				continue;
			if (_Eremy->EremyCurrentPosition.X == w && _Eremy->EremyCurrentPosition.Y == h && _Eremy->Delete != true)
				continue;

			// �ش� ��ǥ�� ���� �� �׸���
			_Input->Gotoxy(w, h);
			char temp = Map[h][w];
			if (temp == '0')					// �� ����
				cout << " ";
			else if (temp == '1')				// Wall
				cout << "#";
			else if (temp == '2')				// Closed Door
				cout << "*";
			else if (temp == '3')				// Closed Door (2) 
				cout << "��";
			else if (temp == 'r')				// RED
			{
				SetColor(red, red);
				cout << " ";
				SetColor(white, black);
			}
			else if (temp == 'b')				// BLUE
			{
				SetColor(blue, blue);
				cout << " ";
				SetColor(white, black);
			}
			else if (temp == 'y')				// YELLOW
			{
				SetColor(yellow, yellow);
				cout << " ";
				SetColor(white, black);
			}
			else if (temp == 'G')
				cout << "G";
			else if (temp == 'W')
				cout << "W";
			else if (temp == 'A')
				cout << "A";
			else if (temp == 'L')
				cout << "L";
			else if (temp == 'O')
				cout << "O";
			else if (temp == 'P')
				cout << "P";
			else if (temp == 'E')
				cout << "E";
			else if (temp == 'N')
				cout << "N";
			else if (temp == 'C')
				cout << "C";
			else if (temp == 'S')
				cout << "S";
			else if (temp == 'B')
				cout << "B";
			else if (temp == 'U')
				cout << "U";
			else if (temp == 'R')
				cout << "R";
			else if (temp == 'D')
				cout << "D";
			else if (temp == 'Y')
				cout << "Y";
		}
	}
}

// �������� �� �����ϱ�
void Stage::TempMap(char map[][80])
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			tempMap[y][x] = map[y][x];
		}
	}
}

// �� �����ϱ�
void Stage::SettingMap(Input* _Input, Tick* _Tick, int* GameNumber, char map[][80])
{
	// ó�� �� ����
	if (Once == false)
	{
		TempMap(map);
		_player->Init(40, 5, _Input);
		DrawMap(MapY, MapX, tempMap, _Input);

		Once = true;
	}

	// �ܾ� �ϼ��Ǹ� �� �ٽ� �׸���
	if (_word->DrawWordMap == true)
	{
		DrawMap(MapY, MapX, tempMap, _Input);
	}

	// �÷��̾� �����̱�
	_player->Move(tempMap, _Input, _Tick, _word);

	// �÷��̾ Ŭ���� �ϸ� �̵��ϱ�
	if (_player->Clear == true)
	{
		_player->Clear = false;
		Once = false;
		system("cls");
		(*GameNumber)++;

		if (*GameNumber == 7)
			*GameNumber = 0;
	}

	// Space bar�� ������ �� �ٽ� ����
	if (_Input->IsSpaceCmdOn())
	{
		_Input->Set(ESCAPE_KEY_INDEX, false);
		Once = false;
	}
}