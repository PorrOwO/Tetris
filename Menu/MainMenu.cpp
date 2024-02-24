#include "Menu.hpp"

void createBox(WINDOW* win, int c1, int c2){
    box(win, c1, c2);
    refresh();
};

int main(int argc, char* argv[]){
    initscr();

    // creazione finestra del menù;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    /*
    printw(to_string(yMax).c_str());
    move(1,0);
    printw(to_string(xMax).c_str());
    */

    // dimensioni riferite al terminale completamente espanso
    // potenzialmente da cambiare --> forse troppo grande
    const int HEIGHT = yMax - 10;
    const int WIDTH = xMax / 2;

    // finestra centrata sullo stdscr    
    // WINDOW* winM = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
    WINDOW* winM = newwin(HEIGHT, WIDTH, (yMax/2)-(HEIGHT/2), (xMax/2)-(WIDTH/2));
    createBox(winM, 0, 0);
    
    // Array di tutte le possibili opzioni del menù
    const int numOptions = 3;
    Option options[numOptions] = {
        Option("NEWGAME"),
        Option("LEADERBOARD"),
        Option("EXIT")    
    };

    /*
    options[0].setCurrentCursorXPos(1);
    options[1].setCurrentCursorXPos(1);
    options[2].setCurrentCursorXPos(1);

    options[0].setCurrentCursorYPos(1);
    options[1].setCurrentCursorYPos(3);
    options[2].setCurrentCursorYPos(5);
    */

    BarraMenu Menu = BarraMenu(winM, options, numOptions);
    Menu.draw();    

    refresh();
    wgetch(winM);
    endwin();
}