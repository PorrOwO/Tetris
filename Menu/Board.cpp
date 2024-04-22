#include "Board.hpp"

Board::Board() {
    this->matrixWin = Window();
    this->mainWindow = Window();
};

Board::Board(Window win) {
    this->mainWindow = win;
    this->rows = ROWS;
    this->cols = COLS;
    int y = (this->mainWindow.getHeight() / 2) - (this->rows/2) + 1;
    int x = (this->mainWindow.getWidth() / 2) - (this->cols/2) + 1; 

    // finestra dove vengono disegnati i tetramini deve
    // essere più piccola per refreshare senza perdere la board
    this->matrixWin = Window(ROWS, COLS, y, x);


    /*for(int i=0; i<this->rows; i++) {
        for(int j=0; j<this->cols; j++) {
            this->Matrice[i][j]=0;
        }
    }*/

};

void Board::draw() {
    box(this->mainWindow.getWin(),0,0);

    //wborder(this->matrixWin.getWin(),LEFT_SIDE, RIGHT_SIDE, TOP_SIDE, BOTTOM_SIDE, TOP_LEFT_CORNER, TOP_RIGHT_CORNER, BOTTOM_LEFT_CORNER, BOTTOM_RIGHT_CORNER);
    int y = (this->mainWindow.getHeight() / 2) - (this->rows/2) + 1;
    int x = (this->mainWindow.getWidth() / 2) - (this->cols/2) + 1; // parte dal centro boh ?
    for(int i=0; i<this->rows; i++)
    {
        // wmove(this->mainWindow.getWin(), y + i, x);
        for(int j=0;j<this->cols; j++)
        {
            // wmove(this->mainWindow.getWin(), y + i, x + j);
            mvwaddch(this->mainWindow.getWin(), y + i, x + j, (char)this->MATRIXBOARD[i][j]);
        }
    }
    wrefresh(this->mainWindow.getWin());
    wrefresh(this->matrixWin.getWin());
    wgetch(this->mainWindow.getWin());
};

Window Board::getMatrixWinObj() {
    return this->matrixWin;
}
