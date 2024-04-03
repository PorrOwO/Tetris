#include <iostream>
#include <ncurses.h>
#include <string>
#include <thread>
#include "./Tetramini/Tetramino.cpp"
#include "./constants.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));
    initscr();
    noecho();
    WINDOW *win = newwin(W_HEIGHT, W_WIDTH, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);

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
    refresh();

    nodelay(stdscr, true);

    while (!isOver)
    {
        clear();
        box(win, 0, 0);
        test.draw(currentY, currentX, rotation);
        this_thread::sleep_for(50ms); //game tick rate
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
        default:
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

