#include "Render.h"
#include <iostream>
#include <windows.h>
#include "Engine.h"

char map1[14][56] = {
    {"1111111111111111111111111111111111111111111111111111111"},
    {"1000l00000000000000000000000000000000000000000000000001"},
    {"10k0l00000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"10p0100000000000000000000000000000000000000000000000g01"},
    {"1000100000000000000000000000000000000000000000000000001"},
    {"1111111111111111111111111111111111111111111111111111111"},
};

char map2[14][56] = {
    {"1111111111111111111111111111111111111111111111111111111"},
    {"1000000001000000000001000000000000100000000000000000001"},
    {"1000000001000000000001000000000000100000000000000000001"},
    {"1000100001000001000001000001000000100000000100000000001"},
    {"1000100001000001000001000001000000100000000100000000001"},
    {"1000100001000001000001000001000000100000000100000000001"},
    {"1000100001000001000001000001000000100000000100000000001"},
    {"100010000l000001000001000001000000100000000100000000001"},
    {"100010000l000001000001000001000000100000000100000000001"},
    {"1000100001000001000001000001000000100000000100000000001"},
    {"1000100001000001000001000001000000100000000100000000001"},
    {"10p0100001000001000000000001000000000000000100000000g01"},
    {"100010k001000001000000000001000000000000000100000000001"},
    {"1111111111111111111111111111111111111111111111111111111"},
};

char tempMap[14][56];

void titleDraw()
{
    printf("\n\n\n\n");
    printf("        #####    ###     ###      #      ####    ##### \n");
    printf("        #       #       #        # #     #   #   #     \n");
    printf("        ####    ####    #       #####    ####    ####  \n");
    printf("        #           #   #       #   #    #       #     \n");
    printf("        #####   ####     ###    #   #    #       ##### \n");
}

int menuDraw()
{
    int x = 24;
    int y = 12;
    gotoxy(x - 2, y);
    printf("> 게 임 시 작");
    gotoxy(x, y + 1);
    printf("게 임 정 보");
    gotoxy(x, y + 2);
    printf("   종 료   ");

    while (1)
    {
        int n = KeyControl();
        switch (n)
        {
        case UP:
        {
            if (y > 12)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN:
        {
            if (y < 14)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT:
        {
            return y - 12;
        }
        }
    }
}

void infoDraw()
{
    system("cls");
    printf("\n\n");
    printf("                          [ 조 작 법 ] \n\n");
    printf("                      이 동 : W, A, S, D\n");
    printf("                      선 택 : 스 페 이 스 바\n\n\n\n\n\n\n");
    printf("                   출 처 : codevkr.tistory.com\n\n");
    printf("           스페이스바를 누르면 메인화면으로 이동합니다.\n\n");

    while (1)
    {
        if (KeyControl() == SUBMIT)
            break;
    }
}

int maplistDraw()
{
    int x = 24;
    int y = 6;
    system("cls");
    printf("\n\n");
    printf("                     [ 맵 선택 ]\n\n");

    gotoxy(x - 2, y);
    printf("> 쉬 움");
    gotoxy(x, y + 1);
    printf("어 려 움");
    gotoxy(x, y + 2);
    printf("뒤 로");

    while (1)
    {
        int n = KeyControl();
        switch (n)
        {
        case UP:
        {
            if (y > 6)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN:
        {
            if (y < 9)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT:
            return y - 6;
        }
    }
}

void drawMap(int* x, int* y)
{
    system("cls");
    int h, w;

    for (h = 0; h < 14; h++)
    {
        for (w = 0; w < 56; w++)
        {
            char temp = tempMap[h][w];
            if (temp == '0')
            {
                setColor(black, black);
                printf(" ");
            }
            else if (temp == '1')
            {
                setColor(white, white);
                printf("#");
            }
            else if (temp == 'p')
            {
                *x = w;
                *y = h;
                setColor(cyan, black);
                printf("@");
            }
            else if (temp == 'g')
            {
                setColor(lightgreen, black);
                printf("G");
            }
            else if (temp == 'k')
            {
                setColor(yellow, black);
                printf("*");
            }
            else if (temp == 'l')
            {
                setColor(brown, black);
                printf("+");
            }
        }
        printf("\n");
    }
    setColor(white, black);
    Sleep(100);
}

void drawUI(int* x, int* y, int* key)
{
    setColor(white, black);
    gotoxy(3, 16);
    printf("위치 : %02d, %02d", *x, *y);
    
    setColor(yellow, black);
    gotoxy(34, 16);
    printf("열쇠 : %d개", *key);
}

void gLoop(int mapCode)
{
    int x, y;
    int key = 0;
    int playing = 1;

    if (mapCode == 0)
        memcpy(tempMap, map1, sizeof(tempMap));
    else if (mapCode == 1)
        memcpy(tempMap, map2, sizeof(tempMap));

    drawMap(&x, &y);

    while (playing)
    {
        drawUI(&x, &y, &key);

        switch (KeyControl())
        {
        case UP:
            move(&x, &y, 0, -1, &key, &playing);
            break;
        case DOWN:
            move(&x, &y, 0, 1, &key, &playing);
            break;
        case RIGHT:
            move(&x, &y, 1, 0, &key, &playing);
            break;
        case LEFT:
            move(&x, &y, -1, 0, &key, &playing);
            break;
        case SUBMIT:
            playing = 0;
        }
    }

    gotoxy(22, 8);
    printf("Game Clear!");
    Sleep(1500);
}

void move(int* x, int* y, int _x, int _y, int* key, int* playing)
{
    char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black);

    if (mapObject == '0')
    {
        gotoxy(*x, *y);
        printf(" ");

        setColor(cyan, black);
        gotoxy(*x + _x, *y + _y);
        printf("@");

        *x += _x;
        *y += _y;
    }
    else if (mapObject == 'k')
    {
        *key += 1;
        tempMap[*y + _y][*x + _x] = '0';
        gotoxy(*x + _x, *y + _y);
        printf(" ");
    }
    else if (mapObject == 'l')
    {
        if (*key > 0)
        {
            *key -= 1;
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            printf(" ");
        }
    }
    else if (mapObject == 'g')
    {
        *playing = 0;
    }
}

