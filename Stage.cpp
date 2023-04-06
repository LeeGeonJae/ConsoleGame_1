#include "Stage.h"
#include <Windows.h>
#include <iostream>

using namespace std;

// 메뉴 그리기
void Stage::Menu(Input* _Input)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = "Hello? I'm the fairy of the tutorial";
	narrationarr[1] = "Welcome to my console game";
	narrationarr[2] = "\'W\' is up, \'S\' is down, \'D\' is right, \'A\' is left";
	narrationarr[3] = "and \'space bar\' is choice";
	narrationarr[4] = "I hope you play a good game";

	// 게임 타이틀 제목
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

	// 게임 처음 세팅
	if (Once == false)
	{
		_Input->Gotoxy(x - 2, 15);
		cout << "> 게임 시작";
		_Input->Gotoxy(x, 16);
		cout << "게임 정보";
		_Input->Gotoxy(x, 17);
		cout << "  종료  ";

		Once = true;
	}

	// 위로 올라가기
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

	// 아래로 내려가기
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

// 게임 오버
void Stage::GameOver(Input* _Input, int* GameNumber)
{
	system("cls");
	_Input->Gotoxy(0, 10);
	SetColor(white, white);
	cout << "#############################################################################" << endl; SetColor(white, black);
	cout << "               당신은 죽으셨습니다 5초 후에 메뉴로 돌아갑니다                " << endl; SetColor(white, white);
	cout << "#############################################################################" << endl;

	Sleep(5000);
	system("cls");
	Once = false;
	*GameNumber = 0;
}

// 게임 정보
void Stage::GameInformation(Input* _Input)
{
	if (Once == false)
	{
		system("cls");
		Narrationarrlen = 0;
		Once = true;

		_Input->Gotoxy(1, 4);
		cout << "\n\n";
		cout << "            --게임인재원 5기 프로그래밍 학과 미니 콘솔 게임 프로젝트--    " << endl;
		cout << "                               [ 조 작 법 ]                          " << endl;
		cout << "                            이 동 : W, A, S, D                       " << endl;
		cout << "                         선택 및 리셋 : 스페이스 바                       " << endl;
		cout << "                          개 발 자 : Lee Geon Jae                     " << endl << endl;
		cout << "                 이 게임은 baba is you를 모티브로 만들어졌습니다         " << endl;
		cout << "                  스페이스 바를 누르면 메인 화면으로 돌아갑니다          " << endl;
	}
}

// 스테이지1
void Stage::StageOne(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = "Oh! Welcome to the first stage!";
	narrationarr[1] = "\'w\' is up, \'s\' is down, \'d\' is right, and \'a\' is left.";
	narrationarr[2] = "Press the \'Space Bar\' : Map Reset!";
	narrationarr[3] = "How to move on to the next stage?";
	narrationarr[4] = "Think about it!";

	SettingMap(_Input, _Tick, GameNumber, StageOneMap);
}

// 스테이지2
void Stage::StageTwo(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = "excellent! You passed the first stage";
	narrationarr[1] = "What are those alphabets on the map?";
	narrationarr[2] = "Don't you think something will happen";
	narrationarr[3] = "if you complete the word?";
	narrationarr[4] = "Let's complete the word!";

	SettingMap(_Input, _Tick, GameNumber, StageTwoMap);
}

// 스테이지3
void Stage::StageThree(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 6;

	// 나레이션 쓰기 ( 영어만 가능 )
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
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
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
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = "Oh! I think that's the enemy!";
	narrationarr[1] = "That's running towards GOAL!";
	narrationarr[2] = "You need to stop them from reaching GOAL!";
	narrationarr[3] = "'*' Shapes won't stop that!";
	narrationarr[4] = "you should find the opposite meaning of \'OPEN\'!";

	SettingMap(_Input, _Tick, GameNumber, StageFiveMap);
}

// 색 지정하기
void Stage::SetColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

// 맵 그리기
void Stage::DrawMap(int x, int y, char Map[][80], Input* _Input)
{
	int h, w;
	for (h = 0; h < y; h++)
	{
		for (w = 0; w < x; w++)
		{
			// 만약 해당 좌표에 플레이어가 있으면 다시 그리지 않기
			if (_player->PlayerCurrentPosition.X == w && _player->PlayerCurrentPosition.Y == h)
				continue;
			if (_Eremy->EremyCurrentPosition.X == w && _Eremy->EremyCurrentPosition.Y == h && _Eremy->Delete != true)
				continue;

			// 해당 좌표에 가서 맵 그리기
			_Input->Gotoxy(w, h);
			char temp = Map[h][w];
			if (temp == '0')					// 빈 공간
				cout << " ";
			else if (temp == '1')				// Wall
				cout << "#";
			else if (temp == '2')				// Closed Door
				cout << "*";
			else if (temp == '3')				// Closed Door (2) 
				cout << "ㅁ";
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

// 스테이지 맵 복사하기
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

// 맵 세팅하기
void Stage::SettingMap(Input* _Input, Tick* _Tick, int* GameNumber, char map[][80])
{
	// 처음 맵 세팅
	if (Once == false)
	{
		TempMap(map);
		_player->Init(40, 5, _Input);
		DrawMap(MapY, MapX, tempMap, _Input);

		Once = true;
	}

	// 단어 완성되면 맵 다시 그리기
	if (_word->DrawWordMap == true)
	{
		DrawMap(MapY, MapX, tempMap, _Input);
	}

	// 플레이어 움직이기
	_player->Move(tempMap, _Input, _Tick, _word);

	// 플레이어가 클리어 하면 이동하기
	if (_player->Clear == true)
	{
		_player->Clear = false;
		Once = false;
		system("cls");
		(*GameNumber)++;

		if (*GameNumber == 7)
			*GameNumber = 0;
	}

	// Space bar를 누르면 맵 다시 시작
	if (_Input->IsSpaceCmdOn())
	{
		_Input->Set(ESCAPE_KEY_INDEX, false);
		Once = false;
	}
}