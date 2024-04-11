#include "Board.hpp"


Board::Board()
{
    this->matrixWin=Window();
    this->mainWindow=Window();
};

Board::Board(Window win)
{
  this->mainWindow=win;
  int y=this->mainWindow.getY()*2+7;
  int x=this->mainWindow.getX()*2-(40/2);
  this->matrixWin=Window(30,40,y,x);
  this->rows=ROWS;
  this->cols=COLS;
  /*for(int i=0; i<this->rows; i++)
  {
      for(int j=0; j<this->cols; j++)
      {
          this->Matrice[i][j]=0;
    }
}*/
};


void Board::draw()
{   box(this->mainWindow.getWin(),0,0);
    const chtype LEFT_SIDE = '<';
    const chtype RIGHT_SIDE = '>';
    const chtype TOP_SIDE = ' ';
    const chtype BOTTOM_SIDE = 'v';

    const chtype TOP_LEFT_CORNER = '@';
    const chtype TOP_RIGHT_CORNER = '@';
    const chtype BOTTOM_LEFT_CORNER = '^';
    const chtype BOTTOM_RIGHT_CORNER = '^';
    wborder(this->matrixWin.getWin(),LEFT_SIDE, RIGHT_SIDE, TOP_SIDE, BOTTOM_SIDE, TOP_LEFT_CORNER, TOP_RIGHT_CORNER, BOTTOM_LEFT_CORNER, BOTTOM_RIGHT_CORNER);
    // this->matrixWin.addBox();
    // this->matrixWin.addCustomBorder(0,0,0,0,0,0,0,0);
    //box(matrixWin.getWin(),0,0);
    /*for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrixWin.addCharAt(i+1, j+5, this->Matrice[i][j]);
        }
   }*/

    wrefresh(this->mainWindow.getWin());
    wrefresh(this->matrixWin.getWin());
    wgetch(this->mainWindow.getWin());
};

Window Board::getMatrixWin(){
    return this->matrixWin;
}
