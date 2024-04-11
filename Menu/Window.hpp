#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <ncurses.h>
#include <fstream>
using namespace std;
class Window{
protected:
    int Height;
    int Width;
    int XMax;
    int YMax;
    WINDOW* win;
public:
    Window();
    Window(int h, int wi, int y, int x);
    WINDOW* getWin();
    int getY();
    int getX();

};
