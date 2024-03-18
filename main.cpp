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

    // chtype input = wgetch(win);

    Tetramino test = Tetramino();
    // drawColorSqare(1,1, COLOR_CYAN);
    test.draw(5, 5, 0);
    refresh();

    int rotation = 0;
    bool isOver = false;
    chtype input;
        
    while (!isOver)
    {
        this_thread::sleep_for(50ms);
        input = getch();
        switch (input)
        {
        case 'a':
            clear();
            // mvwprintw(win, 1, 1, to_string(rotation).c_str());
            rotation--;
            if (rotation < 0)
            {
                rotation = 3;
            }
            test.draw(5, 5, rotation);
            // refresh();
            // mvwprintw(win, 1, 1, to_string(rotation).c_str());
            break;
        case 'd':
            clear();
            // mvwprintw(win, 1, 1, to_string(rotation).c_str());
            if (rotation > 3)
            {
                rotation = 0;
            }
            rotation++;
            test.draw(5, 5, rotation);
            // refresh();
            // mvwprintw(win, 1, 1, to_string(rotation).c_str());
            break;
        case 10:
            isOver = true;
            break;
        default:
            break;
        }
        box(win, 0, 0);
        refresh();
    }

    getch();
    refresh();
    endwin();

    return 0;
}

