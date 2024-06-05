#pragma once

#include "Tetramino.hpp"
#include "utils.hpp"
#include <ncurses.h>

class TetrisBoard:public Drawable{
    public:
        TetrisBoard(WINDOW* win);
        TetrisBoard();
        void draw();
        bool isLineFull(int line);
        bool isLineEmpty(int line);
        int clearLines();
        void reset();
        bool isHittingLeftWall(Tetramino* tetramino);
        bool isHittingRightWall(Tetramino* tetramino);
        bool isHittingFloor(Tetramino* tetramino);
        void pinTetramino(Tetramino* tetramino);
        bool canPlaceTetramino(Tetramino* tetramino);

        int board[utils::BOARD_HEIGHT][utils::BOARD_WIDTH] = {};

    protected:
};
