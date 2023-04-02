#pragma once

#include <iostream>
#include <Windows.h>
#include "Render.h"
#include "Engine.h"

using namespace std;

int main()
{
    init();

    while (1)
    {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0)
        {
            int n = maplistDraw();

            if (n == 0)
            {
                gLoop(0);
            }
            else if (n == 1)
            {
                gLoop(1);
            }
        }
        else if (menuCode == 1)
            infoDraw();
        else if (menuCode == 2)
            return 0;
        system("cls");
    }

    return 0;
}
