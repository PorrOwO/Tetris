#pragma once
#include <ncurses.h>
#include "../constants.hpp"

class Board{
    public:
        Board();
        ~Board();
        void draw();
        void drawColorSquare(int x, int y);
    protected:
        int matrix[ROWS][COLS] = {};
};
