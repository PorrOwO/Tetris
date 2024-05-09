#pragma once

#include <ncurses.h>
#include "utils.hpp"

class Tetramino {
    public:
        Tetramino(WINDOW* win);
        ~Tetramino();
        
        // devo disegnare il tetramino in una finestra con ncurses
        void draw();

        void rotateLeft();
        void rotateRight();
        void moveLeft();
        void moveRight();
        void moveDown();
        void moveUp();

        void spawn();
        void setX(int x);
        void setY(int y);
        void setRotation(int rotation);
        void setType(int type);
        void setColor(int color);
        void setShape(const int shape[4][4]);
        
        int getX();
        int getY();
        int getRotation();
        int getType();
        int getColor();
        int getBlockValue(int x, int y);
        int shape[4][4];

    protected:
        WINDOW* win;
        int x;
        int y;
        int rotation;
        int type;
        int color;
};
