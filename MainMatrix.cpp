#include "MainMatrix.hpp"

/*
MainMatrix::MainMatrix(){
    this->rows = 0;
    this->cols = 0;
};
*/

MainMatrix::MainMatrix(){
    this->matrixWin = Window(40,80); // le misure della finestra sono probabilmente errate --> si vedrà in seguito
    this->rows = ROWS;
    this->cols = COLS;
    // this->matrixWin = win;
    // matrice nulla
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->MATRIXBOARD[i][j] = (char)0;
        }
    }
    // this->matrixWin.addBox();
};

// metodo per posizionare la matrice e settare il bordo.
// non mi fa impazzire però per adesso va bene --> da cambiare
void MainMatrix::draw(){
    const chtype LEFT_SIDE = '<';
    const chtype RIGHT_SIDE = '>';
    const chtype TOP_SIDE = ' ';
    const chtype BOTTOM_SIDE = 'v';
    
    const chtype TOP_LEFT_CORNER = '@';
    const chtype TOP_RIGHT_CORNER = '@';
    const chtype BOTTOM_LEFT_CORNER = '^';
    const chtype BOTTOM_RIGHT_CORNER = '^';
    
    this->matrixWin.addCustomBorder(LEFT_SIDE, RIGHT_SIDE, TOP_SIDE, BOTTOM_SIDE, TOP_LEFT_CORNER, TOP_RIGHT_CORNER, BOTTOM_LEFT_CORNER, BOTTOM_RIGHT_CORNER);
    // this->matrixWin.addBox();
    // this->matrixWin.addCustomBorder(0,0,0,0,0,0,0,0);

    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrixWin.addCharAt(i, j, this->MATRIXBOARD[i][j]);
        }
    }
};

int MainMatrix::getRows(){
    return this->rows;
};
int MainMatrix::getCols(){
    return this->cols;
};

/*
chtype MainMatrix::getChar(int row, int col){
    return this->MATRIXBOARD[row][col];
};
*/

Window MainMatrix::getMatrixWin(){
    return this->matrixWin;
};

void MainMatrix::setCharMatrixAt(int row, int col, chtype val){
    this->MATRIXBOARD[row][col] = val;
}