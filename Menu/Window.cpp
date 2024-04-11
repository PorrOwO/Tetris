
#include "Window.hpp"
Window::Window(){
    this->Height= 0;
    this->Width= 0;
    this->YMax=0;
    this->XMax=0;
    this->win=newwin(0,0,0,0);
};

Window::Window(int h, int wi, int y, int x){
    this->Height = h;
    this->Width = wi;
    this->YMax=y;
    this->XMax=x;

    //int xMax, yMax;
    //getmaxyx(stdscr, yMax, xMax);

    this->win=newwin(this->Height, this->Width, YMax/2 - (h/2), XMax/2 - (wi/2));
};

WINDOW* Window::getWin(){
    return this->win;
};

int Window::getY()
{ return this->YMax;

};


int Window::getX()
{
    return this->XMax;
};

