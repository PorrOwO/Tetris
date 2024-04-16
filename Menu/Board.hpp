#pragma once

#include <ncurses.h>
#include "Window.hpp"
#include "../constants.hpp"

class Board{
protected:
    //int Matrice[ROWS][COLS];
    Window mainWindow;
    Window matrixWin;
    int rows, cols;//rowcharPos, colCharPos;
public:
    Board();
    Board(Window win);
    void draw();
    Window getMatrixWinObj();
};
