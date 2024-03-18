#include <iostream>
#include <ncurses.h>
//#include <Tetramini/Tetramino.hpp>
#include "./constants.hpp"

using namespace std;

int rotate(int px, int py, int r);
void drawScreen(char *, int , int);
void drawColorSqare(int x, int y, int color);
void drawTetromino(int x, int y, const char *type);
int rotateBlock(int i, int mode);

int main(int argc, char const *argv[])
{

    initscr();
    noecho();
    WINDOW *win = newwin(W_HEIGHT, W_WIDTH, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    const char *tetromino0 = SHAPE_0;
    const char *tetromino1 = SHAPE_1;
    const char *tetromino2 = SHAPE_2;
    
    // drawColorSqare(1,1, COLOR_CYAN);
    drawTetromino(10, 10, tetromino0);
    drawTetromino(1, 1, tetromino1);
    drawTetromino(15, 15, tetromino2);
    getch();
    endwin();

    return 0;
}

void drawColorSqare(int x, int y, int color){
    move(x, y);
    attron(COLOR_PAIR(color));
    addch('a');
    attroff(COLOR_PAIR(color));
}

void drawTetromino(int row, int col, const char *type){
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if(type[rotateBlock(y*4+x, 0)] != '.'){
                drawColorSqare(row + y, col + x, type[x]);
            }
        }
        
    }
    
}

int rotateBlock(int i, int mode)
{
        switch (mode)
        {
                case 0:
                        i = i;
                        break;
                case 1:  // 90 degrees
                        i = 12 - 4*(i % 4) + (i / 4);
                        break;
                case 2: // 180 degrees
                        i = 15 - 4*(i / 4) - (i % 4);
                        break;
                case 3: // 270 degrees
                        i = 3 + 4*( i % 4) - (i / 4);
        }
        return i;
}