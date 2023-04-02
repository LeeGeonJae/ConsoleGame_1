#pragma once

enum
{
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void gLoop(int mapCode);
void titleDraw();
int menuDraw();
void infoDraw();
int maplistDraw();
void drawMap(int* x, int* y);
void drawUI(int* x, int* y, int* key);
void move(int* x, int* y, int _x, int _y, int* key, int* playing);