#pragma once
#include <ncurses.h>
#include "Tetramino.hpp"



class hud{
    protected:
        int punteggio;
        char nome;
        WINDOW *win
        WINDOW *wpezzo;

    public:
        hud(WINDOW *win, WINDOW* wpezzo, int punteggio, char nome);
        hud();
        ~hud();
        void punteggioAttuale(int punteggio); 
        void name(char nome);
        void nextPiece(int shape[4][4]);
        void printHUD(WINDOW* win, WINDOW* wpezzo, int punteggio, char nome);

};