#include "Tetramino.hpp"
#include "utils.hpp"
#include <ncurses.h>
#include "TetrisBoard.hpp"
#include <iostream>
#include <thread>

int main() {
    initscr();
    noecho();
    curs_set(0);

    bool isOver = false;

    // caduta tetramini
    bool pushDown = false;
    int fallDownCount = 0;
    int fallDownRate = 20;

    WINDOW* mainWin = newwin(40, 40, 1, 1);
    box(mainWin, 0, 0);

    WINDOW* boardWin = newwin(utils::BOARD_HEIGHT, utils::BOARD_WIDTH, 
                              20 - utils::BOARD_HEIGHT / 2, 
                              20 - utils::BOARD_WIDTH / 2);

    Tetramino tetramino = Tetramino(boardWin);
    TetrisBoard board = TetrisBoard(boardWin);

    nodelay(boardWin, TRUE);
    keypad(boardWin, TRUE);

    tetramino.setShape(utils::SHAPE_4);

    refresh();
    
    board.draw();
    tetramino.draw();

    wrefresh(boardWin);
    wrefresh(mainWin);
        
    wtimeout(boardWin, 50);
    chtype input = wgetch(boardWin);

    while(input != 'q') {

        fallDownCount++;
        pushDown = (fallDownCount == fallDownRate);
        if(pushDown) {
            fallDownCount = 0;
            tetramino.moveDown();
        }
        switch (input) {
            case 'q':
                isOver = true;
                break;
            case 'd':
                tetramino.moveRight();
                if(!board.canPlaceTetramino(&tetramino)) {
                    tetramino.moveLeft();
                }
                break;
            case 'a':
                tetramino.moveLeft();
                if(!board.canPlaceTetramino(&tetramino)) {
                    tetramino.moveRight();
                }
                break;
            case 's':
                tetramino.moveDown();
                if(!board.canPlaceTetramino(&tetramino)) {
                    tetramino.moveUp();
                }
                break;
            case 'w':
                tetramino.rotateRight();
                if(!board.canPlaceTetramino(&tetramino) && board.isHittingLeftWall(&tetramino)) {
                    tetramino.moveRight();
                }

                if(!board.canPlaceTetramino(&tetramino) && board.isHittingRightWall(&tetramino)) {
                    tetramino.moveLeft();
                }
                
                // TODO: si muove troppo in alto?
                if(!board.canPlaceTetramino(&tetramino) && board.isHittingFloor(&tetramino)) {
                    tetramino.moveUp();
                }
                break;
            default:
                break;
        }

        if(board.isHittingFloor(&tetramino)) {
            tetramino.setY(utils::BOARD_HEIGHT - 2);
        }

        wclear(boardWin);
        box(mainWin, 0, 0);
        tetramino.draw();
        board.draw();
        wrefresh(mainWin);
        wrefresh(boardWin);

        input = wgetch(boardWin);
    }

    endwin();
    return 0;
}
