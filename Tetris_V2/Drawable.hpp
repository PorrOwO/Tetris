
#pragma once
#include <ncurses.h>

class Drawable
{
protected:
    int x;
    int y;
    WINDOW* win;
public:
    Drawable(WINDOW* win);
    Drawable();
    void draw();
    ~Drawable();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    WINDOW* getWin();
    void setWin(WINDOW* win);
};
