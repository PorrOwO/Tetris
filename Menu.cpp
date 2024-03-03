#include "Menu.hpp"

// costruttori
Menu::Menu(){
    this->win = Window();
}

Menu::Menu(Window win, Option* options, int numOptions){
    this->win = win;
    this->options = options;
    this->numOptions = numOptions;
    // this->highlight = highlight;
    const int incr = 2;
    int yVal = ((this->win.getWinHeight()) / 2) - incr;
    int xVal = (this->win.getWinWidth()) / 2;
    int offset;
    for (int i = 0; i < this->numOptions; i++){
        this->options[i].setOptionOpenState(false);
        offset = this->options[i].getOptionTitle().length();
        this->options[i].setXCursorPos(xVal - (offset / 2));
        this->options[i].setYCursorPos(yVal);
        yVal += incr;
    }
};

// distruttore
/*
Menu::~Menu(){
    // delwin(this->getWin().getWin());
    // this->win = Window();
    this->win.clear();
};
*/

// metodo per stampare a schermo il menù
void Menu::draw(){
    // int hl = this->highlight;
    // int highlight = 0;
    this->win.addDrawableObj(DrawableInterface(this->win.getWinHeight()-3, (this->win.getWinWidth()/2)-22, "press 'w(s)' or 'key_up(down)' to navigate")); // quel 22 è la metà della lunghezza della stringa
    this->win.addDrawableObj(DrawableInterface(this->win.getWinHeight()-2, (this->win.getWinWidth() / 2)-20, "press 'key_enter' to select any option "));

    for(int i = 0; i < this->numOptions; i++){
        int currentY = this->options[i].getYCursorPos();
        int currentX = this->options[i].getXCursorPos();
        std::string title = this->options[i].getOptionTitle();
        if(i == this->highlight){
            wattron(this->win.getWin(), A_REVERSE);
        }
        this->win.addDrawableObj(DrawableInterface(currentY, currentX, title));
        // this->win.addStringAt(currentY, currentX, title);
        wattroff(this->win.getWin(), A_REVERSE);
        // this->win.refresh();
    }
};

void Menu::incrHighlight(){
    this->highlight++;
};

void Menu::decrHighlight(){
    this->highlight--;
}

void Menu::setHighlight(int val){
    this->highlight = val;
};

// metodi get
// ritorna la finestra
Window Menu::getWin(){
    return this->win;
};
// ritorna il numero di opzioni
int Menu::getNumOptions(){
    return this->numOptions;
};
// ritorna il puntatore ad una opzione
Option Menu::getOption(){
    return this->options[this->highlight];
};
int Menu::getHighlight(){
    return this->highlight;
};
