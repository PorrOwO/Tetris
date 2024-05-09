#include "Tetramino.hpp"
#include "utils.hpp"
#include <ncurses.h>
#include "TetrisBoard.hpp"
#include "Menu.hpp"
#include "Classifica.hpp"

int main() {
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(utils::RED, COLOR_RED, COLOR_BLACK);
    init_pair(utils::GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(utils::YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(utils::BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(utils::PURPLE, COLOR_BLUE, COLOR_RED);
    init_pair(utils::CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(utils::ORANGE, COLOR_YELLOW, COLOR_RED);
    srand(time(nullptr));
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

    Option options[utils::NUM_OPTIONS] = {
        Option(utils::OPTION_1),
        Option(utils::OPTION_2),
        Option(utils::OPTION_3),
    };

    Menu menu = Menu(mainWin, options, utils::NUM_OPTIONS);
    Tetramino tetramino = Tetramino(boardWin);
    TetrisBoard board = TetrisBoard(boardWin);
    Classifica cla= Classifica(mainWin);

    nodelay(boardWin, TRUE);
    keypad(boardWin, TRUE);

    tetramino.spawn();

    refresh();
    
    int esci = -1;

    int scelta=menu.draw();
    wrefresh(boardWin);
    wrefresh(mainWin);
    do{
       // box(menu.getWin(),0,0);
       wclear(mainWin);
       refresh();
       switch(scelta) {
            case 0: {
                box(mainWin,0,0);
                board.draw();
                tetramino.draw();

                wtimeout(boardWin, 50);
                chtype input = wgetch(boardWin);

                while(!isOver) {

                    wclear(mainWin);
                    box(mainWin, 0, 0);

                    pushDown = (fallDownCount == fallDownRate);
                    if(pushDown) {
                        fallDownCount = 0;
                        tetramino.moveDown();
                    }
                    switch (input) {
                        case 'q': {
                            isOver = true;
                            break;
                        }
                        case 'd': {
                            tetramino.moveRight();
                            if(!board.canPlaceTetramino(&tetramino)) {
                                tetramino.moveLeft();
                            }       
                            break;
                        }
                        case 'a': {
                            tetramino.moveLeft();
                            if(!board.canPlaceTetramino(&tetramino)) {
                                tetramino.moveRight();
                            }
                            break;
                        }
                        case 's': {
                            tetramino.moveDown();
                            if(!board.canPlaceTetramino(&tetramino)) {
                                tetramino.moveUp();
                            }
                            break;
                        }
                        case 'w': {
                            tetramino.rotateRight();
                            if(!board.canPlaceTetramino(&tetramino) && board.isHittingLeftWall(&tetramino)) {
                                tetramino.moveRight();
                            }

                            if(!board.canPlaceTetramino(&tetramino) && board.isHittingRightWall(&tetramino)) {
                                tetramino.moveLeft();
                            }
                            break;
                        }
                        case ' ': {
                            while(!board.isHittingFloor(&tetramino)) {
                                tetramino.moveDown();
                            }
                            break;
                        }
                        
                        if(board.isHittingFloor(&tetramino) && tetramino.getY() == 0) {
                            isOver = true;
                        }

                        if(board.isHittingFloor(&tetramino)) {
                            board.pinTetramino(&tetramino);
                            board.clearLines();
                            tetramino.spawn();
                        } else {
                            fallDownCount++;
                        }

                        wclear(boardWin);
                        box(mainWin, 0, 0);
                        tetramino.draw();
                        board.draw();
                        wrefresh(mainWin);
                        wrefresh(boardWin);

                        input = wgetch(boardWin);
                    }
                }
            }  
            case 1: {
                box(mainWin,0,0);
                cla=Classifica(mainWin);
                esci= cla.Mostra();
                break;
            }
            case 2: {
                esci = 0;
                break;
            }
            default: {
                break;
            }
        }
    }while(esci==-1);

    endwin();
    return 0;
}