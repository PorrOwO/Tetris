#include "TetrisGame.hpp"

#define HEIGHT 40
#define WIDTH 80

/*
    TODO
    X Uscita dalla finestra di gioco
    - Opzioni menù
*/

int main(int argc, char* argv[]){
    initscr();
    noecho();

    // istanza di TetrisGame
    TetrisGame board(HEIGHT, WIDTH);
    Window menu(board.getWin()->_maxy, board.getWin()->_maxx);
        
    // instanziare menu e opzioni
    // ...
    
    // main game loop
    while(!board.isOver()){
        board.processInput();
        board.updateState();
        board.updateDraw();
    } 

    // refresh();
    wgetch(board.getWin());
    endwin();    
    return 0;
}