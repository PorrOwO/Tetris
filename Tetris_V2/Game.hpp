 #pragma once
 #include <ncurses.h>
#include "utils.hpp"
#include "TetrisBoard.hpp"
#include "Tetramino.hpp"

class Game{
protected: 
    WINDOW* mainWin;
    TetrisBoard board;
    Tetramino tetramino;

public: 
    ~Game();
    Game(WINDOW* win, TetrisBoard b, Tetramino t);
    int loop(); //restituisce il punteggio che poi andrà nella classifica

    
};