#include "Window.hpp"

Window::Window(){
    this->width = 0;
    this->height = 0;
    // this->win = newwin(width, height, 0, 0);
};
Window::Window(int height, int width){
    this->height = height;
    this->width = width;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    this->win = newwin(this->height, this->width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
};

// metodo per inizializzare una finestra
void Window::init(){
    clear();
    refresh();
};

// metodo per creare un bordo alla finestra
void Window::addBox(){
    box(this->win, 0, 0);
};

// metodo per creare un bordo personalizzato
void Window::addCustomBorder(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br){
    wborder(this->win, ls, rs, ts, bs, tl, tr, bl, br);
};

// metodo per aggiungere una stringa a schermo
void Window::addStringAt(int yPos, int xPos, std::string str){
    mvwprintw(this->win, yPos, xPos, str.c_str());
};

// metodo per aggiungere un oggetto disegnabile a schermo
void Window::addDrawableObj(DrawableInterface drawableObj){
    this->addStringAt(drawableObj.getDrawableYPos(), drawableObj.getDrawableXPos(), drawableObj.getDrawableString());
};


// metodo per aggiungere un solo carattere a schermo
void Window::addCharAt(int yPos, int xPos, chtype char1){
    mvwaddch(this->win, yPos, xPos, char1);
};

// metodo per pulire il contenuto della finestra
void Window::clear(){
    wclear(this->win);
    // werase(this->win);
    this->addBox();
};

// metodo per aggiornare il contenuto della finestra
void Window::refresh(){
    wrefresh(this->win);
};

// metodi get
chtype Window::getInput(){
    return wgetch(this->win);
}
WINDOW* Window::getWin(){
    return this->win;
};
int Window::getWinHeight(){
    return this->height;
};
int Window::getWinWidth(){
    return this->width;
};