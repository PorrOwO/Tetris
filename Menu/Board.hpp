#pragma once
#include <ncurses.h>
#include "Window.hpp"
#define COLS 20
#define ROWS 40

class Board{
protected:
    int Matrice[ROWS][COLS];
    Window mainWindow;
    Window matrixWin;
    int rows, cols;//rowcharPos, colCharPos;
public:
    Board();
    Board(Window win);
    void draw();
    int getRows();
    int getCols();
    chtype getChar(int row, int col);
    Window getMatrixWin();
    void setCharMatrixat(int row, int col, chtype val);
};
