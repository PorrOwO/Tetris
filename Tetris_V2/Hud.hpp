#pragma once
#include <ncurses.h>
#include "Tetramino.hpp"



class Hud:public Drawable{
    protected:
        int multiplier;
        int punteggio;
        int lines;
        //char nome;
        //WINDOW *shapeWin;
        Tetramino nexshape;
        WINDOW *hudwin;

    public:
        Hud(WINDOW *hudwin, int punteggio, const int multiplier);//costruttore dell'hud
        Hud();
        ~Hud();
        //void getwin();
        void computeScore();
        void setScore(int punteggio); 
        //void setName(char nome);
        void nextPiece();
        void printHUD();
        void printHUD(WINDOW* hudwin, int punteggio);
        void destroyHUD();
        void setLines(int lines);
        int getLines();


};