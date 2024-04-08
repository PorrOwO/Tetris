#include <iostream>
#include <ncurses.h>
#include <string>
#include <thread>
#include "./Tetramini/Tetramino.cpp"
#include "./constants.hpp"
#include "./Board/Board.cpp"
#include "Board/Board.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // main window
    srand(time(0));
    initscr();
    noecho();
    WINDOW *win = newwin(W_HEIGHT, W_WIDTH, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);

    // tetromino window --> playfield
    const int xPad = (W_WIDTH/2) - (COLS/2) + 1;
    const int yPad = (W_HEIGHT/2) - (ROWS/2) + 1;
    WINDOW* boardWin = newwin(ROWS-1, COLS-1, yPad, xPad);
    refresh();
    box(boardWin, 104, 104);
    wrefresh(boardWin);

    int rotation = 0;
    bool isOver = false;
    bool pushDown = false;
    chtype input;
    int fallDownRate = 20;
    int fallDownCount = 0;

    int currentY = 0;
    int currentX = 0;
    // chtype input = wgetch(win);

    Tetramino test = Tetramino();
    // drawColorSqare(1,1, COLOR_CYAN);
    
    Board testBoard = Board();
    // testBoard.draw();

    refresh();

    nodelay(stdscr, true);

    keypad(stdscr, true);

    while (!isOver)
    {
        // clear();
        box(win, 0, 0);
        // test.draw(currentY, currentX, rotation);
        this_thread::sleep_for(50ms); //game tick rate
        
        testBoard.draw();

        //every n game tick push down the tetromino
        fallDownCount++;
        pushDown = (fallDownCount == fallDownRate);

        if(pushDown){
            fallDownCount = 0;
            currentY++;
        }

        input = getch();
        switch (input)
        {
        case 'a':
            clear();
            rotation--;
            if (rotation < 0)
            {
                rotation = 3;
            }
            test.draw(currentY, currentX, rotation);
            break;
        case 'd':
            clear();
            if (rotation > 3)
            {
                rotation = 0;
            }
            rotation++;
            test.draw(currentY, currentX, rotation);
            break;
        case 10:
            isOver = true;
            break;
        case KEY_LEFT:
            currentX--;
            clear();
            test.draw(currentY, currentX, rotation);
            break;
        case KEY_RIGHT:
            currentX++;
            clear();
            test.draw(currentY, currentX, rotation);
            break;
        default:
            if(pushDown){
                clear();
            }
            // testBoard.draw();
            test.draw(currentY, currentX, rotation);
            break;
        }
        refresh();
    }

    getch();
    refresh();
    endwin();

    return 0;
}

