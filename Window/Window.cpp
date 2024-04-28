#include "Window.hpp"

// costruttore vuoto
Window::Window(){
    this->height = this->width = this->xPos = this->yPos = 0;
    this->win=newwin(0,0,0,0);
};

// costruttore finestra di dim height e width e coordinate yPos e xPos
Window::Window(int height, int width, int yPos, int xPos){
    this->height = height;
    this->width = width;

    this->yPos = yPos;
    this->xPos = xPos;

    this->win=newwin(this->height, this->width, this->yPos, this->xPos);
};

// -- getters --

WINDOW* Window::getWin(){
    return this->win;
};

int Window::getY(){
    return this->yPos;
};


int Window::getX(){
    return this->xPos;
};

int Window::getWidth(){
    return this->width;
}

int Window::getHeight(){
    return this->height;
}