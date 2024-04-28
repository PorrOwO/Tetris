#pragma once

#include "../includeManager.hpp"
using namespace std;

class Window {
protected:
    int height;
    int width;
    int xPos;
    int yPos;
    WINDOW *win;

public:
    Window();
    Window(int height, int width, int yPos, int xPos);
    WINDOW *getWin();
    int getY();
    int getX();
    int getWidth();
    int getHeight();
};