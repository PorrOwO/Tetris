#include <iostream>
#include <ncurses.h>
#include <string>
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
    chtype input = getch();
    
    
        // input = getch();
        //test.draw(5, 5, rotation);
        switch(input){
            case 'a':
            case 'd':
                clear();
                // mvwprintw(win, 1, 1, to_string(rotation).c_str());
                rotation++;
                test.draw(5, 5, 1);
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


    getch();
    refresh();
    endwin();

    return 0;
}

