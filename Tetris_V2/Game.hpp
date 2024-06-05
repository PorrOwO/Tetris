#pragma once
#include <ncurses.h>
#include "utils.hpp"
#include "TetrisBoard.hpp"
#include "Tetramino.hpp"
#include "Hud.hpp"
#include <unistd.h>

class Game{
protected: 
    WINDOW* mainWin;
    TetrisBoard board;
    Tetramino tetramino;
    Hud hud;


public: 
    ~Game();
    Game(WINDOW* win, TetrisBoard b, Tetramino t, Hud h);
    int loop(); //restituisce il punteggio che poi andrà nella classifica

    int x = 0;
};