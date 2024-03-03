#pragma once
#include <iostream>
#include <ncurses.h>
#include <string>
#include "DrawableInterface.hpp"

class Window{
    protected:
        WINDOW* win;
        int height, width;
    public:
        // costruttori
        Window();
        Window(int height, int width);

        // metodo per inizializzare una finestra
        void init();

        // metodo per creare un bordo alla finestra
        void addBox();
        
        // metodo per creare un bordo personalizzato
        void addCustomBorder(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);

        // metodo per aggiungere un oggetto disegnabile a schermo
        void addDrawableObj(DrawableInterface drawableObj);

        // metodo per aggiungere una stringa a schermo
        void addStringAt(int yPos, int xPos, std::string str);
        
        // metodo per aggiungere un solo carattere a schermo
        void addCharAt(int yPos, int xPos, chtype char1);
        
        // metodo per pulire il contenuto della finestra
        void clear();
        
        // metodo per aggiornare il contenuto della finestra
        void refresh();

        // metodi get
        chtype getInput();
        WINDOW* getWin();
        int getWinHeight();
        int getWinWidth();
};