#include "Board.hpp"

Board::Board() {
    this->matrixWin = Window();
    this->mainWindow = Window();
};

Board::Board(Window win) {
    this->mainWindow = win;
    int y = this->mainWindow.getY()*2 + 12;
    int x = this->mainWindow.getX()*2 - 13;

    // finestra dove vengono disegnati i tetramini deve
    // essere più piccola per refreshare senza perdere la board
    this->matrixWin = Window(ROWS - 1, COLS - 2, y, x);
    this->rows = ROWS;
    this->cols = COLS;


    /*for(int i=0; i<this->rows; i++) {
        for(int j=0; j<this->cols; j++) {
            this->Matrice[i][j]=0;
        }
    }*/

};

void Board::draw() {
    box(this->mainWindow.getWin(),0,0);

    //wborder(this->matrixWin.getWin(),LEFT_SIDE, RIGHT_SIDE, TOP_SIDE, BOTTOM_SIDE, TOP_LEFT_CORNER, TOP_RIGHT_CORNER, BOTTOM_LEFT_CORNER, BOTTOM_RIGHT_CORNER);
    int y = this->mainWindow.getY() * 2 +7;
    int x = this->mainWindow.getX() - 14; // parte dal centro boh ?
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
