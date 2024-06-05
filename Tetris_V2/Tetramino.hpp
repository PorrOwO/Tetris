#pragma once

#include <ncurses.h>
#include "utils.hpp"
#include "Drawable.hpp"
class Tetramino:public Drawable{
    public:
        Tetramino(WINDOW* win);
        Tetramino(WINDOW *win, int x, int y);
        Tetramino();
        
        void draw();

        void rotateLeft();
        void rotateRight();
        void moveLeft();
        void moveRight();
        void moveDown();
        void moveUp();

        void spawn(int x, int y);

        void setColor(int color);
        void setShape(const int shape[4][4]);
        
        int getColor();
        int getBlockValue(int x, int y);
        
        int shape[4][4];


    protected:
        int color;
};
