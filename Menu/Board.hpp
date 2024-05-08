#pragma once

#include <ncurses.h>
#include "Window.hpp"
#include "../constants.hpp"

class Board{
    protected:
        Window mainWindow;
        Window matrixWin;
        int matrix[ROWS][COLS] = {};
    public:
        Board();
        Board(Window win);
        void drawSquare(int y, int x);
        void draw();
        int getState(int row, int col);
        Window getMatrixWinObj();
        Window getMainWinObj();
};
