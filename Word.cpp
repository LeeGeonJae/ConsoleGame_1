#include "Word.h"
#include <string>
#include <windows.h>

using namespace std;

// 맵의 모든 벽 없애기
void Word::Wall(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == '1')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// 게임 오버
void Word::All()
{
	GameNumber = 101;
	system("cls");
}

// 닫혀진 문 열리게 만들기
void Word::Open(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == '2')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// 문 닫히게 만들기
void Word::Close(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == '2')
				map[h][w] = '3';
		}
	}

	DrawWordMap = true;
}

// 미정
void Word::Set(char map[][80])
{

	DrawWordMap = true;
}

// Blue 완성 시에 파란색 벽 없애기
void Word::Blue(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == 'b')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// Red 완성 시에 빨간색 벽 없애기
void Word::Red(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == 'r')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// Yellow 완성 시에 노란색 벽 없애기
void Word::Yellow(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == 'y')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// 완성시에 이스터 에그 실행
void Word::NG()
{
	GameNumber = 102;
	system("cls");
}

// 단어를 찾고 그 줄에 단어가 해당되면 해당 단어의 함수 실행
void Word::ChecktheWord(char map[][80], int y, int x)
{
	string tempX;
	string tempY;
	size_t pos;

	for (int i = 0; i < 80; i++)
		tempX.push_back(map[y][i]);
	for (int i = 0; i < 15; i++)
		tempY.push_back(map[i][x]);

	if (tempX.find("WALL") != string::npos)
	{
		pos = tempX.find("WALL");
		for (int i = pos; i < pos + 4; i++)
			map[y][i] = '0';
		Wall(map);
	}
	else if (tempX.find("ALL") != string::npos)
	{
		pos = tempX.find("ALL");
		All();
	}
	else if (tempX.find("OPEN") != string::npos)
	{
		pos = tempX.find("OPEN");
		Open(map);
		for (int i = pos; i < pos + 4; i++)
			map[y][i] = '0';
	}
	else if (tempX.find("CLOSE") != string::npos)
	{
		pos = tempX.find("CLOSE");
		Close(map);
		for (int i = pos; i < pos + 5; i++)
			map[y][i] = '0';
	}
	else if (tempX.find("BLUE") != string::npos)
	{
		pos = tempX.find("BLUE");
		Blue(map);
		for (int i = pos; i < pos + 4; i++)
			map[y][i] = '0';
	}
	else if (tempX.find("RED") != string::npos)
	{
		pos = tempX.find("RED");
		Red(map);
		for (int i = pos; i < pos + 3; i++)
			map[y][i] = '0';
	}
	else if (tempX.find("YELLOW") != string::npos)
	{
		pos = tempX.find("YELLOW");
		Yellow(map);
		for (int i = pos; i < pos + 6; i++)
			map[y][i] = '0';
	}
	else if (tempX.find("NG") != string::npos)
	{
		pos = tempX.find("NG");
		NG();
		for (int i = pos; i < pos + 2; i++)
			map[y][i] = '0';
	}


	if (tempY.find("WALL") != string::npos)
	{
		pos = tempY.find("WALL");
		for (int i = pos; i < pos + 4; i++)
			map[i][x] = '0';
		Wall(map);
	}
	else if (tempY.find("ALL") != string::npos)
	{
		pos = tempY.find("ALL");
		All();
	}
	else if (tempY.find("OPEN") != string::npos)
	{
		pos = tempY.find("OPEN");
		Open(map);
		for (int i = pos; i < pos + 4; i++)
			map[i][x] = '0';
	}
	else if (tempY.find("CLOSE") != string::npos)
	{
		pos = tempY.find("CLOSE");
		Close(map);
		for (int i = pos; i < pos + 5; i++)
			map[i][x] = '0';
	}
	else if (tempY.find("BLUE") != string::npos)
	{
		pos = tempY.find("BLUE");
		Blue(map);
		for (int i = pos; i < pos + 4; i++)
			map[i][x] = '0';
	}
	else if (tempY.find("RED") != string::npos)
	{
		pos = tempY.find("RED");
		Red(map);
		for (int i = pos; i < pos + 3; i++)
			map[i][x] = '0';
	}
	else if (tempY.find("YELLOW") != string::npos)
	{
		pos = tempY.find("YELLOW");
		Yellow(map);
		for (int i = pos; i < pos + 6; i++)
			map[i][x] = '0';
	}
	else if (tempY.find("NG") != string::npos)
	{
		pos = tempY.find("NG");
		NG();
		for (int i = pos; i < pos + 2; i++)
			map[i][x] = '0';
	}
}

// 색 지정하기
void Word::SetColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}