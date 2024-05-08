#pragma once

#include "Tetramino.hpp"
#include "utils.hpp"
#include <ncurses.h>

class TetrisBoard {
    public:
        TetrisBoard(WINDOW* win);
        ~TetrisBoard();
        void draw();
        void update();
        bool isLineFull(int line);
        bool isLineEmpty(int line);
        void clearLines();
        bool isGameOver();
        void reset();
        bool isHittingWall(Tetramino* tetramino);
        bool isHittingLeftWall(Tetramino* tetramino);
        bool isHittingRightWall(Tetramino* tetramino);
        bool isHittingFloor(Tetramino* tetramino);
        bool canPlaceTetramino(Tetramino* tetramino);
        int board[utils::BOARD_HEIGHT][utils::BOARD_WIDTH] = {};
    protected:
        WINDOW* win;
        // posizione della board rispetto alla finestra
        int xPos;
        int yPos;
};
