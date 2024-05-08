#include "Menu.hpp"

Menu::Menu(){
    this->win = Window();
    this->numOptions = 0;
    this->options = nullptr;
}

Menu::Menu(Window win, Option* options, int numOptions){
    this->win = win;
    this->options = options;
    this->numOptions = numOptions; // rendere le opzioni costanti? enum // rendere le opzioni costanti? enum??

    const int incr = 2; // numero di spazi tra un'opzione e un'altra
    int yVal = (this->win.getWin()->_maxy / 2) - incr; // pos iniziale y
    int xVal = (this->win.getWin()->_maxx) / 2; // pos iniziale x
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
    keypad(this->win.getWin(), true); // tasti freccia attivati
    while(true){
        for(int i = 0; i < this->numOptions; i++){
            // posizione del cursore
            int currentY = this->options[i].getY();
            int currentX = this->options[i].getX();

            // stringa corrispondente all'opzione
            string title = this->options[i].getTitle();

            // disegno a schermo
            if(i == highlight){
                wattron(this->win.getWin(), A_STANDOUT);
            }
            mvwprintw(this->win.getWin(), currentY, currentX, title.c_str());
            wattroff(this->win.getWin(), A_STANDOUT);
        }
        // gestione highlight
        choice = wgetch(this->win.getWin());
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

Window Menu::getWinObj(){
    return this->win;
}
