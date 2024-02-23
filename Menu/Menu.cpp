#include "Menu.hpp"

Option::Option(string optionTitle){
    this->optionTitle = optionTitle;
    /*
    this->currentCursorXPos = currentX;
    this->currentCursorYPos = currentY;
    */
};

string Option::getTitle(){
    return this->optionTitle;
};

int Option::getCurrentCursorXpos(){
    return this->currentCursorXPos;
};

int Option::getCurrentCursorYpos(){
    return this->currentCursorYPos;
};

void Option::setCurrentCursorXPos(int val){
    this->currentCursorXPos = val;
};

void Option::setCurrentCursorYPos(int val){
    this->currentCursorYPos = val;
};

BarraMenu::BarraMenu(WINDOW* win, Option* options, int numOptions){
    this->win = win;
    this->options = options;
    this->numOptions = numOptions;

    int yVal = 1;
    for(int i = 0; i < numOptions; i++){
        this->options[i].setCurrentCursorXPos(1);
        this->options[i].setCurrentCursorYPos(yVal);
        yVal += 2;
    }
};

void BarraMenu::draw(){
    for(int i = 0; i < this->numOptions; i++){
        // posizione del cursore
        int currentY = this->options[i].getCurrentCursorYpos();
        int currentX = this->options[i].getCurrentCursorXpos();

        // stringa corrispondente all'opzione
        string title = this->options[i].getTitle();

        // disegno a schermo
        wattron(this->win, A_STANDOUT);
        mvwprintw(this->win, currentY, currentX, title.c_str());
        wattroff(this->win, A_STANDOUT);
    }
};