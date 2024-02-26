#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "Window.hpp"

class TetrisGame{
    private:
        Window win;
        bool gameOver;
    public:
        // costruttore che inizializza una finestra e setta gameOver a false, in questo modo l'utente può eseguire dei comandi
        TetrisGame(int height, int width){
            this->win = Window(height, width);
            this->win.init();
            this->win.addBorder();
            this->gameOver = false;
        };
        // metodo per processare i vari tipi di input
        void processInput(){
            // per adesso aspetta semplicemente che gli venga fornito un input
            chtype input = this->win.getInput();
        };
        void updateState(){
            // update
        };
        // metodo per aggiornare ciò che viene mostrato a schermo
        void updateDraw(){
            this->win.refresh();
        };
        // ritorna lo stato del gioco
        bool isOver(){
            return this->gameOver;
        }
};