#include "Menu.hpp"
#include <ncurses.h>

Menu::Menu(){
    this->win = nullptr;
    this->numOptions = 0;
    this->options = nullptr;
}

Menu::Menu(WINDOW* win, Option* options, int numOptions){
    this->win = win;
    this->options = options;
    this->numOptions = numOptions; // rendere le opzioni costanti? enum // rendere le opzioni costanti? enum??

    int yMax, xMax;
    getmaxyx(this->win, yMax, xMax);
    const int incr = 2; // numero di spazi tra un'opzione e un'altra
    int yVal = (yMax / 2) - incr;
    int xVal = (xMax) / 2;
    //int yVal = (this->win->_maxy / 2) - incr; // pos iniziale y
    //int xVal = (this->win->_maxx) / 2; // pos iniziale x
    int offset; // offset per centrare le opzioni
    for(int i = 0; i < numOptions; i++){
        offset = this->options[i].getTitle().length();
        this->options[i].setX(xVal - (offset / 2));
        this->options[i].setY(yVal);
        yVal += incr;
    }
};

int Menu::draw(){ //draw ritorna la scelta dell'utente'
    int choice;
    int highlight = 0;
    keypad(this->win, true); // tasti freccia attivati
    while(true){
        for(int i = 0; i < this->numOptions; i++){
            // posizione del cursore
            int currentY = this->options[i].getY();
            int currentX = this->options[i].getX();

            // stringa corrispondente all'opzione
            std::string title = this->options[i].getTitle();

            // disegno a schermo
            if(i == highlight){
                wattron(this->win, A_STANDOUT);
            }
            mvwprintw(this->win, currentY, currentX, "%s",title.c_str());
            wattroff(this->win, A_STANDOUT);
        }
        // gestione highlight
        choice = wgetch(this->win);
        switch(choice){
            case KEY_UP:
                highlight--;
                if(highlight == -1){
                    highlight = 2; // highlight = 0
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 3){
                    highlight = 0; // highlight = 2;
                }
                break;
            default:
                break;
        }
        if(choice == 10){
            break;
        }
    }
    return highlight;
};

WINDOW* Menu::getWin(){
    return this->win;
}
