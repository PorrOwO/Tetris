#include "TetrisBoard.hpp"
#include "utils.hpp"
#include <ncurses.h>

TetrisBoard::TetrisBoard(WINDOW* win) {
    xPos = 0;
    yPos = 0;
    this->win = win;
    this->xPos = 0;
    this->yPos = 0;
    // this->xPos = this->win->_maxx / 2 - utils::BOARD_WIDTH / 2;
    // this->yPos = this->win->_maxy / 2 - utils::BOARD_HEIGHT / 2;
    for(int i = 0; i < utils::BOARD_HEIGHT; i++) {
        this->board[i][0] = -1;
        this->board[i][utils::BOARD_WIDTH - 1] = -1;
    }

    for(int i = 0; i < utils::BOARD_WIDTH; i++) {
        this->board[utils::BOARD_HEIGHT - 1][i] = -1;
    }
}

TetrisBoard::~TetrisBoard() {
}

void TetrisBoard::draw() {
    for(int i = 0; i < utils::BOARD_HEIGHT; i++) {
        for(int j = 0; j < utils::BOARD_WIDTH; j++) {
            if(this->board[i][j] == -1) {
                mvwaddch(this->win, i + this->yPos, j + this->xPos, ACS_CKBOARD);
            }else if (this->board[i][j] == 1)
            {
                mvwaddch(this->win, i + this->yPos, j + this->xPos, ACS_CKBOARD);
            }
            
        }
    }
}

void TetrisBoard::update() {
}

// controlla se il tetramino può essere inserito nella posizione corrente
bool TetrisBoard::canPlaceTetramino(Tetramino* tetramino) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tetramino->shape[i][j] != 0) {
                if(this->board[i + tetramino->getY()][j + tetramino->getX()] != 0) {
                    return false;
               }
            }
        }
    }
    return true;
}

// se la riga è piena ritorna true, altrimenti false
bool TetrisBoard::isLineFull(int line) {
    for(int i = 1; i < utils::BOARD_WIDTH - 1; i++) {
        if(this->board[line][i] == 0) {
            return false;
        }
    }
    return true;
}

bool TetrisBoard::isHittingLeftWall(Tetramino* tetramino) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tetramino->shape[i][j] != 0) {
                if(tetramino->getX() + j == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool TetrisBoard::isHittingRightWall(Tetramino* tetramino) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tetramino->shape[i][j] != 0) {
                if(tetramino->getX() + j == utils::BOARD_WIDTH - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool TetrisBoard::isHittingFloor(Tetramino* tetramino) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tetramino->shape[i][j] != 0) {
                if(tetramino->getY() + i == utils::BOARD_HEIGHT - 1 || !this->canPlaceTetramino(tetramino)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void TetrisBoard::pinTetramino(Tetramino* tetramino) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(tetramino->shape[i][j] != 0) {
                this->board[i + tetramino->getY() -1 ][j + tetramino->getX()] = 1;
            }
        }
    }
}

// se la riga è vuota ritorna true, altrimenti false
bool TetrisBoard::isLineEmpty(int line) {
    for(int i = 1; i < utils::BOARD_WIDTH - 1; i++) {
        if(this->board[line][i] != 0) {
            return false;
        }
    }
    return true;
}

void TetrisBoard::clearLines() {
    for(int i = 0; i < utils::BOARD_HEIGHT - 1; i++) {
        if(this->isLineFull(i)) {
            for(int j = i; j > 0 && !this->isLineEmpty(j); j--) {
                for(int k = 1; k < utils::BOARD_WIDTH - 1; k++) {
                    this->board[j][k] = this->board[j - 1][k];
                }
            }
        }
    }
}

bool TetrisBoard::isGameOver() {
    return false;
}

void TetrisBoard::reset() {
}
