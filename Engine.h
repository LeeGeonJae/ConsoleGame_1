#pragma once

enum Input
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SUBMIT,
};

void gotoxy(int x, int y);
int KeyControl();
void init();
void setColor(int forground, int background);