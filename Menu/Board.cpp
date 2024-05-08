#include "Board.hpp"
#include <ncurses.h>

Board::Board() {
    this->matrixWin = Window();
    this->mainWindow = Window();
};

Board::Board(Window win) {
    
    for(int i = 0; i < ROWS; i++) {
        this->matrix[i][0] = 1;
        this->matrix[i][COLS - 1] = 1;
    }
    for(int i = 0; i < COLS; i++) {
        this->matrix[ROWS - 1][i] = 1;
    }

    this->mainWindow = win;

    int yPos = (this->mainWindow.getHeight() / 2) - (ROWS / 2) - 1;
    int xPos = (this->mainWindow.getWidth() / 2) - (COLS/ 2) + 1;

    this->matrixWin = Window(ROWS - 1, COLS - 2, yPos, xPos);
};

void Board::drawSquare(int y, int x) {
    
    const int yPadding = (this->mainWindow.getHeight() / 2) - (ROWS / 2);
    const int xPadding = (this->mainWindow.getWidth() / 2) - (COLS / 2);

    mvaddch(y + yPadding, x + xPadding, '@');
};

void Board::draw() {
    // box(this->mainWindow.getWin(),0,0);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(this->matrix[i][j])
                drawSquare(i, j);
        }
    }
}

Window Board::getMatrixWinObj() {
    return this->matrixWin;
}

Window Board::getMainWinObj() {
    return this->mainWindow;
}
