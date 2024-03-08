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
    WINDOW* win;
public:
    Window();
    Window(int h, int wi);
    WINDOW* getWin();

};
