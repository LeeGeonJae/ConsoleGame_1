#include "Stage.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void Stage::Menu(Input* _Input)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 6;

	// 나레이션 쓰기 ( 영어만 가능 )
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
		cout << "> 게임 시작";
		_Input->Gotoxy(x, 16);
		cout << "게임 정보";
		_Input->Gotoxy(x, 17);
		cout << "  종료  ";

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
		cout << "  --게임인재원 5기 프로그래밍 학과 미니 콘솔 게임 프로젝트--    " << endl;
		cout << "                    [ 조 작 법 ]                          " << endl;
		cout << "                 이 동 : W, A, S, D                       " << endl;
		cout << "                 선 택 : 스페이스 바                       " << endl;
		cout << "              개 발 자 : Lee Geon Jae                     " << endl << endl;
		cout << "      이 게임은 baba is you를 모티브로 만들어졌습니다         " << endl;
		cout << "        스페이스 바를 누르면 메인 화면으로 돌아갑니다          " << endl;
	}

}

void Stage::StageOne(Input* _Input)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
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
