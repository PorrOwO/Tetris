#include "TetrisGame.hpp"

#define HEIGHT 30
#define WIDTH 40

/*
    TODO
    - Uscita dalla finestra di gioco
    - Opzioni menù
*/

int main(int argc, char* argv[]){
    initscr();
    noecho();

    // istanza di TetrisGame
    TetrisGame board(HEIGHT, WIDTH);

    // main game loop
    while(!board.isOver()){
        board.processInput();
        board.updateState();
        board.updateDraw();
    } 

    refresh();
    getch();
    endwin();    
    return 0;
}