#include "Board.hpp"
#include <ncurses.h>

Board::Board(){
    for(int i = 0; i < ROWS; i++){
        this->matrix[i][0] = 1;
        this->matrix[i][COLS - 1] = 1;
    }
    for(int i = 0; i < COLS; i++){
        this->matrix[ROWS - 1][i] = 1;
    }
}

Board::~Board(){
    // code //
}

void Board::drawColorSquare(int y, int x){
    const int xPadding = (W_WIDTH/2) - (COLS/2);
    const int yPadding = (W_HEIGHT/2) - (ROWS/2);

    move(y + yPadding, x + xPadding);
    addch('@');
}

void Board::draw(){
    for(int y = 0; y < ROWS; y++){
        for(int x = 0; x < COLS; x++){
            if(this->matrix[y][x]){
                drawColorSquare(y, x);
            }
        }
    }
}
