#include "Tetramino.hpp"
#include "../constants.hpp"
#include <ncurses.h>

Tetramino::Tetramino()
{
    int tipo = rand() % 7;
    
    switch (tipo)
    {
    case 0:
        this->type = SHAPE_0;
        break;
    case 1:
        this->type = SHAPE_1;
        break;
    case 2:
        this->type = SHAPE_2;
        break;
    case 3:
        this->type = SHAPE_3;
        break;
    case 4:
        this->type = SHAPE_4;
        break;
    case 5:
        this->type = SHAPE_5;
        break;
    case 6:
        this->type = SHAPE_6;
        break;
    default:
        break;
    }
}

int Tetramino::rotateBlock(int i, int mode)
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

void Tetramino::drawColorSqare(int x, int y){
    move(x, y);
    // attron(COLOR_PAIR(color));
    addch('#');
    // move(x + 1, y);
    // addch(' '|A_REVERSE);
    // addch(0x2588);
    // attroff(COLOR_PAIR(color));
}

void Tetramino::draw(int row, int col, int rot){
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if(this->type[rotateBlock(y*4+x, rot)] != '.'){
                drawColorSqare(row + y, col + x);
                drawColorSqare(row + y, col + x);
            }
        }
        
    }
}
