#include "Game.hpp"
//#include "Hud.hpp"

Game::~Game()
{};

Game::Game(WINDOW* win, TetrisBoard b, Tetramino t, Hud h)
{
    this->mainWin=win;
    this->board=b;
    this->tetramino=t;
    this->hud=h;
};

int Game::loop()
{
    bool isOver=false;
    
    bool pushDown= false;
    int fallDownCount=0;
    int fallDownRate=20;

    this->tetramino.spawn();
    //sleep(1);
    hud.nextPiece();
    hud.printHUD();
    refresh();
    this->board.draw();
    this->tetramino.draw();
    
    wrefresh(this->mainWin);
    wrefresh(this->board.getWin());
    wrefresh(this->hud.getWin());

    wtimeout(this->board.getWin(),50);
    chtype input=wgetch(this->board.getWin());

     while(!isOver) {

        //wclear(mainWin);
        box(mainWin, 0, 0);

        pushDown = (fallDownCount == fallDownRate);
        if(pushDown) {
            fallDownCount = 0;
            this->tetramino.moveDown();
        }
        switch (input) {
            case 'q': 
                isOver = true;
                break;

            case 'd': 
                this->tetramino.moveRight();
                if(!this->board.canPlaceTetramino(&this->tetramino)) {
                    this->tetramino.moveLeft();
                }       
                break;

            case 'a': 
                this->tetramino.moveLeft();
                if(!this->board.canPlaceTetramino(&this->tetramino)) {
                    this->tetramino.moveRight();
                }
                break;

            case 's': 
                this->tetramino.moveDown();
                if(!this->board.canPlaceTetramino(&this->tetramino)) {
                    this->tetramino.moveUp();
                }
                break;

            case 'w': 
                this->tetramino.rotateRight();
                if(!this->board.canPlaceTetramino(&this->tetramino) && this->board.isHittingLeftWall(&this->tetramino)) {
                    this->tetramino.moveRight();
                }

                if(!this->board.canPlaceTetramino(&this->tetramino) && this->board.isHittingRightWall(&this->tetramino)) {
                    this->tetramino.moveLeft();
                }
                break;

            case ' ':
                while(!this->board.isHittingFloor(&this->tetramino)) {
                    this->tetramino.moveDown();
                }
                break;
        }

        if(this->board.isHittingFloor(&this->tetramino) && this->tetramino.getY() == 0) {
            isOver = true;
        }

        if(this->board.isHittingFloor(&this->tetramino)) {
            this->board.pinTetramino(&this->tetramino); 
            //this->board.clearLines();
            hud.setLines(this->board.clearLines());
            if(hud.getLines() > 0){
                this->hud.computeScore();
                this->hud.printHUD();
            }   
            hud.setLines(0);
            this->tetramino.spawn();
            
        } else {
            fallDownCount++;
        }
        wrefresh(this->hud.getWin());
        wclear(this->board.getWin());
        box(mainWin, 0, 0);
        this->board.draw();
        this->tetramino.draw();
        wrefresh(mainWin);
        wrefresh(this->board.getWin());
        

        input = wgetch(this->board.getWin());
    }


    return 10;


}
