#include <iostream>
#include <ncurses.h>
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

    Tetramino test = Tetramino();
    // drawColorSqare(1,1, COLOR_CYAN);
    test.draw(5, 5, 0);
    getch();
    endwin();

    return 0;
}

