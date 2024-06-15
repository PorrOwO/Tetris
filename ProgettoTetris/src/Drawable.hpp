
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
    ~Drawable();
    
    void draw();
    int getX();
    int getY();
    WINDOW* getWin();
    
    void setX(int x);
    void setY(int y);
    void setWin(WINDOW* win);
};
