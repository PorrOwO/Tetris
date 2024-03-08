
#include "Window.hpp"
Window::Window(){
    this->Height= 0;
    this->Width= 0;
    this->win=newwin(0,0,0,0);
};

Window::Window(int h, int wi){
    this->Height = h;
    this->Width = wi;

    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    this->win=newwin(this->Height, this->Width, yMax/2 - (h/2), xMax/2 - (wi/2));
};

WINDOW* Window::getWin(){
    return this->win;
};
