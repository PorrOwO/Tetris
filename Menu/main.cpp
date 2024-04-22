//#include "Menu.hpp"
#include "Tetris.hpp"

void createBox(WINDOW* win, int c1, int c2){
    box(win, c1, c2);
    refresh();
};

int main(int argc, char* argv[]){
    initscr();
    noecho();

    // creazione finestra del menù;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    // dimensioni riferite al terminale completamente espanso
    // potenzialmente da cambiare --> forse troppo grande
    const int HEIGHT = yMax - 10;
    const int WIDTH = xMax / 2;

    // finestra centrata sullo stdscr    
     //WINDOW* winM = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
    //WINDOW* winM = newwin(HEIGHT, WIDTH, (yMax/2)-(HEIGHT/2), (xMax/2)-(WIDTH/2));
    //createBox(winM, 0, 0);
    
    // Array di tutte le possibili opzioni del menù
    const int numOptions = 3;
    Option options[numOptions] = {
        Option("NEWGAME"),
        Option("LEADERBOARD"),
        Option("EXIT")    
    };
    yMax = yMax/2-(HEIGHT/2);
    xMax = xMax/2-(WIDTH/2);

    Window win = Window(HEIGHT,WIDTH,yMax,xMax);
    Menu optionMenu = Menu(win, options, numOptions);
    Tetris Inizio= Tetris(optionMenu);

    Inizio.gameLoop();

    refresh();

    endwin();
}
