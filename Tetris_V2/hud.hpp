#pragma once
#include <ncurses.h>
#include "Tetramino.hpp"



class hud{
    protected:
        int multiplier;
        int punteggio;
        char nome;
        int nextshape[4][4];
        WINDOW *win;
        WINDOW *wpezzo;

    public:
        hud(WINDOW *win, WINDOW* wpezzo, int punteggio, char nome);//costruttore dell'hud
        hud();
        ~hud();
        void computeScore(int lines);
        void setScore(int punteggio); 
        void setName(char nome);
        void nextPiece(int shape[4][4]);
        void hud::printHUD();
        void printHUD(WINDOW* win, WINDOW* wpezzo, int punteggio, char nome);

};