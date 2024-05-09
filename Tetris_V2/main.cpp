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

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int winHeight = yMax - 10;
    int winWidth = xMax / 2;

    int yWinPos = (yMax / 2) - (winHeight / 2);
    int xWinPos = (xMax / 2) - (winWidth / 2);

    WINDOW* mainWin = newwin(winHeight, winWidth, yWinPos, xWinPos);
    box(mainWin, 0, 0);
    
    WINDOW* boardWin = newwin(utils::BOARD_HEIGHT, utils::BOARD_WIDTH, 
                              yWinPos + (winHeight / 2) - (utils::BOARD_HEIGHT / 2),
                              xWinPos + (winWidth / 2) - (utils::BOARD_WIDTH / 2));

    Option options[utils::NUM_OPTIONS] = {
        Option(utils::OPTION_1),
        Option(utils::OPTION_2),
        Option(utils::OPTION_3),
    };

    Menu menu = Menu(mainWin, options, utils::NUM_OPTIONS);
    TetrisBoard board = TetrisBoard(boardWin);
    Tetramino tetramino = Tetramino(boardWin);
    Classifica cla= Classifica(mainWin);

    nodelay(boardWin, TRUE);
    keypad(boardWin, TRUE);

    tetramino.spawn();
    refresh();   

    // box(mainWin,0,0);
    menu.draw();
    board.draw();
    tetramino.draw();

    wrefresh(boardWin);
    wrefresh(mainWin);

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
                break;

            case ' ':
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
        board.draw();
        tetramino.draw();
        wrefresh(mainWin);
        wrefresh(boardWin);

        input = wgetch(boardWin);
    }  

    endwin();
    return 0;
}
