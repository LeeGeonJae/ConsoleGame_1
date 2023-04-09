#include "Stage.h"
#include <Windows.h>
#include <iostream>

using namespace std;

// 메뉴 그리기
void Stage::Menu(Input* _Input)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 4;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"안녕? 나는 튜토리얼의 요정이야!";
	narrationarr[1] = L"나는 네가 게임 중에 심심하지 않게 여러가지를 알려줄 예정이야!";
	narrationarr[2] = L"\'W\'는 위, \'S\'는 아래, \'Space bar\'는 선택이야!";
	narrationarr[3] = L"이 게임을 충분히 즐겨주었으면 해!";

	// 게임 타이틀 제목
	_Input->Gotoxy(0, 3);

	SetColor(white, white);
	wcout << "                                                                               " << endl << endl; SetColor(white, black);
	wcout << "     #     #                         #     # ###                               " << endl;
	wcout << "     #  #  #: ####  #####  #####     #  #  #  #  ######   ##   #####  #####    " << endl;
	wcout << "     #  #  # #    # #    # #    #    #  #  #  #      #   #  #  #    # #    #   " << endl;
	wcout << "     #  #  # #    # #    # #    #    #  #  #  #     #   #    # #    # #    #   " << endl;
	wcout << "     #  #  # #    # #####  #    #    #  #  #  #    #    ###### #####  #    #   " << endl;
	wcout << "     #  #  # #    # #    # #    #    #  #  #  #   #     #    # #   #  #    #   " << endl;
	wcout << "      ## ##   ####  #    # #####      ## ##  ### ###### #    # #    # #####    " << endl << endl; SetColor(white, white);
	wcout << "                                                                               " << endl;
	SetColor(white, black);

	// 게임 처음 세팅
	if (Once == false)
	{
		_Input->Gotoxy(x - 2, 15);
		wcout << L"> 게임 시작";
		_Input->Gotoxy(x, 16);
		wcout << L"게임 정보";
		_Input->Gotoxy(x, 17);
		wcout << L"  종료  ";

		Once = true;
	}

	// 위로 올라가기
	if (_Input->IsUpCmdOn())
	{
		_Input->Set(USER_CMD_UP, false);

		if (y > 15)
		{
			_Input->Gotoxy(x - 2, y);
			wcout << " ";
			_Input->Gotoxy(x - 2, --y);
			wcout << ">";
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
			wcout << " ";
			_Input->Gotoxy(x - 2, ++y);
			wcout << ">";
			Sleep(150);
		}
	}
}

// 게임 오버
void Stage::GameOver(Input* _Input, int* GameNumber)
{
	system("cls");

	SetColor(yellow, black);
	wcout << L"####################################$$======***!*!!!!!!!!!!!!!!!!*****= *= ====== =@@@@@@@##########@@@@@@@@@@@@@@@@@###" << endl;
	wcout << L"###################################$$==== = ****!!!;;;;;;;;;;;;;; !!!!!*****= ======####################################" << endl;
	wcout << L"#################################$$$====****!!!!!;;;;; ::;; :;;;;; !!!!!!!****= = *= =##################################" << endl;
	wcout << L"################################$$$ == = ****!!!!;;;;; :::::::::::;;; !!!!!!!****= **=##################################" << endl;
	wcout << L"################################$$$ == ****!!!;;;;; :::~~~~~~~~~:: : ;;; !!!!!********##################################" << endl;
	wcout << L"##############################$$$====****!!!;;; :::~~~~~--~~~~~::::;; !!!!!!******######################################" << endl;
	wcout << L"##############################$$$====**!!!!!;; ::~~~-------- - ~- ~~:::;;; !!!!***!**###################################" << endl;
	wcout << L"##############################$$$ == = ***!!!;;; ::~~~-- - , -, -- - , -- - ~~::;;;; !!!!*!!**##########################" << endl;
	wcout << L"##############################$$====**!!!;;; ::~~----, , , , , ., , , -- - ~~:::;;;; !!!!!!!############################" << endl;
	wcout << L"##############################$$ == = ***!!!;; ::~---- - , , , ., ., , , , , , --~~:::;;; !!!!!!!#######################" << endl;
	wcout << L"##############################$$ == ****!;;; :::~-- - , , , , , , ., , , , , , , -- - ~~:: : ;;; !!!!!*#################" << endl;
	wcout << L"##############################$ == = ***!!;;; ::~~--, , , , , .   ..., , , , , -~~~::;; !!!!***#########################" << endl;
	wcout << L"##############################$ == = ***!!;; ::~-- - , , , , , .       ., ., , --~~::;;; !!!***#########################" << endl;
	wcout << L"##############################====***!!; ::~~-- - , .           ...., , --~~::;; !!!***#################################" << endl;
	wcout << L"#############################====***!!; ::~---- .모든 것이 폭발했습니다., , --~~::;; !!!***#############################" << endl;
	wcout << L"##############################====**!!;; ::~-- - , . .    ., , -~~::;; !!!***###########################################" << endl;
	wcout << L"##############################====***!;; :~~- , .         .., .    . ., -~~::;; !!***=##################################" << endl;
	wcout << L"##############################====***!;; ::~- .  . .  . .....    .  --~~::;; !!**= =####################################" << endl;
	wcout << L"##############################$====**!;; ::~- ........., -~~:;;; !***= =      ##########################################" << endl;
	wcout << L"##############################$====**!;; ::~, ..  ..., ., ....., .  ., -~::;; !!**= ==##################################" << endl;
	wcout << L"##############################$====**!!;; :~- , .., , , ., ., .. .. - . - ~::;; !!**= ==################################" << endl;
	wcout << L"##############################$$ == = ***!;;; :, , ., , , -, .., .. .., ...  . - ~: ;; !!!**= ==########################" << endl;
	wcout << L"##############################$$====**!!;; :-, , , -- - , , ., ...   ....   ~::;; !!**= == =############################" << endl;
	wcout << L"##############################$$$====*!!!;;; --, --, , , , ...   ...., ~::; !!!*= ====##################################" << endl;
	wcout << L"##############################$$$====**!!!;; :, ~- , . - . .      . . ., ~::;; !!*= == = $$#############################" << endl;
	wcout << L"##############################$$$$====**!!; !:-- - , ., . . .      ., -~: ;; !!!*= == $$$###############################" << endl;
	wcout << L"################################$$$ == = ***!!!; ~-- - , ..   .    .., , , , :;; !!*= == = $$$##########################" << endl;
	wcout << L"################################$$$$ == = ****!!; :: - , .    .    ., , .~~~;; !!**= == = $$$###########################" << endl;
	wcout << L"#################################$$$====*****!::, , ...  .    .., .:;; !!!**= = $$$$$###################################" << endl;
	wcout << L"##################################$$$====****!:-, -., , ., ~;; !!**= == $$$$$###########################################" << endl;
	wcout << L"###################################$$$ == = ****~~, -.--., ~- ., , ;; !**= == $$$$#$####################################" << endl;
	wcout << L"###################################$$$====*!-------- . ., -. .. - ; !!*= == = $$$$######################################" << endl;
	wcout << L"#################################$$$$ = $ == **~, . :., -, , -.   . .., , ; !**= = $$$$$$###############################" << endl;
	wcout << L"################################# = -~~~--; !. .--.. . ..           ..!~*= == = -$, ####################################" << endl;
	wcout << L"#################################~; ~, :, , , --. ..     .~., ., .   . : , -~*: -. - .~#################################" << endl;
	wcout << L"################################$!; *~!~- , , . .  ., . - ~; -~~~~- , ., , -, ., ~; #$##################################\n\n\n" << endl;
	SetColor(white, black);

	SetColor(white, white);
	wcout << L"########################################################################################################################" << endl; SetColor(white, black);
	wcout << L"                                   당신은 죽으셨습니다 5초 후에 메뉴로 돌아갑니다                " << endl; SetColor(white, white);
	wcout << L"########################################################################################################################" << endl;
	SetColor(white, black);

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

		_Input->Gotoxy(1, 10);
		SetColor(lightgreen, black);
		wcout << "\n\n";
		wcout << L"                                --게임인재원 5기 프로그래밍 학과 미니 콘솔 게임 프로젝트--    " << endl;
		wcout << L"                                                   [ 조 작 법 ]                          " << endl;
		wcout << L"                                                이 동 : W, A, S, D                       " << endl;
		wcout << L"                                             선택 및 리셋 : 스페이스 바                       " << endl;
		wcout << L"                                              개 발 자 : Lee Geon Jae                     " << endl << endl;
		wcout << L"                                     이 게임은 baba is you를 모티브로 만들어졌습니다         " << endl;
		wcout << L"                                      스페이스 바를 누르면 메인 화면으로 돌아갑니다          " << endl;
		SetColor(white, black);
	}
}

// 스테이지1
void Stage::StageOne(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"첫번째 스테이지에 온 것을 환영해!";
	narrationarr[1] = L"\'w\':위, \'s\':아래, \'d\':오른쪽, \'a\':왼쪽이야!";
	narrationarr[2] = L"그리고 스페이스 바를 누르면 게임 리셋이야!";
	narrationarr[3] = L"다음 스테이지를 어떻게 가냐고?";
	narrationarr[4] = L"한번 생각해봐!";

	SettingMap(_Input, _Tick, GameNumber, StageOneMap);
}

// 스테이지2
void Stage::StageTwo(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"훌륭해! 너는 첫번째 스테이지를 통과했어!";
	narrationarr[1] = L"근데 맵에 있는 저 알파벳들은 무엇일까?";
	narrationarr[2] = L"저 알파벳들로 무슨 일들을 할 수 있을까?";
	narrationarr[3] = L"궁금하지 않아?";
	narrationarr[4] = L"단어를 한 번 완성해봐!";

	SettingMap(_Input, _Tick, GameNumber, StageTwoMap);
}

// 스테이지3
void Stage::StageThree(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 6;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"오! 저 많은 알파벳들은 무엇일까?";
	narrationarr[1] = L"스테이지를 통과하기 위해 너는 몇 가지 단어들을 생각해야해!";
	narrationarr[2] = L"맵에 존재하는 \'*\'모양은 \'문\'이라고 생각하면 좋아!";
	narrationarr[3] = L"네가 저 문을 통과하려면 어떻게 해야할까?";
	narrationarr[4] = L"문을 열어야 하지 않을까?";
	narrationarr[5] = L"닫다의 반대되는 말은 무엇일까?";

	SettingMap(_Input, _Tick, GameNumber, StageThreeMap);
}

void Stage::StageFour(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"오! 저 맵 아래에 존재하는 것은 뭐지?";
	narrationarr[1] = L"저건 다음 스테이지로 통하는 통로를 향해 달리고 있어!";
	narrationarr[2] = L"무슨 일이 벌어질지는 몰라도 막아야 될 것 같아!";
	narrationarr[3] = L"일반 \'*\'모양은 저것을 막을 수 없어!";
	narrationarr[4] = L"저 별모양을 바꿔서 저것을 막아야 해!";

	if (Once == false)
	{
		_Eremy->Init(5, 12, _Input);
	}

	_Eremy->Move(tempMap, _Tick, _Input, 10);

	SettingMap(_Input, _Tick, GameNumber, StageFourMap);
}

void Stage::StageFive(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 5;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"와! 맵이 엄청 알록달록해졌어!";
	narrationarr[1] = L"나는 노랑과 파랑도 좋아햐지만, 빨간색도 좋아해!";
	narrationarr[2] = L"네가 좋아하는 색은 무엇이니?";
	narrationarr[3] = L"파랑, 노랑, 빨간색의 눈은 정말 아름다워!";
	narrationarr[4] = L"나는 물론 알록달록한 꽃들을 정말 좋아해!";

	SettingMap(_Input, _Tick, GameNumber, StageFiveMap);
}

void Stage::StageSix(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 6;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"이번 시간에는, 네가 배워본 것들을 한 번 활용해볼 시간이야!";
	narrationarr[1] = L"네가 게임을 진행할 동안에 나는 잡담을 한번 해볼까 해!";
	narrationarr[2] = L"어쩌면 내 이야기 중에서 힌트를 찾을 수 있을지도 모르지?";
	narrationarr[3] = L"이 게임은 상당한 컨트롤을 요구한다고 나는 알고 있어";
	narrationarr[4] = L"어쩌면 게임 제작자가 유도한 것일 수도?";
	narrationarr[5] = L"네가 충분하게 게임을 즐겼으면 좋겠지만!";

	if (Once == false)
	{
		_Eremy->Init(5, 12, _Input);
	}

	_Eremy->Move(tempMap, _Tick, _Input, 30);

	SettingMap(_Input, _Tick, GameNumber, StageSixMap);
}

void Stage::StageSeven(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 7;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"네가 좋아하는 책이나 영화가 있어?";
	narrationarr[1] = L"사람들이 말하길 책은 마음의 양식이라고들 하지!";
	narrationarr[2] = L"그리고 게임은 단순한 오락거리에 불과하다고 해";
	narrationarr[3] = L"오락거리는 즐거움을 추구하는 거잖아?";
	narrationarr[4] = L"즐거움을 추구하는 것은 나쁜게 아니야";
	narrationarr[5] = L"우리는 바쁘고 해야할 것들이 많지만 휴식이 필요할 때,";
	narrationarr[6] = L"게임은 충분한 휴식거리가 될 거야!";

	SettingMap(_Input, _Tick, GameNumber, StageSevenMap);
}

void Stage::StageEight(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 6;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"오늘 아침은 먹었어?";
	narrationarr[1] = L"분명 귀찮을 수도 있지만 아침을 먹는 것이 건강에 좋아!";
	narrationarr[2] = L"가끔 바쁘게 일하다보면 밥먹을 때를 잊을 수도 있겠지";
	narrationarr[3] = L"그나자나 게임은 충분하게 즐기고 있어?";
	narrationarr[4] = L"나는 네가 충분히 즐겼으면 좋겠지만";
	narrationarr[5] = L"네가 그렇게 느끼지 못한다면 그건 아마 게임 잘못이겠지";

	SettingMap(_Input, _Tick, GameNumber, StageEightMap);
}

void Stage::GoodEnging(Input* _Input, Tick* _Tick, int* GameNumber, int PlayTime)
{
	// 나레이션 배열 갯수
	Narrationarrlen = 2;

	// 나레이션 쓰기 ( 영어만 가능 )
	narrationarr[0] = L"축하해! 너는 게임을 클리어 했어!";
	narrationarr[1] = L"스페이스 바를 누르면 게임이 종료될거야!";

	if(Once == false)
	{
		_Input->Gotoxy(1, 1);
		Once = true;
		wcout << L"\n\n\n"; SetColor(lightgreen, black);
		wcout << L"                                                       PlayTime : " << PlayTime << "\n\n\n"; SetColor(white, black);
		wcout << L"                             ##    ##  #######  ##     ##    ##      ## #### ##    ## #### #### " << endl;
		wcout << L"                              ##  ##  ##     ## ##     ##    ##  ##  ##  ##  ###   ## #### ####" << endl;
		wcout << L"                               ####   ##     ## ##     ##    ##  ##  ##  ##  ####  ## #### ####" << endl;
		wcout << L"                                ##    ##     ## ##     ##    ##  ##  ##  ##  ## ## ##  ##   ##" << endl;
		wcout << L"                                ##    ##     ## ##     ##    ##  ##  ##  ##  ##  ####" << endl;
		wcout << L"                                ##    ##     ## ##     ##    ##  ##  ##  ##  ##   ### #### ####" << endl;
		wcout << L"                                ##     #######   #######      ###  ###  #### ##    ## #### ####" << endl;
	}

	if (_Input->IsSpaceCmdOn())
		*GameNumber = -1;
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
				wcout << " ";
			else if (temp == '1')				// Wall
			{
				SetColor(white, white);
				wcout << "#";
				SetColor(white, black);
			}
			else if (temp == '2')				// Closed Door
				wcout << "*";
			else if (temp == '3')				// Closed Door (2) 
				wcout << "ㅁ";
			else if (temp == 'r')				// RED
			{
				SetColor(red, black);
				wcout << "r";
				SetColor(white, black);
			}
			else if (temp == 'b')				// BLUE
			{
				SetColor(lightblue, black);
				wcout << "b";
				SetColor(white, black);
			}
			else if (temp == 'y')				// YELLOW
			{
				SetColor(yellow, black);
				wcout << "y";
				SetColor(white, black);
			}
			else if (temp == 'G')
				wcout << "G";
			else if (temp == 'W')
				wcout << "W";
			else if (temp == 'A')
				wcout << "A";
			else if (temp == 'L')
				wcout << "L";
			else if (temp == 'O')
				wcout << "O";
			else if (temp == 'P')
				wcout << "P";
			else if (temp == 'E')
				wcout << "E";
			else if (temp == 'N')
				wcout << "N";
			else if (temp == 'C')
				wcout << "C";
			else if (temp == 'S')
				wcout << "S";
			else if (temp == 'B')
				wcout << "B";
			else if (temp == 'U')
				wcout << "U";
			else if (temp == 'R')
				wcout << "R";
			else if (temp == 'D')
				wcout << "D";
			else if (temp == 'Y')
				wcout << "Y";
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

		//if (*GameNumber == 10)
		//	*GameNumber = 0;
	}

	// Space bar를 누르면 맵 다시 시작
	if (_Input->IsSpaceCmdOn())
	{
		_Input->Set(ESCAPE_KEY_INDEX, false);
		Once = false;
	}
}