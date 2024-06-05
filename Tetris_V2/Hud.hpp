#pragma once
#include <ncurses.h>
#include "Tetramino.hpp"
#include "Drawable.hpp"



class Hud: public Drawable{
    protected:
        int multiplier;
        int punteggio;
        int lines;

        WINDOW *shapeWin;
        Tetramino nexshape;
        WINDOW *hudwin;

    public:
        Hud(WINDOW *hudwin, int punteggio, const int multiplier);//costruttore dell'hud
        Hud();
        ~Hud();
        void computeScore();
        void setScore(int punteggio); 
        void setnextShape(Tetramino nexshape);
        void printNextShape();
        void nextPiece(Tetramino nexshape);
        void printHUD();
        void printHUD(WINDOW* hudwin, int punteggio);
        void destroyHUD();
        void setLines(int lines);
        int getLines();
        int getScore();
        Tetramino getNexshape();


};